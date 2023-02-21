package notepad;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.application.Platform;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.SeparatorMenuItem;
import javafx.scene.control.TextArea;
import javafx.scene.layout.BorderPane;
import javafx.stage.FileChooser;
import javax.swing.JFileChooser;

public class NotepadUI extends BorderPane {

    protected final MenuBar menuBar;
    protected final Menu menu;
    protected final MenuItem menuItem;
    protected final MenuItem menuItem0;
    protected final MenuItem menuItem1;
    protected final SeparatorMenuItem separatorMenuItem;
    protected final MenuItem menuItem2;
    protected final Menu menu0;
    protected final MenuItem menuItem3;
    protected final SeparatorMenuItem separatorMenuItem0;
    protected final MenuItem menuItem4;
    protected final MenuItem menuItem5;
    protected final MenuItem menuItem6;
    protected final MenuItem menuItem7;
    protected final SeparatorMenuItem separatorMenuItem1;
    protected final MenuItem menuItem8;
    protected final Menu menu1;
    protected final MenuItem menuItem9;
    protected final TextArea textArea;
   // protected final Stage stage;

    public NotepadUI() {
        

        menuBar = new MenuBar();
        menu = new Menu();
        menuItem = new MenuItem();
        menuItem0 = new MenuItem();
        menuItem1 = new MenuItem();
        separatorMenuItem = new SeparatorMenuItem();
        menuItem2 = new MenuItem();
        menu0 = new Menu();
        menuItem3 = new MenuItem();
        separatorMenuItem0 = new SeparatorMenuItem();
        menuItem4 = new MenuItem();
        menuItem5 = new MenuItem();
        menuItem6 = new MenuItem();
        menuItem7 = new MenuItem();
        separatorMenuItem1 = new SeparatorMenuItem();
        menuItem8 = new MenuItem();
        menu1 = new Menu();
        menuItem9 = new MenuItem();
        textArea = new TextArea();

        setMaxHeight(USE_PREF_SIZE);
        setMaxWidth(USE_PREF_SIZE);
        setMinHeight(USE_PREF_SIZE);
        setMinWidth(USE_PREF_SIZE);
        setPrefHeight(400.0);
        setPrefWidth(600.0);

        BorderPane.setAlignment(menuBar, javafx.geometry.Pos.CENTER);

        menu.setMnemonicParsing(false);
        menu.setText("File");

        menuItem.setMnemonicParsing(false);
        menuItem.setText("New");
        menuItem.setOnAction(event -> {
            textArea.clear();
        });

        menuItem0.setMnemonicParsing(false);
        menuItem0.setText("Open");
        menuItem0.setOnAction(event -> {
            JFileChooser jFileChooser = new JFileChooser();
            StringBuffer buffer;
            buffer = new StringBuffer();
            int result = jFileChooser.showOpenDialog(null);
            if (result == JFileChooser.APPROVE_OPTION) {
                try {
                    FileReader reader = null;

                    File file = jFileChooser.getSelectedFile();
                    reader = new FileReader(file);
                    int i = 1;
                    while (i != -1) {
                        i = reader.read();
                        char ch = (char) i;
                        buffer.append(ch);

                    }
                    textArea.setText(buffer.toString());
                } catch (FileNotFoundException ex) {
                    Logger.getLogger(NotepadUI.class.getName()).log(Level.SEVERE, null, ex);
                } catch (IOException ex) {
                    Logger.getLogger(NotepadUI.class.getName()).log(Level.SEVERE, null, ex);
                }
            }  
        });

        menuItem1.setMnemonicParsing(false);
        menuItem1.setText("Save");
        menuItem1.setOnAction(event ->{
            FileChooser fc = new FileChooser();
            FileChooser.ExtensionFilter ext = new FileChooser.ExtensionFilter("undefined", ".txt");
            File savefile = fc.showSaveDialog(null);
            try {
                FileWriter fw = new FileWriter(savefile);
                fw.write(textArea.getText());
                fw.close();
            } catch (IOException ex) {
                System.out.println(ex.getMessage());
            }
        });

        separatorMenuItem.setMnemonicParsing(false);

        menuItem2.setMnemonicParsing(false);
        menuItem2.setText("Exit");
        menuItem2.setOnAction(event -> {
            Platform.exit();
        });

        menu0.setMnemonicParsing(false);
        menu0.setText("Edit");

        menuItem3.setMnemonicParsing(false);
        menuItem3.setText("Undo");
        menuItem3.setOnAction(event -> {
            textArea.undo();
        });

        separatorMenuItem0.setMnemonicParsing(false);

        menuItem4.setMnemonicParsing(false);
        menuItem4.setText("Cut");
        menuItem4.setOnAction(event -> {
            textArea.cut();
        });

        menuItem5.setMnemonicParsing(false);
        menuItem5.setText("Copy");
        menuItem5.setOnAction(event -> {
            textArea.copy();
        });

        menuItem6.setMnemonicParsing(false);
        menuItem6.setText("Paste");
        menuItem6.setOnAction((event -> {
            textArea.paste();
        }));

        menuItem7.setMnemonicParsing(false);
        menuItem7.setText("Delete");
        menuItem7.setOnAction(event -> {
            textArea.replaceSelection("");
        });

        separatorMenuItem1.setMnemonicParsing(false);

        menuItem8.setMnemonicParsing(false);
        menuItem8.setText("Select All");
        menuItem8.setOnAction(event -> {
            textArea.selectAll();
        });


        menu1.setMnemonicParsing(false);
        menu1.setText("Help");

        menuItem9.setMnemonicParsing(false);
        menuItem9.setText("About Notepad");
        menuItem9.setOnAction(event -> {
            Alert alert = new Alert(AlertType.INFORMATION, "FX NotePad Version 0.0 created by javaTeam in the ITI");
            alert.show();
        });
        setTop(menuBar);

        BorderPane.setAlignment(textArea, javafx.geometry.Pos.CENTER);
        textArea.setPrefHeight(200.0);
        textArea.setPrefWidth(200.0);
        setCenter(textArea);

        menu.getItems().add(menuItem);
        menu.getItems().add(menuItem0);
        menu.getItems().add(menuItem1);
        menu.getItems().add(separatorMenuItem);
        menu.getItems().add(menuItem2);
        menuBar.getMenus().add(menu);
        menu0.getItems().add(menuItem3);
        menu0.getItems().add(separatorMenuItem0);
        menu0.getItems().add(menuItem4);
        menu0.getItems().add(menuItem5);
        menu0.getItems().add(menuItem6);
        menu0.getItems().add(menuItem7);
        menu0.getItems().add(separatorMenuItem1);
        menu0.getItems().add(menuItem8);
        menuBar.getMenus().add(menu0);
        menu1.getItems().add(menuItem9);
        menuBar.getMenus().add(menu1);

    }
}
