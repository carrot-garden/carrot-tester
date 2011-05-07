package case_01;

import static org.junit.Assert.*;

import java.util.Collection;

import org.junit.Test;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.hazelcast.core.Hazelcast;
import com.hazelcast.core.Instance;

public class TestMainSample {

	private static final Logger log = LoggerFactory
			.getLogger(TestMainSample.class);

	public static final long SLEEP = 30 * 1000;
	public static final long STEP = 1 * 1000;

	@Test
	public void testMain() throws Exception {

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

		assertTrue(true);

	}

}
