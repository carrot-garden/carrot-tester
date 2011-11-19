package com.carrotgarden.hdf5;

import java.io.File;
import java.lang.reflect.Field;

/**
 * http://blog.cedarsoft.com/
 * 
 * Setting "java.library.path" programmatically
 * 
 */

public class JLP {

	public static String PATH = "java.library.path";

	public static void log(String text) {
		System.out.println(text);
	}

	public static void pathLog() {

		String path = System.getProperty(PATH);

		String[] array = path.split(File.pathSeparator);

		for (String entry : array) {
			log("\t" + entry);
		}

	}

	public static void pathAdd(String lib) throws Exception {

		String path = lib + File.pathSeparator + System.getProperty(PATH);

		System.setProperty(PATH, path);

		Field fieldSysPaths = ClassLoader.class.getDeclaredField("sys_paths");

		fieldSysPaths.setAccessible(true);

		fieldSysPaths.set(null, null);

	}

	public static void main(String args[]) throws Exception {

		log("init");

		pathAdd("/usr/lib/jni");

		pathLog();

	}

}
