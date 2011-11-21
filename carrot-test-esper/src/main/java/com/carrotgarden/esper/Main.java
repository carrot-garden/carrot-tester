package com.carrotgarden.esper;

import com.espertech.esper.client.Configuration;
import com.espertech.esper.client.EPServiceProvider;
import com.espertech.esper.client.EPServiceProviderManager;
import com.espertech.esper.client.EPStatement;

public class Main {

	static void log(final String text) {
		System.out.println(text);
	}

	public static void main(final String[] args) {

		log("init");

		final Configuration config = new Configuration();

		config.addEventTypeAutoName(OrderEvent.class.getPackage().getName());

		final EPServiceProvider epService = EPServiceProviderManager
				.getDefaultProvider(config);

		final String expression = "select avg(price) "
				+ "from OrderEvent.win:time(30 sec)";

		final EPStatement statement = epService.getEPAdministrator().createEPL(
				expression);

		final MyListener listener = new MyListener();

		statement.addListener(listener);

		final OrderEvent event = new OrderEvent("shirt", 74.50);

		epService.getEPRuntime().sendEvent(event);

	}

}
