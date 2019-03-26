package gui.StartPage.panels;

import javax.swing.*;

public class ManualPanel extends JPanel {
    private JTextField text;
    private JButton okBtn;
    private JButton cancelBtn;

    public ManualPanel() {
        this.text = new JTextField(10);
        this.okBtn = new JButton("OK");
        this.cancelBtn = new JButton("Cancel");

        add(this.text);
        add(this.okBtn);
        add(this.cancelBtn);
    }

    public JTextField getText() {
        return this.text;
    }

    public JButton getOkBtn() {
        return this.okBtn;
    }

    public JButton getCancelBtn() {
        return this.cancelBtn;
    }
}
