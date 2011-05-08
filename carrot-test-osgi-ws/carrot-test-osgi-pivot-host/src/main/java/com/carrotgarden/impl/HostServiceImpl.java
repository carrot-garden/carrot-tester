package com.carrotgarden.impl;

import org.apache.felix.scr.annotations.Component;
import org.apache.felix.scr.annotations.Service;

import com.carrotgarden.api.HostService;

@Component
@Service
public class HostServiceImpl implements HostService {

	@Override
	public String lookup() {
		System.out.println("lookup");
		return "lookup";
	}

}
