package test_case_01;

import org.codehaus.jackson.Version;
import org.codehaus.jackson.map.module.SimpleModule;

import test_case_01.api.Ice;
import test_case_01.provider.Builder;

public class Main {

	static void log(String text) {
		System.out.println(text);
	}

	public static void main(String... args) throws Exception {

		log("started");

		//

		Container container = new Container();
		container.value = Builder.build();

		//

		Class<Ice> klaz = Ice.class;

		Version version = new Version(1, 0, 0, null);
		SimpleModule module = new SimpleModule("ice", version);
		module.addDeserializer(klaz, new IceDeserializer(klaz));
		module.addSerializer(new IceSerializer(klaz));

		J.registerModule(module);

		//

		String json = J.intoText(container);

		log("json=" + json);

		//

		log("finished");

	}

}
