package com.carrotgarden.hdf5.pt_jna;

import static com.carrotgarden.hdf5.pt_jna.HDF5.*;
import static com.carrotgarden.hdf5.pt_jna.HDF5HL.*;
import static ncsa.hdf.hdf5lib.HDF5Constants.*;

import java.nio.ByteBuffer;

import com.carrotgarden.hdf5.JLP;
import com.sun.jna.Memory;
import com.sun.jna.Pointer;

public class Main {

	public static void log(String text) {
		System.out.println(text);
	}

	public static void main(String[] args) throws Exception {

		JLP.pathAdd("/usr/lib/jni");
		// JLP.pathLog();

		int file_id = H5Fcreate("target/packet_table_FLexample.h5",
				H5F_ACC_TRUNC | H5F_ACC_DEBUG, H5P_DEFAULT, H5P_DEFAULT);

		log("file_id=" + file_id);

		int datatype_id = PacketStruct.createPacketType();
		long chunk_size = 500;
		int compression = -1;

		int table_id = H5PTcreate_fl(file_id, "test", datatype_id, chunk_size,
				compression);

		log("table_id=" + table_id);

		log("H5PTis_valid=" + H5PTis_valid(table_id));

		byte[] array = new byte[10];

		Pointer data = new Memory(array.length);

		data.write(0, array, 0, array.length);

		H5PTappend(table_id, 1, data);

		H5PTclose(table_id);

		H5Fclose(file_id);

	}

	public void testH5PTappend(int tbId) {

		PacketStruct pkt1 = new PacketStruct();
		PacketStruct pkt2 = new PacketStruct();
		PacketStruct pkt3 = new PacketStruct();

		ByteBuffer buffer = ByteBuffer.allocateDirect(pkt1.size() * 3);

		pkt1.setByteBuffer(buffer, 0);
		pkt1.int32.set(1);
		pkt1.int8.set((byte) 2);
		pkt1.float64.set(3.0);

		pkt2.setByteBuffer(buffer, pkt1.size());
		pkt2.int32.set(4);
		pkt2.int8.set((byte) 5);
		pkt2.float64.set(6.0);

		pkt3.setByteBuffer(buffer, pkt1.size());
		pkt3.int32.set(7);
		pkt3.int8.set((byte) 8);
		pkt3.float64.set(9.0);

		// int writeStatus = H5PTappend(tbId, 3, buffer);

		// long[] npackets = new long[1];
		// int getStatus = H5PTget_num_packets(tbId, npackets);

		// int closeStatus = H5PTclose(tbId);

	}

}
