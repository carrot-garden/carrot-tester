package com.carrotgarden.test;

import java.io.File;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.amazonaws.auth.AWSCredentials;
import com.amazonaws.auth.PropertiesCredentials;
import com.amazonaws.services.ec2.AmazonEC2;
import com.amazonaws.services.ec2.AmazonEC2Client;
import com.amazonaws.services.ec2.model.DescribeInstancesResult;
import com.amazonaws.services.ec2.model.Instance;
import com.amazonaws.services.ec2.model.InstanceState;
import com.amazonaws.services.ec2.model.Reservation;
import com.amazonaws.services.ec2.model.Tag;

public class ListEC2 {

	static final Logger logger = LoggerFactory.getLogger(ListEC2.class);

	public static void main(String[] args) throws Exception {

		logger.debug("init");

		// final String text = FileUtils.readFileToString(file);

		//

		final String home = System.getProperty("user.home");

		final File file = new File(home,
				".amazon/carrotgarden/credentials/admin-ec2.properties");

		logger.debug("file" + file);

		final AWSCredentials props = new PropertiesCredentials(file);

		final AmazonEC2 client = new AmazonEC2Client(props);

		final DescribeInstancesResult result = client.describeInstances();

		final List<Reservation> reservations = result.getReservations();

		for (final Reservation entry : reservations) {

			logger.debug("entry : " + entry);

			final List<Instance> instances = entry.getInstances();

			for (final Instance item : instances) {

				logger.debug("item : " + item);

				final InstanceState state = item.getState();

				logger.debug("state : " + state);

				final List<Tag> tags = item.getTags();

				for (final Tag tag : tags) {

					logger.debug("tag : " + tag);

				}

			}

		}

		//

		logger.debug("done");

	}

}
