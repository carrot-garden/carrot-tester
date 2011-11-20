package com.carrotgarden.hdf5.pt_bridj;

import static com.carrotgarden.bridj.Hdf5_hlLibrary.*;
import static ncsa.hdf.hdf5lib.H5.*;
import static ncsa.hdf.hdf5lib.HDF5Constants.*;
import static org.bridj.Pointer.*;

import java.nio.ByteBuffer;

import org.bridj.BridJ;
import org.bridj.NativeLibrary;

import com.carrotgarden.hdf5.JLP;

public class Main {

	// private static final int H5F_ACC_TRUNC = 0x0002;

	public static void log(String text) {
		System.out.println(text);
	}

	public static void main(String[] args) throws Exception {

		NativeLibrary lib1 = BridJ.getNativeLibrary("hdf5");
		log("lib=" + lib1);

		NativeLibrary lib2 = BridJ.getNativeLibrary("hdf5_hl");
		log("lib=" + lib2);

		JLP.pathAdd("/usr/lib/jni");
		JLP.pathLog();

		String name = "target/packet_table_FLexample.h5";

		int file_id = H5Fcreate(name, H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);

		log("file_id=" + file_id);

		int datatype_id = PacketStruct.createPacketType();
		long chunk_size = 500;
		int compression = -1;

		int table_id = H5PTcreate_fl(file_id, pointerToCString("test"),
				datatype_id, chunk_size, compression);

		log("table_id=" + table_id);

		log("H5PTis_valid=" + H5PTis_valid(table_id));

		ByteBuffer buffer = make(3);

		H5PTappend(table_id, 1, pointerToBuffer(buffer));

		H5PTclose(table_id);

		H5Fclose(file_id);

	}

	static ByteBuffer make(int count) {

		ByteBuffer buffer = ByteBuffer
				.allocateDirect(PacketStruct.SIZE * count);

		for (int k = 0; k < count; k++) {

			PacketStruct pkt = new PacketStruct();

			pkt.setByteBuffer(buffer, k * PacketStruct.SIZE);
			pkt.int32.set(k + 1);
			pkt.int8.set((byte) k);
			pkt.float64.set(1.5 + 3.0 * k);

		}

		return buffer;

	}

}
