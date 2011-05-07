package define;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

import org.openfast.Message;
import org.openfast.MessageBlockReader;
import org.openfast.ScalarValue;
import org.openfast.template.type.codec.TypeCodec;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * definition of cqg preamble
 * 
 * cqg_preamble : { cqg_length cme_preamble}
 * 
 * cqg_length : { fast_encode( u_int_32("length of everything after length") ) }
 * 
 * cme_preamble : { no_fast_encode (cme_sequence cme_channel) }
 * 
 * cme_sequence : { big_endian((u_int_32(sequence))}
 * 
 * cme_channel: { u_byte(channel) }
 * 
 * */

public class MessageBlockReaderCQG implements MessageBlockReader {

	static final Logger log = LoggerFactory
			.getLogger(MessageBlockReaderCQG.class);

	private final byte[] array = new byte[5];

	private final ByteBuffer buffer = ByteBuffer.wrap(array).order(
			ByteOrder.BIG_ENDIAN);

	// CQG prefix
	private int length;

	// CME prefix
	private int sequence;
	private int channel;

	private final static TypeCodec codec = TypeCodec.INTEGER;

	private InputStream input;
	private DataInputStream dataInput;

	@Override
	public void messageRead(InputStream input, Message message) {
	}

	/** read CQG preamble */
	@Override
	public boolean readBlock(final InputStream input) {
		if (this.input != input) {
			this.input = input;
			dataInput = new DataInputStream(input);
		}
		try {

			// CQG length : read fast-encoded integer
			ScalarValue value = codec.decode(dataInput);
			length = value.toInt();

			// CME preamble
			dataInput.readFully(array);
			buffer.clear();

			// CME message sequence
			sequence = buffer.getInt();
			// CME message source channel
			channel = buffer.get();

			return true;

		} catch (final IOException e) {

			log.error("", e);

			return false;

		}
	}

	public int getSequence() {
		return sequence;
	}

	public int getLength() {
		return length;
	}

	public int getChannel() {
		return channel;
	}

	@Override
	public String toString() {
		return " length=" + length + " sequence=" + sequence + " channel="
				+ channel;
	}

}
