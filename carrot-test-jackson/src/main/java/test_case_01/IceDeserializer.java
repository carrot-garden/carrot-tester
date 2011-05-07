package test_case_01;

import java.io.IOException;

import org.codehaus.jackson.JsonParser;
import org.codehaus.jackson.JsonProcessingException;
import org.codehaus.jackson.map.DeserializationContext;
import org.codehaus.jackson.map.deser.StdDeserializer;

import test_case_01.api.Ice;

class IceDeserializer extends StdDeserializer<Ice> {

	protected IceDeserializer(Class<Ice> klaz) {
		super(klaz);
	}

	@Override
	public Ice deserialize(JsonParser jp, DeserializationContext ctxt)
			throws IOException, JsonProcessingException {
		return null;
	}

}
