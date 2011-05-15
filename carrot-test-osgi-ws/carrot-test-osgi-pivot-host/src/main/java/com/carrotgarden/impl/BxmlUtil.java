package com.carrotgarden.impl;

import java.net.URL;

import org.apache.pivot.beans.BXMLSerializer;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class BxmlUtil {

	private static Logger log = LoggerFactory.getLogger(BxmlUtil.class);

	@SuppressWarnings("unchecked")
	public static <T> T loadBXML(final Class<?> reference, final String resource) {

		final Thread thread = Thread.currentThread();
		final ClassLoader tccl = thread.getContextClassLoader();

		T result = null;

		try {

			ClassLoader loader = reference.getClassLoader();

			// must instantiate first
			BXMLSerializer bxml = new BXMLSerializer(loader);

			// then change context
			thread.setContextClassLoader(loader);

			URL url = reference.getResource(resource);

			result = (T) bxml.readObject(url);

		} catch (Exception e) {
			log.error("", e);
		} finally {
			thread.setContextClassLoader(tccl);
		}

		return result;

	}

}
