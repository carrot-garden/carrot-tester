package test_case_01.provider;

import test_case_01.api.Ice;

public class Builder {

	public static Ice build() {
		return new IceImpl2();
	}

}
