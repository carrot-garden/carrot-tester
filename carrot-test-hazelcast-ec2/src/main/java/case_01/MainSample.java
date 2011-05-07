package case_01;

import java.util.Collection;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.hazelcast.core.Hazelcast;
import com.hazelcast.core.Instance;
import com.hazelcast.core.InstanceEvent;
import com.hazelcast.core.InstanceListener;

public class MainSample implements InstanceListener {

	private static final Logger log = LoggerFactory.getLogger(MainSample.class);

	public static final long SLEEP = 300 * 1000;
	public static final long STEP = 1 * 1000;

	public static void main(String[] args) throws Exception {

		MainSample sample = new MainSample();

		Hazelcast.addInstanceListener(sample);

		Collection<Instance> instances = Hazelcast.getInstances();

		for (Instance instance : instances) {
			log.info("instance: {} {}", instance.getInstanceType(),
					instance.getId());
		}

		log.info("SLEEP: {}", SLEEP);

		int sleep = 0;
		while (sleep < SLEEP) {
			Thread.sleep(STEP);
			log.info("sleep: {}", sleep);
			sleep += STEP;
		}

		log.info("SHUTDOWN");

		Hazelcast.shutdown();

	}

	public void instanceCreated(InstanceEvent event) {

		Instance instance = event.getInstance();

		log.info("INIT: {} {}", instance.getInstanceType(), instance.getId());

	}

	public void instanceDestroyed(InstanceEvent event) {

		Instance instance = event.getInstance();

		log.info("HALT: {} {}", instance.getInstanceType(), instance.getId());

	}

}
