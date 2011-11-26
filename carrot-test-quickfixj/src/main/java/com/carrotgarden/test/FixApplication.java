package com.carrotgarden.test;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import quickfix.Application;
import quickfix.DoNotSend;
import quickfix.FieldNotFound;
import quickfix.IncorrectDataFormat;
import quickfix.IncorrectTagValue;
import quickfix.Message;
import quickfix.RejectLogon;
import quickfix.SessionID;
import quickfix.UnsupportedMessageType;

public class FixApplication implements Application {

	static final Logger log = LoggerFactory.getLogger(FixMainServer.class);

	@Override
	public void onCreate(SessionID sessionId) {

		log.debug("sessionId=" + sessionId);

	}

	@Override
	public void onLogon(SessionID sessionId) {

		log.debug("sessionId=" + sessionId);

	}

	@Override
	public void onLogout(SessionID sessionId) {

		log.debug("sessionId=" + sessionId);

	}

	@Override
	public void toAdmin(Message message, SessionID sessionId) {

		log.debug("message=" + message);
		log.debug("sessionId=" + sessionId);

	}

	@Override
	public void fromAdmin(Message message, SessionID sessionId)
			throws FieldNotFound, IncorrectDataFormat, IncorrectTagValue,
			RejectLogon {

		log.debug("message=" + message);
		log.debug("sessionId=" + sessionId);

	}

	@Override
	public void toApp(Message message, SessionID sessionId) throws DoNotSend {

		log.debug("message=" + message);
		log.debug("sessionId=" + sessionId);

	}

	@Override
	public void fromApp(Message message, SessionID sessionId)
			throws FieldNotFound, IncorrectDataFormat, IncorrectTagValue,
			UnsupportedMessageType {

		log.debug("message=" + message);
		log.debug("sessionId=" + sessionId);

	}

}
