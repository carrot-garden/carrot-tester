package com.carrotgarden.hdf5.jna;

import static ncsa.hdf.hdf5lib.HDF5Constants.H5F_ACC_TRUNC;
import static ncsa.hdf.hdf5lib.HDF5Constants.H5P_DEFAULT;

import com.carrotgarden.hdf5.JLP;
import com.sun.jna.Pointer;

public class Main {

	public static void main(String[] args) throws Exception {

		JLP.pathAdd("/usr/lib/jni");

		int datatype_id = -1;

		int file_id = Hdf5Hl.H5Fcreate("target/packet_table_FLexample.h5",
				H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);

		int compression = 0;

		int ptable_id = Hdf5Hl.H5PTcreate_fl(file_id, "/trial1", datatype_id,
				500, compression);

		Pointer data = null;

		Hdf5Hl.H5PTappend(ptable_id, 1, data);

	}

}
