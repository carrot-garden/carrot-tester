package com.carrotgarden.hdf5.pt_jna;

import com.sun.jna.Native;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;

/**
 */
public class HDF5 {

	static {
		Native.register("hdf5");
	}

	/**
	 * Creates an HDF5 file.
	 */
	public static native int H5Fcreate(final String name, final int flags,
			final int fcpl_id, final int fapl_id);

	public static native int H5Fclose(final int file_id);

	public static native int H5Tcreate(final int clazz, final int size);

	public static native int H5Tcopy(final int dtype_id);

	public static native int H5Tset_size(final int dtype_id, final int size);

	public static native int H5Tvlen_create(final int base_type_id);

	/**
	 * hid_t H5Tarray_create2( hid_t base_type_id, unsigned rank, const hsize_t
	 * dims[&lt;rank&gt;], )
	 */
	public static native int H5Tarray_create2(final int base_type_id,
			final int rank, final long... dims);

	/**
	 * H5_DLL herr_t H5Tset_tag(hid_t type, const char *tag)
	 */
	public static native int H5Tset_tag(final int type, final String tag);

	/**
	 * hid_t H5Screate_simple(int rank, const hsize_t * dims, const hsize_t *
	 * maxdims )
	 */
	public static native int H5Screate_simple(final int rank,
			final long[] dims, final long... maxdims);

	/**
	 * herr_t H5Sclose(hid_t space_id )
	 */
	public static native int H5Sclose(final int space_id);

	/**
	 * hid_t H5Dcreate2( hid_t loc_id, const char *name, hid_t dtype_id, hid_t
	 * space_id, hid_t lcpl_id, hid_t dcpl_id, hid_t dapl_id )
	 */
	public static native int H5Dcreate2(final int loc_id, final String name,
			final int type_id, final int space_id, final int lcpl_id,
			final int dcpl_id, final int dapl_id);

	/**
	 * herr_t H5Dwrite(hid_t dataset_id, hid_t mem_type_id, hid_t mem_space_id,
	 * hid_t file_space_id, hid_t xfer_plist_id, const void * buf )
	 */
	public static native int H5Dwrite(final int dataset_id,
			final int mem_type_id, final int mem_space_id,
			final int file_space_id, final int xfer_plist_id, final int... buf);

	/**
	 * See {@link #H5Dwrite(int, int, int, int, int, int...)}.
	 */
	public static native int H5Dwrite(final int dataset_id,
			final int mem_type_id, final int mem_space_id,
			final int file_space_id, final int xfer_plist_id, final Pointer buf);

	/**
	 * herr_t H5Dvlen_reclaim(hid_t type_id, hid_t space_id, hid_t plist_id,
	 * void *buf )
	 */
	public static native int H5Dvlen_reclaim(final int type_id,
			final int space_id, final int plist_id, Pointer buf);

	/**
	 * herr_t H5Dclose(hid_t dataset_id )
	 */
	public static native int H5Dclose(final int dataset_id);

	/**
	 * hid_t H5Pcreate(hid_t cls_id )
	 */
	public static native int H5Pcreate(final int cls_id);

	/**
	 * herr_t H5Pset_chunk(hid_t plist, int ndims, const hsize_t * dim )
	 */
	public static native int H5Pset_chunk(final int plist, final int ndims,
			final long... dim);

	/**
	 * typedef struct { size_t len; Length of VL data (in base type units) void
	 * *p; Pointer to VL data } hvl_t
	 */
	public static class hvl_t extends Structure {
		public int len;
		public Pointer p;

		public hvl_t() {
		}

		public hvl_t(final int len, final byte... blob) {
			this.len = len;
			// p = new Blob(blob);
		}

		public static class ByValue extends hvl_t implements Structure.ByValue {

			public ByValue() {
				super();
			}

			public ByValue(final int len, final byte... blob) {
				super(len, blob);
			}
		}
	}

}
