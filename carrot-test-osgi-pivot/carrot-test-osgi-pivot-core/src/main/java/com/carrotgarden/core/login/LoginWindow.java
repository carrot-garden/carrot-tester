package com.carrotgarden.core.login;

import java.net.URL;

import org.apache.pivot.beans.Bindable;
import org.apache.pivot.collections.Map;
import org.apache.pivot.util.Resources;
import org.apache.pivot.wtk.Button;
import org.apache.pivot.wtk.ButtonStateListener;
import org.apache.pivot.wtk.Checkbox;
import org.apache.pivot.wtk.FlowPane;
import org.apache.pivot.wtk.HorizontalAlignment;
import org.apache.pivot.wtk.RadioButton;
import org.apache.pivot.wtk.Window;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class LoginWindow extends Window implements Bindable {

	protected static final Logger log = LoggerFactory
			.getLogger(LoginWindow.class);

	@Override
	public void initialize(Map<String, Object> namespace, URL location,
			Resources resources) {

		log.info("init");

		flowPane = (FlowPane) namespace.get("flowPane");
		leftRadioButton = (RadioButton) namespace.get("leftRadioButton");
		rightRadioButton = (RadioButton) namespace.get("rightRadioButton");
		centerRadioButton = (RadioButton) namespace.get("centerRadioButton");
		alignToBaselineCheckbox = (Checkbox) namespace
				.get("alignToBaselineCheckbox");

		ButtonStateListener buttonStateListener = new ButtonStateListener() {
			@Override
			public void stateChanged(Button button, Button.State previousState) {
				updateFlowPaneState();
			}
		};

		leftRadioButton.getButtonStateListeners().add(buttonStateListener);
		rightRadioButton.getButtonStateListeners().add(buttonStateListener);
		centerRadioButton.getButtonStateListeners().add(buttonStateListener);
		alignToBaselineCheckbox.getButtonStateListeners().add(
				buttonStateListener);

		updateFlowPaneState();

	}

	private void updateFlowPaneState() {
		HorizontalAlignment alignment = null;

		if (leftRadioButton.isSelected()) {
			alignment = HorizontalAlignment.LEFT;
		} else if (rightRadioButton.isSelected()) {
			alignment = HorizontalAlignment.RIGHT;
		} else if (centerRadioButton.isSelected()) {
			alignment = HorizontalAlignment.CENTER;
		}

		if (alignment != null) {
			flowPane.getStyles().put("alignment", alignment);
		}

		flowPane.getStyles().put("alignToBaseline",
				alignToBaselineCheckbox.isSelected());
	}

	private FlowPane flowPane;
	private RadioButton leftRadioButton;
	private RadioButton rightRadioButton;
	private RadioButton centerRadioButton;
	private Checkbox alignToBaselineCheckbox;

	// ####################

}
