package bench.osgi;

import java.util.HashMap;
import java.util.Map;

import org.apache.felix.scr.annotations.Activate;
import org.apache.felix.scr.annotations.Component;
import org.apache.felix.scr.annotations.Deactivate;
import org.apache.felix.scr.annotations.Modified;
import org.apache.felix.scr.annotations.Reference;
import org.osgi.service.event.Event;
import org.osgi.service.event.EventAdmin;

@Component
public class Events1pub {

	@Reference
	private EventAdmin eventAdmin;

	protected void bind(EventAdmin eventAdmin) {
		this.eventAdmin = eventAdmin;
	}

	protected void unbind(EventAdmin eventAdmin) {
		this.eventAdmin = null;
	}

	@Activate
	protected void activate(Map<String, ?> config) {
	}

	@Modified
	protected void modified(Map<String, ?> config) {

		String topic = EventAPI.OPEN;
		Map<String, String> props = new HashMap<String, String>();

		Event event = new Event(topic, props);

		eventAdmin.sendEvent(event); // sync

		eventAdmin.postEvent(event); // async

	}

	@Deactivate
	protected void deactivate(Map<String, ?> config) {
	}

}
