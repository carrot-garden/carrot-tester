/*
 * Copyright (C) 2010 Toni Menzel
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.carrotgarden.test;

import java.io.File;
import java.io.IOException;
import java.util.Properties;

import org.junit.Test;
import org.ops4j.pax.url.maven.commons.MavenConfiguration;
import org.ops4j.pax.url.maven.commons.MavenConfigurationImpl;
import org.ops4j.pax.url.maven.commons.MavenConstants;
import org.ops4j.pax.url.mvn.ServiceConstants;
import org.ops4j.pax.url.mvn.internal.AetherBasedResolver;
import org.ops4j.util.property.PropertiesPropertyResolver;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.sonatype.aether.collection.DependencyCollectionException;
import org.sonatype.aether.resolution.ArtifactResolutionException;

/**
 * Simply playing with mvn api.
 */
public class AetherTest1 {

	private static Logger LOG = LoggerFactory.getLogger(AetherTest1.class);

	@Test
	public void resolveArtifact() throws DependencyCollectionException,
			ArtifactResolutionException, IOException {

		final AetherBasedResolver aetherBasedResolver = new AetherBasedResolver(
				getMavenConfig());

		aetherBasedResolver.resolve("org.ops4j.pax.web", "pax-web-api", "",
				"jar", "0.7.2").close();

	}

	private MavenConfiguration getMavenConfig() throws IOException {

		final Properties p = new Properties();

		p.setProperty(ServiceConstants.PID
				+ MavenConstants.PROPERTY_LOCAL_REPOSITORY, getMavenRepo()
				.toURI().toASCIIString());

		final String repoKey = ServiceConstants.PID
				+ MavenConstants.PROPERTY_REPOSITORIES;

		final String repoValue = ""
				+ "http://localhost:8181/nexus/content/groups/public/@id=nexus,"
				// +
				// "http://scm.ops4j.org/repos/ops4j/projects/pax/runner-repository/@id=paxrunner,"
				// + "http://repo1.maven.org/maven2/@id=central,"
				//
				+ "";

		p.setProperty(repoKey, repoValue);

		return new MavenConfigurationImpl(new PropertiesPropertyResolver(p),
				ServiceConstants.PID);

	}

	private File getMavenRepo() throws IOException {

		final File base = new File("./target");

		base.mkdir();

		final File file = new File(base, "maven-repo");

		file.mkdirs();

		LOG.info("maven repo = " + file.getAbsolutePath());

		return file;

	}

}
