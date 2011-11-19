package com.carrotgarden.hdf5.tutorial;

import com.carrotgarden.hdf5.JLP;

import ncsa.hdf.object.FileFormat;
import ncsa.hdf.object.Group;
import ncsa.hdf.object.h5.H5File;

/**
 * <p>
 * Title: HDF Object Package (Java) Example
 * </p>
 * <p>
 * Description: this example shows how to create HDF5 groups using the
 * "HDF Object Package (Java)". The example created the group structure:
 * 
 * <pre>
 *     "/" (root)
 *         g1
 *             g11
 *             g12
 *         g2
 *             g21
 *             g22
 * </pre>
 * 
 * </p>
 * 
 * @author Peter X. Cao
 * @version 2.4
 */
public class H5GroupCreate {

	private static String fname = "target/H5GroupCreate.h5";

	public static void main(String args[]) throws Exception {

		JLP.pathAdd("/usr/lib/jni");

		// retrieve an instance of H5File
		FileFormat fileFormat = FileFormat
				.getFileFormat(FileFormat.FILE_TYPE_HDF5);

		if (fileFormat == null) {
			System.err.println("Cannot find HDF5 FileFormat.");
			return;
		}

		// create a new file with a given file name.
		H5File testFile = (H5File) fileFormat.create(fname);

		if (testFile == null) {
			System.err.println("Failed to create file:" + fname);
			return;
		}

		// open the file and retrieve the root group
		testFile.open();
		Group root = (Group) ((javax.swing.tree.DefaultMutableTreeNode) testFile
				.getRootNode()).getUserObject();

		// create groups
		Group g1 = testFile.createGroup("g1", root);
		Group g11 = testFile.createGroup("g11", g1);
		Group g12 = testFile.createGroup("g12", g1);
		Group g2 = testFile.createGroup("g2", root);
		Group g21 = testFile.createGroup("g21", g2);
		Group g22 = testFile.createGroup("g22", g2);

		// close file resource
		testFile.close();

	}

}
