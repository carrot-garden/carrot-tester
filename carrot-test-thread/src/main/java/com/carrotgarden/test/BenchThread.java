package com.carrotgarden.test;

import java.util.LinkedList;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class BenchThread {

	private static final Logger log = LoggerFactory
			.getLogger(BenchThread.class);

	private static final List<Thread> list = new LinkedList<Thread>();

	public static void main(final String[] args) throws Exception {

		log.debug("init");

		final int count = 500;

		for (int k = 0; k < count; k++) {

			final String name = String.format("# tester %03d", k);

			final Thread thread = new Thread(name) {

				@Override
				public void run() {
					while (true) {
						try {
							Thread.sleep(10 * 1000);
						} catch (final InterruptedException e) {
							//
						}
					}
				}

			};

			thread.start();

			list.add(thread);

		}

		System.gc();

		log.debug("ready");

		Thread.sleep(1000 * 1000);

		log.debug("done");

	}

}
