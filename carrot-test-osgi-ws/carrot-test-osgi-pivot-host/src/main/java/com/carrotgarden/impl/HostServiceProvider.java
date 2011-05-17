package com.carrotgarden.impl;

import org.apache.felix.scr.annotations.Component;
import org.apache.felix.scr.annotations.Service;
import org.apache.pivot.collections.Map;
import org.apache.pivot.wtk.Display;
import org.osgi.framework.BundleContext;

import com.carrotgarden.api.host.HostService;
import com.carrotgarden.api.plugin.PluginShutdownService;

@Component
@Service
public class HostServiceProvider extends HostOsgiFramework implements
		HostService {

	protected Display display;

	protected Map<String, String> properties;

	//

	@Override
	public Display getHostDisplay() {
		return display;
	}

	@Override
	public Map<String, String> getHostProperties() {
		return properties;
	}

	@Override
	protected void registerHostServices(BundleContext context) {

		context.registerService(HostService.class.getName(), this, null);

	}

	protected boolean isShutdownConfirmed() {

		PluginShutdownService shutdownService = getFrameworkService(PluginShutdownService.class);

		if (shutdownService == null) {
			return true;
		}

		log.info("shutdownService: {}", shutdownService);

		return shutdownService.isShutdownConfirmed();

	}

	//

	@SuppressWarnings("unchecked")
	@Override
	public <T> T loadBXML(final Class<?> reference, final String resource) {

		return (T) BxmlUtil.loadBXML(reference, resource);

	}

}
