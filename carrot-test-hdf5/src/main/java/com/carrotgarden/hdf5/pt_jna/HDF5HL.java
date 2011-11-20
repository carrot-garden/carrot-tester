package com.carrotgarden.hdf5.pt_jna;

import com.sun.jna.Native;
import com.sun.jna.Pointer;

/**
 */
public class HDF5HL {

	static {
		Native.register("hdf5_hl");
	}

	/**
	 * hid_t H5PTcreate_fl( hid_t loc_id, const char * dset_name, hid_t
	 * dtype_id, hsize_t chunk_size, int compression )
	 * 
	 * H5PTcreate_fl creates and opens a packet table named dset_name attached
	 * to the object specified by the identifier loc_id. It should be closed
	 * with H5PTclose.
	 */
	public static native int H5PTcreate_fl(final int loc_id,
			final String dset_name, final int dtype_id, final long chunk_size,
			final int compression);

	/**
	 * herr_t H5PTappend( hid_t table_id, hsize_t nrecords, const void* data)
	 * 
	 * H5PTappend writes nrecords packets to the end of a packet table specified
	 * by table_id. data is a buffer containing the data to be written. For a
	 * packet table holding fixed-length packets, this data should be in the
	 * packet table's datatype. For a variable-length packet table, the data
	 * should be in the form of hvl_t structs.
	 */
	public static native int H5PTappend(final int table_id, final int nrecords,
			final Pointer data);

	/**
	 * hid_t H5PTopen( hid_t loc_id, const char *dset_name )
	 */
	public static native int H5PTopen(final int loc_id, final String dset_name);

	/**
	 * herr_t H5PTclose( hid_t table_id )
	 */
	public static native int H5PTclose(final int table_id);

	/**
	 * herr_t H5PTis_valid( hid_t table_id)
	 * 
	 * H5PTis_valid returns a non-negative value if table_id corresponds to an
	 * open packet table, and returns a negative value otherwise.
	 */
	public static native int H5PTis_valid(final int table_id);

}
