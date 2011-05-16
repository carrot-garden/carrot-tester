package com.carrotgarden.core;

import java.awt.Color;
import java.net.URL;

import org.apache.pivot.beans.Bindable;
import org.apache.pivot.collections.ArrayList;
import org.apache.pivot.collections.Map;
import org.apache.pivot.collections.Sequence;
import org.apache.pivot.util.Resources;
import org.apache.pivot.util.concurrent.TaskExecutionException;
import org.apache.pivot.wtk.Action;
import org.apache.pivot.wtk.Alert;
import org.apache.pivot.wtk.ApplicationContext;
import org.apache.pivot.wtk.BoxPane;
import org.apache.pivot.wtk.Button;
import org.apache.pivot.wtk.ButtonGroup;
import org.apache.pivot.wtk.ButtonPressListener;
import org.apache.pivot.wtk.ButtonStateListener;
import org.apache.pivot.wtk.Checkbox;
import org.apache.pivot.wtk.Component;
import org.apache.pivot.wtk.FlowPane;
import org.apache.pivot.wtk.HorizontalAlignment;
import org.apache.pivot.wtk.ImageView;
import org.apache.pivot.wtk.Label;
import org.apache.pivot.wtk.ListButton;
import org.apache.pivot.wtk.ListButtonSelectionListener;
import org.apache.pivot.wtk.ListView;
import org.apache.pivot.wtk.ListViewSelectionListener;
import org.apache.pivot.wtk.MessageType;
import org.apache.pivot.wtk.PushButton;
import org.apache.pivot.wtk.RadioButton;
import org.apache.pivot.wtk.Span;
import org.apache.pivot.wtk.SuggestionPopup;
import org.apache.pivot.wtk.TextInput;
import org.apache.pivot.wtk.TextInputContentListener;
import org.apache.pivot.wtk.Window;
import org.apache.pivot.wtk.content.ColorItem;
import org.apache.pivot.wtk.media.Image;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class WindowExtra2 extends Window implements Bindable {

	protected static final Logger log = LoggerFactory
			.getLogger(WindowExtra2.class);

	private PushButton pushButton;

	private PushButton selectButton;

	private ListView listView;
	private Label selectionLabel;

	private ListButton listButton;
	private ImageView imageView;

	private ListButton colorListButton;
	private BoxPane checkboxBoxPane;
	private int selectedCount;

	private ArrayList<String> states;

	private TextInput stateTextInput1;

	private TextInput stateTextInput2;
	private final SuggestionPopup suggestionPopup = new SuggestionPopup();

	@Override
	public void initialize(Map<String, Object> namespace, URL location,
			Resources resources) {

		// ###############

		pushButton = (PushButton) namespace.get("pushButton");

		ButtonPressListener listener = new ButtonPressListener() {
			@Override
			public void buttonPressed(Button button) {
				Alert.alert(MessageType.INFO, "You clicked me!",
						WindowExtra2.this);
			}
		};

		pushButton.getButtonPressListeners().add(listener);

		// ###############

		selectButton = (PushButton) namespace.get("selectButton");

		// Get a reference to the button group
		final ButtonGroup numbersGroup = (ButtonGroup) namespace.get("numbers");

		// Add a button press listener
		selectButton.getButtonPressListeners().add(new ButtonPressListener() {
			@Override
			public void buttonPressed(Button button) {
				String message = "You selected \""
						+ numbersGroup.getSelection().getButtonData() + "\".";
				Alert.alert(MessageType.INFO, message, WindowExtra2.this);
			}
		});

		// ###############

		selectionLabel = (Label) namespace.get("selectionLabel");
		listView = (ListView) namespace.get("listView");

		listView.getListViewSelectionListeners().add(
				new ListViewSelectionListener() {

					@Override
					public void selectedRangeAdded(ListView listView,
							int rangeStart, int rangeEnd) {
						updateSelection(listView);
					}

					@Override
					public void selectedRangeRemoved(ListView listView,
							int rangeStart, int rangeEnd) {
						updateSelection(listView);
					}

					@Override
					public void selectedRangesChanged(ListView listView,
							Sequence<Span> previousSelectedRanges) {
						if (previousSelectedRanges != null
								&& previousSelectedRanges != listView
										.getSelectedRanges()) {
							updateSelection(listView);
						}
					}

					@Override
					public void selectedItemChanged(ListView listView,
							Object previousSelectedItem) {
						// No-op
					}

					private void updateSelection(ListView listView) {

						String selectionText = "";

						Sequence<Span> selectedRanges = listView
								.getSelectedRanges();

						for (int i = 0, n = selectedRanges.getLength(); i < n; i++) {
							Span selectedRange = selectedRanges.get(i);

							for (int j = selectedRange.start; j <= selectedRange.end; j++) {
								if (selectionText.length() > 0) {
									selectionText += ", ";
								}

								String text = (String) listView.getListData()
										.get(j);
								selectionText += text;
							}
						}

						selectionLabel.setText(selectionText);
					}
				});

		// ###############

		listButton = (ListButton) namespace.get("listButton");
		imageView = (ImageView) namespace.get("imageView");

		listButton.getListButtonSelectionListeners().add(
				new ListButtonSelectionListener.Adapter() {

					@Override
					public void selectedItemChanged(ListButton listButton,
							Object previousSelectedItem) {

						Object selectedItem = listButton.getSelectedItem();

						if (selectedItem != null) {

							log.info("XXX selectedItem : {}", selectedItem);

							// Get the image URL for the selected item
							// ClassLoader classLoader = Thread.currentThread()
							// .getContextClassLoader();
							ClassLoader classLoader = getClass()
									.getClassLoader();

							log.info("XXX classLoader : {}", classLoader);

							// XXX
							URL imageURL = classLoader.getResource("/tutorial/"
									+ selectedItem);

							log.info("XXX imageURL : {}", imageURL);

							/*
							 * If the image has not been added to the resource
							 * cache yet, add it
							 */
							Image image = (Image) ApplicationContext
									.getResourceCache().get(imageURL);

							if (image == null) {
								try {
									image = Image.load(imageURL);
								} catch (TaskExecutionException exception) {
									throw new RuntimeException(exception);
								}

								ApplicationContext.getResourceCache().put(
										imageURL, image);
							}

							// Update the image
							imageView.setImage(image);
						}
					}
				});

		// ###############

		listButton.setSelectedIndex(0);
		colorListButton = (ListButton) namespace.get("colorListButton");
		checkboxBoxPane = (BoxPane) namespace.get("checkboxBoxPane");

		ButtonStateListener buttonStateListener = new ButtonStateListener() {
			@Override
			public void stateChanged(Button button, Button.State previousState) {
				if (button.isSelected()) {
					selectedCount++;
				} else {
					selectedCount--;
				}

				applyColorAction.setEnabled(selectedCount > 0);
			}
		};

		ArrayList<String> numbers = new ArrayList<String>("One", "Two",
				"Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten");

		for (String number : numbers) {
			Checkbox checkbox = new Checkbox(number);
			checkbox.getButtonStateListeners().add(buttonStateListener);
			checkboxBoxPane.add(checkbox);
		}

		// ############################3

		stateTextInput1 = (TextInput) namespace.get("stateTextInput1");
		stateTextInput1.getTextInputContentListeners().add(
				new TextInputContentListener.Adapter() {
					@Override
					public void textInserted(final TextInput textInput,
							int index, int count) {
						String text = textInput.getText();

						int i = ArrayList.binarySearch(states, text,
								states.getComparator());

						if (i < 0) {
							i = -(i + 1);
							int n = states.getLength();

							if (i < n) {
								text = text.toLowerCase();
								final String state = states.get(i);

								if (state.toLowerCase().startsWith(text)) {
									String nextState = (i == n - 1) ? null
											: states.get(i + 1);

									if (nextState == null
											|| !nextState.toLowerCase()
													.startsWith(text)) {
										textInput.setText(state);

										int selectionStart = text.length();
										int selectionLength = state.length()
												- selectionStart;
										textInput.setSelection(selectionStart,
												selectionLength);
									}
								}
							}
						}
					}
				});

		// #######################

		stateTextInput2 = (TextInput) namespace.get("stateTextInput2");

		stateTextInput2.getTextInputContentListeners().add(
				new TextInputContentListener.Adapter() {
					@Override
					public void textInserted(TextInput textInput, int index,
							int count) {
						String text = textInput.getText();
						ArrayList<String> suggestions = new ArrayList<String>();

						for (String state : states) {
							if (state.toUpperCase().startsWith(
									text.toUpperCase())) {
								suggestions.add(state);
							}
						}

						if (suggestions.getLength() > 0) {
							suggestionPopup.setSuggestionData(suggestions);
							suggestionPopup.open(textInput);
						}
					}

					@Override
					public void textRemoved(TextInput textInput, int index,
							int count) {
						suggestionPopup.close();
					}
				});

		suggestionPopup.setListSize(4);

		// ####################

		flowPane = (FlowPane) namespace.get("flowPane");
		leftRadioButton = (RadioButton) namespace.get("leftRadioButton");
		rightRadioButton = (RadioButton) namespace.get("rightRadioButton");
		centerRadioButton = (RadioButton) namespace.get("centerRadioButton");
		alignToBaselineCheckbox = (Checkbox) namespace
				.get("alignToBaselineCheckbox");

		ButtonStateListener buttonStateListener2 = new ButtonStateListener() {
			@Override
			public void stateChanged(Button button, Button.State previousState) {
				updateFlowPaneState();
			}
		};

		leftRadioButton.getButtonStateListeners().add(buttonStateListener);
		rightRadioButton.getButtonStateListeners().add(buttonStateListener);
		centerRadioButton.getButtonStateListeners().add(buttonStateListener);
		alignToBaselineCheckbox.getButtonStateListeners().add(
				buttonStateListener2);

		updateFlowPaneState();

		// ####################

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

	// ###############

	private final Action applyColorAction = new Action() {
		@Override
		public void perform(Component source) {
			ColorItem colorItem = (ColorItem) colorListButton.getButtonData();
			Color color = colorItem.getColor();

			for (Component component : checkboxBoxPane) {
				Checkbox checkbox = (Checkbox) component;
				if (checkbox.isSelected()) {
					checkbox.getStyles().put("color", color);
					checkbox.setSelected(false);
				}
			}
		}
	};

	public WindowExtra2() {

		Action.getNamedActions().put("applyColor", applyColorAction);

		applyColorAction.setEnabled(false);

		initStates();

	}

	// ##################

	private void initStates() {

		// Populate the lookup values, ensuring that they are sorted
		states = new ArrayList<String>();
		states.setComparator(String.CASE_INSENSITIVE_ORDER);

		states.add("Alabama");
		states.add("Alaska");
		states.add("Arizona");
		states.add("Arkansas");
		states.add("California");
		states.add("Colorado");
		states.add("Connecticut");
		states.add("Delaware");
		states.add("District of Columbia");
		states.add("Florida");
		states.add("Georgia");
		states.add("Hawaii");
		states.add("Idaho");
		states.add("Illinois");
		states.add("Indiana");
		states.add("Iowa");
		states.add("Kansas");
		states.add("Kentucky");
		states.add("Louisiana");
		states.add("Maine");
		states.add("Maryland");
		states.add("Massachusetts");
		states.add("Michigan");
		states.add("Minnesota");
		states.add("Mississippi");
		states.add("Missouri");
		states.add("Montana");
		states.add("Nebraska");
		states.add("Nevada");
		states.add("New Hampshire");
		states.add("New Jersey");
		states.add("New Mexico");
		states.add("New York");
		states.add("North Carolina");
		states.add("North Dakota");
		states.add("Ohio");
		states.add("Oklahoma");
		states.add("Oregon");
		states.add("Pennsylvania");
		states.add("Rhode Island");
		states.add("South Carolina");
		states.add("South Dakota");
		states.add("Tennessee");
		states.add("Texas");
		states.add("Utah");
		states.add("Vermont");
		states.add("Virginia");
		states.add("Washington");
		states.add("West Virginia");
		states.add("Wisconsin");
		states.add("Wyoming");

	}

	// ####################

	private FlowPane flowPane;
	private RadioButton leftRadioButton;
	private RadioButton rightRadioButton;
	private RadioButton centerRadioButton;
	private Checkbox alignToBaselineCheckbox;

	// ####################

}
