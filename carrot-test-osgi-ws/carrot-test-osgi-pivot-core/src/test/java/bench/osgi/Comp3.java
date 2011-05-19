package bench.osgi;

import java.util.concurrent.Executor;

import org.apache.felix.scr.annotations.Component;
import org.apache.felix.scr.annotations.Service;

@Component
@Service
public class Comp3 implements Executor {

	@Override
	public void execute(Runnable command) {

	}

}
