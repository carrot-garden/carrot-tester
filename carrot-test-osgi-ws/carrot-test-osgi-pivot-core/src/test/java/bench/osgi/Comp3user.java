package bench.osgi;

import java.util.Map;
import java.util.concurrent.Executor;

import org.apache.felix.scr.annotations.Activate;
import org.apache.felix.scr.annotations.Component;
import org.apache.felix.scr.annotations.Reference;

@Component
public class Comp3user {

	@Reference
	private Executor runner;

	protected void bind(Executor runner) {
		this.runner = runner;
	}

	protected void unbind(Executor runner) {
		this.runner = null;
	}

	@Activate
	protected void activate(Map<String, ?> config) {
		Runnable command = new Runnable() {
			@Override
			public void run() {
			}
		};
		runner.execute(command);
	}

}
