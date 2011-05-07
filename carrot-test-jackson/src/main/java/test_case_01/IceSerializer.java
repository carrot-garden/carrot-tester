package test_case_01;

import java.io.IOException;

import org.codehaus.jackson.JsonGenerationException;
import org.codehaus.jackson.JsonGenerator;
import org.codehaus.jackson.map.SerializerProvider;
import org.codehaus.jackson.map.ser.ScalarSerializerBase;

import test_case_01.api.Ice;

class IceSerializer extends ScalarSerializerBase<Ice> {

	protected IceSerializer(Class<Ice> klaz) {
		super(klaz);
	}

	@Override
	public void serialize(Ice value, JsonGenerator jgen,
			SerializerProvider provider) throws IOException,
			JsonGenerationException {
	}

}
