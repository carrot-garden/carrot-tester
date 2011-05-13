package com.carrotgarden.impl;

import org.apache.felix.scr.annotations.Component;
import org.apache.felix.scr.annotations.Service;
import org.apache.pivot.collections.Map;
import org.apache.pivot.wtk.Display;
import org.osgi.framework.BundleContext;

import com.carrotgarden.api.host.HostService;

@Component
@Service
public class HostServiceImpl extends HostFramework implements HostService {

	protected Display display;

	protected Map<String, String> properties;

	//

	@Override
	public Display getHostDisplay() {
		return display;
	}

	@Override
	public Map<String, String> getHostProperties() {
		return null;
	}

	@Override
	protected void registerHostServices(BundleContext context) {

		context.registerService(HostService.class.getName(), this, null);

	}

}
