package com.carrotgarden.hdf5.jna;

import com.sun.jna.Native;
import com.sun.jna.Pointer;

/**
 * @author <a href="mailto:Johannes.Stamminger@Astrium.EADS.net">Johannes
 *         Stamminger</a>
 * @version : #5 $
 */
public class Hdf5Hl extends Hdf5 {

	static {
		Native.register("hdf5_hl");
	}

	/**
	 * hid_t H5PTcreate_fl( hid_t loc_id, const char * dset_name, hid_t
	 * dtype_id, hsize_t chunk_size, int compression )
	 */
	public static native int H5PTcreate_fl(final int loc_id,
			final String dset_name, final int dtype_id, final long chunk_size,
			final int compression);

	/**
	 * herr_t H5PTappend( hid_t table_id, hsize_t nrecords, const void* data)
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

}
