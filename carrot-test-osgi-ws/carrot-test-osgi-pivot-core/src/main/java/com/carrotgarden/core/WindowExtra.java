package com.carrotgarden.core;

import java.net.URL;

import org.apache.pivot.beans.Bindable;
import org.apache.pivot.collections.Map;
import org.apache.pivot.collections.Sequence;
import org.apache.pivot.util.Resources;
import org.apache.pivot.util.concurrent.TaskExecutionException;
import org.apache.pivot.wtk.Alert;
import org.apache.pivot.wtk.ApplicationContext;
import org.apache.pivot.wtk.Button;
import org.apache.pivot.wtk.ButtonGroup;
import org.apache.pivot.wtk.ButtonPressListener;
import org.apache.pivot.wtk.ImageView;
import org.apache.pivot.wtk.Label;
import org.apache.pivot.wtk.ListButton;
import org.apache.pivot.wtk.ListButtonSelectionListener;
import org.apache.pivot.wtk.ListView;
import org.apache.pivot.wtk.ListViewSelectionListener;
import org.apache.pivot.wtk.MessageType;
import org.apache.pivot.wtk.PushButton;
import org.apache.pivot.wtk.Span;
import org.apache.pivot.wtk.Window;
import org.apache.pivot.wtk.media.Image;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class WindowExtra extends Window implements Bindable {

	protected static final Logger log = LoggerFactory
			.getLogger(WindowExtra.class);

	private PushButton pushButton;

	private PushButton selectButton;

	private ListView listView;
	private Label selectionLabel;

	private ListButton listButton;
	private ImageView imageView;

	@Override
	public void initialize(Map<String, Object> namespace, URL location,
			Resources resources) {

		// ###############

		pushButton = (PushButton) namespace.get("pushButton");

		ButtonPressListener listener = new ButtonPressListener() {
			@Override
			public void buttonPressed(Button button) {
				Alert.alert(MessageType.INFO, "You clicked me!",
						WindowExtra.this);
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
				Alert.alert(MessageType.INFO, message, WindowExtra.this);
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

		listButton.setSelectedIndex(0);

	}

	// ###############

}
