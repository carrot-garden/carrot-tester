package com.carrotgarden.api.host;

import org.apache.pivot.collections.Map;
import org.apache.pivot.wtk.Display;

public interface HostAppService {

	String PROP_REPO_LOCATION = "platform.repository";
	String PROP_REPO_ACTIVATE = "platform.activation";
	String PROP_BACKEND_HOST_URL = "platform.backend.hostUrl";
	String PROP_BACKEND_APP_ID = "platform.backend.appId";

	Display getDisplay();

	String getProperty(String name);

	Map<String, String> getProperties();

}
