package gui;

import gui.StartPage.StartWindowImpl;
import gui.StartPage.listeners.ChoicePanelListener;
import gui.StartPage.listeners.ManualPanelListener;

import javax.swing.*;
import java.awt.*;

public class Test {

    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            StartWindowImpl frame = new StartWindowImpl();
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setVisible(true);

            frame.setChoicePanelListener(new ChoicePanelListener() {
                @Override
                public void onManualBtnClicked() {
                    frame.setManualMode();
                }

                @Override
                public void onFileBtnClicked() {

                }
            });

            frame.setManualPanelListener(new ManualPanelListener() {
                @Override
                public void onOkBtnClicked() {

                }

                @Override
                public void onCancelBtnClicked() {
                    frame.setChoiceMode();
                }
            });
        });
    }
}
