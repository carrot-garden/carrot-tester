package com.carrotgarden.hdf5.tutorial;

import com.carrotgarden.hdf5.JLP;

import ncsa.hdf.object.Dataset;
import ncsa.hdf.object.Datatype;
import ncsa.hdf.object.FileFormat;
import ncsa.hdf.object.Group;
import ncsa.hdf.object.h5.H5File;

/**
 * <p>
 * Title: HDF Object Package (Java) Example
 * </p>
 * <p>
 * Description: this example shows how to create HDF5 datasets using the
 * "HDF Object Package (Java)". The example created the group structure and
 * datasets:
 * 
 * <pre>
 *     "/" (root)
 *         integer arrays
 *             2D 32-bit integer 20x10
 *             3D 16-bit integer 20x10x5
 *         float arrays
 *             2D 64-bit double 20x10
 *             3D 32-bit float  20x10x5
 * </pre>
 * 
 * </p>
 * 
 * @author Peter X. Cao
 * @version 2.4
 */
public class H5DatasetCreate {

	private static String fname = "target/H5DatasetCreate.h5";
	private static long[] dims2D = { 20, 10 };
	private static long[] dims3D = { 20, 10, 5 };

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

		// create groups at the root
		Group g1 = testFile.createGroup("integer arrays", root);
		Group g2 = testFile.createGroup("float arrays", root);

		// create 2D 32-bit (4 bytes) integer dataset of 20 by 10
		Datatype dtype = testFile.createDatatype(Datatype.CLASS_INTEGER, 4,
				Datatype.NATIVE, Datatype.NATIVE);
		Dataset dataset = testFile.createScalarDS("2D 32-bit integer 20x10",
				g1, dtype, dims2D, null, null, 0, null);

		// create 3D 8-bit (1 byte) unsigned integer dataset of 20 by 10 by 5
		dtype = testFile.createDatatype(Datatype.CLASS_INTEGER, 1,
				Datatype.NATIVE, Datatype.SIGN_NONE);
		dataset = testFile.createScalarDS("3D 8-bit unsigned integer 20x10x5",
				g1, dtype, dims3D, null, null, 0, null);

		// create 2D 64-bit (8 bytes) double dataset of 20 by 10
		dtype = testFile.createDatatype(Datatype.CLASS_FLOAT, 8,
				Datatype.NATIVE, -1);
		dataset = testFile.createScalarDS("2D 64-bit double 20x10", g2, dtype,
				dims2D, null, null, 0, null);

		// create 3D 32-bit (4 bytes) float dataset of 20 by 10 by 5
		dtype = testFile.createDatatype(Datatype.CLASS_FLOAT, 4,
				Datatype.NATIVE, -1);
		dataset = testFile.createScalarDS("3D 32-bit float  20x10x5", g2,
				dtype, dims3D, null, null, 0, null);

		// close file resource
		testFile.close();
	}

}
