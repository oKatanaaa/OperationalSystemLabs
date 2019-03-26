package gui.StartPage.panels;

import javax.swing.*;

public class ChoicePanel extends JPanel {
    private String manualBtnName = "Manual";
    private JButton manualBtn;
    private String fileBtnName = "File";
    private JButton fileBtn;

    public ChoicePanel() {
        this.manualBtn = new JButton(this.manualBtnName);
        this.fileBtn = new JButton(this.fileBtnName);

        add(this.manualBtn);
        add(this.fileBtn);
    }

    public JButton getManualBtn() {
        return this.manualBtn;
    }

    public JButton getFileBtn() {
        return this.fileBtn;
    }
}
