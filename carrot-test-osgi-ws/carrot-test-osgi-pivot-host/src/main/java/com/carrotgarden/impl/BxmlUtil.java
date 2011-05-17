package com.carrotgarden.impl;

import java.net.URL;

import org.apache.pivot.beans.BXMLSerializer;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class BxmlUtil {

	private static Logger log = LoggerFactory.getLogger(BxmlUtil.class);

	public static Object loadBXML(final Class<?> reference,
			final String resource) {

		final Thread thread = Thread.currentThread();
		final ClassLoader tccl = thread.getContextClassLoader();

		Object result = null;

		try {

			ClassLoader loader = reference.getClassLoader();

			// must instantiate first
			BXMLSerializer bxml = new BXMLSerializer(loader);

			// then change context
			thread.setContextClassLoader(loader);

			URL url = reference.getResource(resource);

			result = bxml.readObject(url);

		} catch (Exception e) {
			log.error("", e);
		} finally {
			thread.setContextClassLoader(tccl);
		}

		return result;

	}

}
