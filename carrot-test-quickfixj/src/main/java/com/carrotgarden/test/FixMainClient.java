package com.carrotgarden.test;

import java.io.FileInputStream;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import quickfix.Application;
import quickfix.DefaultMessageFactory;
import quickfix.FileLogFactory;
import quickfix.FileStoreFactory;
import quickfix.Initiator;
import quickfix.LogFactory;
import quickfix.MessageFactory;
import quickfix.MessageStoreFactory;
import quickfix.SessionSettings;
import quickfix.SocketInitiator;

public class FixMainClient {

	static final Logger log = LoggerFactory.getLogger(FixMainClient.class);

	public static void main(String args[]) throws Exception {

		log.debug("init");

		final String fileName = "./target/classes/config-client.properties";

		final Application application = new FixApplication();

		final FileInputStream input = new FileInputStream(fileName);

		final SessionSettings settings = new SessionSettings(input);

		final MessageStoreFactory storeFactory = new FileStoreFactory(settings);

		final LogFactory logFactory = new FileLogFactory(settings);

		final MessageFactory messageFactory = new DefaultMessageFactory();

		final Initiator client = new SocketInitiator(application, storeFactory,
				settings, logFactory, messageFactory);

		client.start();

		// while( condition == true ) { do something; }
		Thread.sleep(1000 * 10);

		client.stop();

		log.debug("done");

	}

}
