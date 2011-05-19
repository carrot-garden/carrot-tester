package bench.osgi;

import org.apache.felix.scr.annotations.Component;
import org.apache.felix.scr.annotations.Property;
import org.apache.felix.scr.annotations.Service;
import org.osgi.service.event.Event;
import org.osgi.service.event.EventConstants;
import org.osgi.service.event.EventHandler;

@Component
@Service
@Property(//
name = EventConstants.EVENT_TOPIC, value = { EventAPI.OPEN, EventAPI.LOST } //
)
public class Events2sub implements EventHandler {

	@Override
	public void handleEvent(Event event) {

		String topic = event.getTopic();

		if (topic.equals(EventAPI.OPEN)) {
		}

		if (topic.equals(EventAPI.LOST)) {
		}

	}

}
