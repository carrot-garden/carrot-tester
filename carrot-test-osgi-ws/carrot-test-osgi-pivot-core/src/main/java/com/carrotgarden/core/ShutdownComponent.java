package com.carrotgarden.core;

import java.awt.EventQueue;
import java.net.URL;
import java.util.List;
import java.util.Map;

import org.apache.felix.scr.annotations.Activate;
import org.apache.felix.scr.annotations.Component;
import org.apache.felix.scr.annotations.Deactivate;
import org.apache.felix.scr.annotations.Modified;
import org.apache.felix.scr.annotations.Reference;
import org.apache.felix.scr.annotations.Service;
import org.apache.pivot.beans.BXMLSerializer;
import org.apache.pivot.wtk.Display;
import org.apache.pivot.wtk.Window;
import org.osgi.service.cm.ConfigurationAdmin;
import org.osgi.service.event.EventAdmin;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.carrotgarden.api.host.HostService;
import com.carrotgarden.api.plugin.PluginShutdownService;

@Component
@Service
public class ShutdownComponent implements PluginShutdownService {

	private static Logger log = LoggerFactory
			.getLogger(ShutdownComponent.class);

	static {
		//
		log.info("load"); //
		//
	}

	@Reference
	private HostService hostService;

	protected void bind(HostService hostService) {
		this.hostService = hostService;
	}

	protected void unbind(HostService hostService) {
		this.hostService = null;
	}

	@Reference
	private EventAdmin eventAdmin;

	protected void bind(EventAdmin eventAdmin) {
		this.eventAdmin = eventAdmin;
	}

	protected void unbind(EventAdmin eventAdmin) {
		this.eventAdmin = null;
	}

	@Reference
	private ConfigurationAdmin configAdmin;

	protected void bind(ConfigurationAdmin configAdmin) {
		this.configAdmin = configAdmin;
	}

	protected void unbind(ConfigurationAdmin configAdmin) {
		this.configAdmin = null;
	}

	//

	private volatile Window window;

	@Activate
	protected void activate(Map<String, String> config) {

		try {

			log.info("ACTIVATE");

			final Display display = hostService.getHostDisplay();

			final URL url = getClass().getResource("LoginComponent.bxml");

			final BXMLSerializer bxml = new BXMLSerializer();

			EventQueue.invokeLater(new Runnable() {
				@Override
				public void run() {
					try {
						// window = (Window) bxml.readObject(url);
						// window.open(display);
					} catch (Exception e) {
						log.error("", e);
					}
				}
			});

			log.info("DONE");

		} catch (Exception e) {
			log.error("", e);
		}

	}

	@Deactivate
	protected void deactivate(Map<String, String> config) {

		log.info("DEACTIVATE");

		EventQueue.invokeLater(new Runnable() {
			@Override
			public void run() {
				try {
					// window.close();
				} catch (Exception e) {
					log.error("", e);
				}
			}
		});

		log.info("DONE");

	}

	@Modified
	protected void modified(Map<String, String> config) {
		log.info("MODIFIED: {}", config);
	}

	// #########################

	@Override
	public boolean isShutdownConfirmed() {
		log.info("###: {}");
		return true; // xxx
	}

	@Override
	public List<Vote> getVoteList() {
		log.info("###: {}");
		return null;
	}

	@Override
	public void register(Vote vote) {
		log.info("###: {}");
	}

	@Override
	public void unregister(Vote vote) {
		log.info("###: {}");
	}

}
