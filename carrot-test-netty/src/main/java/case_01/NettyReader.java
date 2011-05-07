package case_01;

import java.net.InetSocketAddress;
import java.net.NetworkInterface;
import java.util.concurrent.Executors;

import org.jboss.netty.bootstrap.ConnectionlessBootstrap;
import org.jboss.netty.channel.ChannelPipeline;
import org.jboss.netty.channel.socket.DatagramChannel;
import org.jboss.netty.channel.socket.DatagramChannelFactory;
import org.jboss.netty.channel.socket.oio.OioDatagramChannelFactory;
import org.jboss.netty.handler.logging.LoggingHandler;
import org.jboss.netty.logging.InternalLoggerFactory;
import org.jboss.netty.logging.Slf4JLoggerFactory;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class NettyReader {

	static {
		System.setProperty("java.net.preferIPv4Stack", "true");
	}

	private static final Logger log = LoggerFactory
			.getLogger(NettyReader.class);

	static {
		// use slf4j for internal netty LoggingHandler
		InternalLoggerFactory defaultFactory = new Slf4JLoggerFactory();
		InternalLoggerFactory.setDefaultFactory(defaultFactory);
	}

	public static void main(String... args) throws Exception {

		log.info("init");

		//

		InetSocketAddress bindPoint = //
		// XXX MUST USE GROUP PORT on WINDOWS
		new InetSocketAddress(A.mainAddr, A.groupPort);
		log.debug("bindPoint: {}", bindPoint);

		InetSocketAddress groupPoint = //
		new InetSocketAddress(A.groupAddr, A.groupPort);
		log.debug("groupPoint: {}", groupPoint);

		//

		DatagramChannelFactory factory = //
		new OioDatagramChannelFactory(Executors.newCachedThreadPool());

		ConnectionlessBootstrap boot = //
		new ConnectionlessBootstrap(factory);

		ChannelPipeline channelPipeline = boot.getPipeline();

		channelPipeline.addLast("handler", new LoggingHandler());

		final DatagramChannel channel;

		switch (OS.detect()) {
		case LINUX:
			channel = (DatagramChannel) boot.bind(groupPoint);
			break;
		case WINDOWS:
			channel = (DatagramChannel) boot.bind(bindPoint);
			break;
		default:
			throw new RuntimeException("please define new os");
		}

		NetworkInterface bindInterface = //
		NetworkInterface.getByInetAddress(bindPoint.getAddress());

		channel.joinGroup(groupPoint, bindInterface);

		log.info("ready");

	}

}
