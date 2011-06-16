package bench.classloader;

public class CLPluginTCCL implements CLPlugin {

	@Override
	public ClassLoader getClassLoader() {
		return Thread.currentThread().getContextClassLoader();
	}

}
