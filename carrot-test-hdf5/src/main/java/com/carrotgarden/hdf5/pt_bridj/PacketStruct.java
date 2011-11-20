package com.carrotgarden.hdf5.pt_bridj;

import static ncsa.hdf.hdf5lib.H5.*;
import static ncsa.hdf.hdf5lib.HDF5Constants.*;

import java.nio.ByteBuffer;

import javolution.io.Struct;

public class PacketStruct extends Struct {

	public static final int SIZE = new PacketStruct().size();

	public Signed32 int32 = new Signed32();
	public Signed8 int8 = new Signed8();
	public Float64 float64 = new Float64();

	@Override
	public boolean equals(Object obj) {

		if (!(obj instanceof PacketStruct)) {
			return false;
		}

		if (this == obj) {
			return true;
		}

		PacketStruct other = (PacketStruct) obj;

		return ((this.int32.get() == other.int32.get())
				&& (this.int8.get() == other.int8.get()) && (this.float64.get()
				- other.float64.get() < 1e-10));

	}

	public static int createPacketType() throws Exception {

		final PacketStruct struct = new PacketStruct();

		struct.setByteBuffer(ByteBuffer.allocateDirect(struct.size()), 0);

		int idStruct = H5Tcreate(H5T_COMPOUND, struct.size());

		final String intName = "int32";

		int insertStatus = -1;

		insertStatus = H5Tinsert(idStruct, intName, struct.int32.offset(),
				H5T_STD_I32BE);

		final String charName = "int8";

		insertStatus = H5Tinsert(idStruct, charName, struct.int8.offset(),
				H5T_STD_I8BE);

		final String floatName = "float64";

		insertStatus = H5Tinsert(idStruct, floatName, struct.float64.offset(),
				H5T_IEEE_F64BE);

		return idStruct;

	}

}
