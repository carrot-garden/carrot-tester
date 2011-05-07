package define;

import java.io.InputStream;

import org.openfast.Message;
import org.openfast.MessageInputStream;
import org.openfast.template.TemplateRegistry;
import org.openfast.template.loader.XMLMessageTemplateLoader;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import quickfix.field.MsgSeqNum;
import quickfix.field.Password;
import quickfix.field.SendingTime;
import quickfix.field.Username;
import quickfix.fix50.SecurityDefinitionRequest;
import quickfix.fixt11.Logon;

public class MainDefinitionReader {

	static final Logger log = LoggerFactory
			.getLogger(MainDefinitionReader.class);

	// must start with 1
	static int sendSequence = 1;

	public static void main(String[] args) throws Exception {

		log.info("started");

		// register cqg templates; may need to get updated files from ftp
		final InputStream templateSource = resource("/define/templates.xml");
		final XMLMessageTemplateLoader templateLoader = new XMLMessageTemplateLoader();
		templateLoader.setLoadTemplateIdFromAuxId(true);
		templateLoader.load(templateSource);
		final TemplateRegistry registry = templateLoader.getTemplateRegistry();

		// connect to cqg definition server
		DefinitionStreamer streamer = new DefinitionStreamer();
		streamer.connect();
		log.info("connected");

		// setup cqg preamble decoder
		final MessageBlockReaderCQG blockReader = new MessageBlockReaderCQG();
		// setup cqg message stream decoder
		final MessageInputStream fastInput = new MessageInputStream(
				streamer.input);
		fastInput.setBlockReader(blockReader);
		fastInput.setTemplateRegistry(registry);
		fastInput.getContext().setTraceEnabled(true);

		// send cqg plain fix logon message
		String msgLogon = makeLogonRequest();
		streamer.write(msgLogon);

		// keep reading security definition messages (preable + fast)
		while (true) {

			/*
			 * cqg fast dictionary is per single message only - need reset per
			 * message
			 */
			fastInput.reset();

			/* read fast messages */
			Message msgFAST = fastInput.readMessage();
			if (msgFAST == null) {
				/* end of stream */
				break;
			}

			/* show cqg preample */
			log.info("blockReader : {}", blockReader);

			/* show cqg message */
			log.info("msgRead : {}", msgFAST);

			/*
			 * send cqg definition request only after 1 logon and 2 heartbeat
			 * responses
			 */
			int seqn = blockReader.getSequence();
			if (seqn == 3) {
				String msgSend = makeDefinitionRequest();
				streamer.write(msgSend);
			}

		}

		log.info("finished");

	}

	static String makeLogonRequest() {

		Logon msg = new Logon();

		// see /doc/pdf
		msg.set(new Username("test"));
		msg.set(new Password("test"));

		msg.setField(new MsgSeqNum(sendSequence++)); // must start with 1
		msg.setField(new SendingTime());

		return msg.toString();

	}

	static String makeDefinitionRequest() {

		SecurityDefinitionRequest msg = new SecurityDefinitionRequest();

		// ApplID means cqg multicast channel id
		// http://www.fixprotocol.org/FIXimate3.0/en/FIX.5.0SP2/tag1180.html
		msg.setString(1180, "13");

		msg.setField(new MsgSeqNum(sendSequence++));
		msg.setField(new SendingTime());

		return msg.toString();

	}

	static InputStream resource(String url) {
		return MainDefinitionReader.class.getResourceAsStream(url);
	}

}
