package com.carrotgarden.api.host;

import org.apache.pivot.collections.Map;
import org.apache.pivot.wtk.Display;

public interface HostService {

	Display getHostDisplay();

	Map<String, String> getHostProperties();

}
