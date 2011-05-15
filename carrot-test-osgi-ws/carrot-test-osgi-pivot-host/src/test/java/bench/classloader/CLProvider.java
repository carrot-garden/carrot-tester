package bench.classloader;

public class CLProvider {

	public static final RuntimePermission PIVOT_GET_PLUGIN_PERMISSION = //
	new RuntimePermission("org.apache.pivot.plugin.classloader.get");

	public static final RuntimePermission PIVOT_SET_PLUGIN_PERMISSION = //
	new RuntimePermission("org.apache.pivot.plugin.classloader.set");

	//

	private static volatile CLPlugin plugin;

	public static CLPlugin getPlugin() {
		SecurityManager sm = System.getSecurityManager();
		if (sm != null) {
			sm.checkPermission(PIVOT_GET_PLUGIN_PERMISSION);
		}
		return plugin;
	}

	public static void setPlugin(CLPlugin clPlugin) {
		SecurityManager sm = System.getSecurityManager();
		if (sm != null) {
			sm.checkPermission(PIVOT_SET_PLUGIN_PERMISSION);
		}
		plugin = clPlugin;
	}

	//

	static {
		setPlugin(new CLPluginTCCL());
	}

	//

	public static ClassLoader getClassLoader() {
		return plugin.getClassLoader();
	}

}
