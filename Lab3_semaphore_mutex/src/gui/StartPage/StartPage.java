package gui.StartPage;

import gui.Page;
import gui.StartPage.listeners.ChoicePanelListener;
import gui.StartPage.listeners.ManualPanelListener;

public interface StartPage extends Page {
    void setChoiceMode();
    void setManualMode();
    void setChoicePanelListener(ChoicePanelListener listener);
    void setManualPanelListener(ManualPanelListener listener);
    String getText();

    class ChoosePanel {
    }
}
