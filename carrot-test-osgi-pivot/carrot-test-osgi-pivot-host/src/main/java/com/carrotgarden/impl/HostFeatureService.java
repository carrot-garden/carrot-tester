package com.carrotgarden.impl;

public interface HostFeatureService {

	/* blocking call to install/update & start a plugin */
	void featureActivate(String repositoryURL, String featureName)
			throws Exception;

	/* blocking call to stop a plugin (does not uninstall) */
	void featureDeactivate(String repositoryURL, String featureName)
			throws Exception;

}
