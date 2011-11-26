package com.carrotgarden.test;

import java.io.File;
import java.io.FileReader;
import java.io.Reader;
import java.util.List;
import java.util.Properties;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.widen.valet.Route53Driver;
import com.widen.valet.Zone;
import com.widen.valet.ZoneResource;
import com.widen.valet.internal.Route53Pilot;
import com.widen.valet.internal.Route53PilotImpl;

public class ListDNS {

	static final Logger logger = LoggerFactory.getLogger(ListDNS.class);

	public static void main(String[] args) throws Exception {

		logger.debug("init");

		// final String text = FileUtils.readFileToString(file);

		//

		final String home = System.getProperty("user.home");

		final File file = new File(home,
				".amazon/carrotgarden/credentials/admin-dns.properties");

		logger.debug("file" + file);

		final Reader reader = new FileReader(file);

		final Properties props = new Properties();

		props.load(reader);

		//

		final String AWS_ACCESS_KEY = props.getProperty("accessKey");
		final String AWS_SECRET_KEY = props.getProperty("secretKey");

		final Route53Pilot pilot = new Route53PilotImpl(AWS_ACCESS_KEY,
				AWS_SECRET_KEY);

		final Route53Driver driver = new Route53Driver(pilot);

		final List<Zone> zoneList = driver.listZones();

		for (final Zone entry : zoneList) {
			logger.debug("zone : " + entry);
		}

		final Zone zone = driver.zoneDetailsForDomain("carrotgarden.com.");

		logger.debug("" + zone);

		for (final ZoneResource entry : driver.listZoneRecords(zone)) {
			logger.debug("entry : " + entry);
		}

		logger.debug("done");

	}

}
