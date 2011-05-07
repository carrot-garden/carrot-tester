package define;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.SocketAddress;
import java.nio.charset.Charset;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class DefinitionStreamer {

	static final Logger log = LoggerFactory.getLogger(DefinitionStreamer.class);

	// see /doc/pdf

	// Security Definition Server:
	// Channel ID: 13 (tag 1180-ApplID)
	// Host: 10.1.0.71
	// Port: 2222
	// Username: test
	// Password: test

	// must use ssh port forward; see /doc/vpn/forward.sh
	final static String HOST = "localhost";
	final static int PORT = 2222;

	Socket socket;

	InputStream input;
	OutputStream output;

	DataInputStream dataInput;
	DataOutputStream dataOutput;

	BufferedReader reader;
	BufferedWriter writer;

	synchronized void connect() throws Exception {

		disconnect();

		socket = new Socket();
		SocketAddress endPoint = new InetSocketAddress(HOST, PORT);

		socket.connect(endPoint, 1 * 1000);

		input = socket.getInputStream();
		output = socket.getOutputStream();

		dataInput = new DataInputStream(input);
		dataOutput = new DataOutputStream(output);

		reader = new BufferedReader(new InputStreamReader(input));
		writer = new BufferedWriter(new OutputStreamWriter(output));

	}

	void write(String text) throws Exception {
		byte[] array = text.getBytes(ASCII);
		output.write(array, 0, text.length());
		log.info("msgSend={}", text);
	}

	static Charset ASCII = Charset.forName("ASCII");

	synchronized void disconnect() throws Exception {

		if (socket == null) {
			return;
		}

		input.close();
		output.close();
		socket.close();

	}

}
