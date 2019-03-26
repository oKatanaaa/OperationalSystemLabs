package gui.StartPage;

import gui.OnCloseBtnClickListener;
import gui.StartPage.listeners.ChoicePanelListener;
import gui.StartPage.listeners.ManualPanelListener;
import gui.StartPage.panels.ChoicePanel;
import gui.StartPage.panels.ManualPanel;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;


public class StartPageImpl extends JFrame implements StartPage {

    private int CHOICE_MODE = 0;
    private int MANUAL_MODE = 1;
    private int mode = CHOICE_MODE;

    private ChoicePanel choicePanel;
    private JButton manualBtn;
    private JButton fileBtn;

    private ManualPanel manualPanel;
    private JButton okBtn;
    private JButton cancelBtn;
    private JTextField text;

    // Currently these fields aren't used anywhere
    private ChoicePanelListener choicePanelListener;
    private ManualPanelListener manualPanelListener;

    public StartPageImpl() {
        setTitle("Start Page");
        setSize(300, 200);

        this.choicePanel = new ChoicePanel();
        this.manualBtn = this.choicePanel.getManualBtn();
        this.fileBtn = this.choicePanel.getFileBtn();

        this.manualPanel = new ManualPanel();
        this.okBtn = this.manualPanel.getOkBtn();
        this.cancelBtn = this.manualPanel.getCancelBtn();
        this.text = this.manualPanel.getText();

        add(this.choicePanel);
    }


    @Override
    public void setChoiceMode() {
        this.mode = this.CHOICE_MODE;
        getContentPane().removeAll();
        add(this.choicePanel);
        validate();
        repaint();
    }

    @Override
    public void setManualMode() {
        this.mode = this.MANUAL_MODE;
        getContentPane().removeAll();
        add(this.manualPanel);
        validate();
        repaint();
    }

    @Override
    public void setChoicePanelListener(final ChoicePanelListener listener) {
        this.choicePanelListener = listener;

        this.manualBtn.addActionListener(e -> listener.onManualBtnClicked());

        this.fileBtn.addActionListener(e -> listener.onFileBtnClicked());
    }

    @Override
    public void setManualPanelListener(ManualPanelListener listener) {
        this.manualPanelListener = listener;

        this.okBtn.addActionListener(e -> listener.onOkBtnClicked());

        this.cancelBtn.addActionListener(e -> listener.onCancelBtnClicked());
    }

    @Override
    public String getText() {
        return this.text.getText();
    }

    @Override
    public void setOnCloseBtnClickListener(OnCloseBtnClickListener listener) {

    }

    @Override
    public void close() {
        dispatchEvent(new WindowEvent(this, WindowEvent.WINDOW_CLOSING));
    }
}
