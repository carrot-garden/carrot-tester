package com.carrotgarden.esper;

public class OrderEvent {

	private final String itemName;
	private final double price;

	public OrderEvent(final String itemName, final double price) {
		this.itemName = itemName;
		this.price = price;
	}

	public String getItemName() {
		return itemName;
	}

	public double getPrice() {
		return price;
	}

}
