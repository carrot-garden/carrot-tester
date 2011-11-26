package com.carrotgarden.test;

import java.io.FileInputStream;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import quickfix.Acceptor;
import quickfix.Application;
import quickfix.DefaultMessageFactory;
import quickfix.FileLogFactory;
import quickfix.FileStoreFactory;
import quickfix.LogFactory;
import quickfix.MessageFactory;
import quickfix.MessageStoreFactory;
import quickfix.SessionSettings;
import quickfix.SocketAcceptor;

public class FixMainServer {

	static final Logger log = LoggerFactory.getLogger(FixMainServer.class);

	public static void main(String args[]) throws Exception {

		log.debug("init");

		final String fileName = "./target/classes/config-server.properties";

		final Application application = new FixApplication();

		final FileInputStream input = new FileInputStream(fileName);

		final SessionSettings settings = new SessionSettings(input);

		final MessageStoreFactory storeFactory = new FileStoreFactory(settings);

		final LogFactory logFactory = new FileLogFactory(settings);

		final MessageFactory messageFactory = new DefaultMessageFactory();

		final Acceptor server = new SocketAcceptor(application, storeFactory,
				settings, logFactory, messageFactory);

		server.start();

		// while( condition == true ) { do something; }
		Thread.sleep(1000 * 1000);

		server.stop();

		log.debug("done");

	}

}
