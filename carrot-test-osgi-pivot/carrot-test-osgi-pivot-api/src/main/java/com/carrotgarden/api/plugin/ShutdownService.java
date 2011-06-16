package com.carrotgarden.api.plugin;

import java.util.Date;
import java.util.List;

public interface ShutdownService {

	// interface EVENT {
	// String ALL = EventUtil.name("*");
	// String REQUESTED = EventUtil.name("REQUESTED");
	// String CONFIRMED = EventUtil.name("CONFIRMED");
	// }

	interface Vote extends Comparable<Vote> {

		String getName();

		String getDescription();

		Date getCompetionDeadline();

	}

	boolean requestShutdown();

	//

	List<Vote> getVoteList();

	void register(Vote vote);

	void unregister(Vote vote);

}
