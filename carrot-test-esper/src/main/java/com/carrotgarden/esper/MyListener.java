package com.carrotgarden.esper;

import com.espertech.esper.client.EventBean;
import com.espertech.esper.client.UpdateListener;

public class MyListener implements UpdateListener {

	public void update(final EventBean[] newEvents, final EventBean[] oldEvents) {

		final EventBean event = newEvents[0];

		System.out.println("avg=" + event.get("avg(price)"));

	}

}
