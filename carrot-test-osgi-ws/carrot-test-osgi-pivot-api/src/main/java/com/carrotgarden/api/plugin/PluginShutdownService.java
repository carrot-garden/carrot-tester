package com.carrotgarden.api.plugin;

import java.util.Date;
import java.util.List;

public interface PluginShutdownService {

	interface Vote extends Comparable<Vote> {

		String getName();

		String getDescription();

		Date getCompetionDeadline();

	}

	boolean isShutdownConfirmed();

	List<Vote> getVoteList();

	void register(Vote vote);

	void unregister(Vote vote);

	//

}
