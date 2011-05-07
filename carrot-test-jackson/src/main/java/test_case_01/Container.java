package test_case_01;

import org.codehaus.jackson.annotate.JsonProperty;

import test_case_01.api.Ice;

class Container {

	@JsonProperty("ice")
	Ice value;

}
