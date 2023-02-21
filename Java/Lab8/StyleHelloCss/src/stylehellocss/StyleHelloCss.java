/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package stylehellocss;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.StackPane;
import javafx.scene.text.Text;
import javafx.stage.Stage;

/**
 *
 * @author golden tech
 */
public class StyleHelloCss extends Application {
    
    @Override
    public void start(Stage primaryStage) {
        Text txt = new Text("Hello World!");
        txt.setId("text");      
        
        StackPane root = new StackPane();
        root.getChildren().add(txt);
        Scene scene = new Scene(root, 400, 350);
        scene.getStylesheets().add("style.css");
       //scene.getStylesheets().add(getClass().getResource("style.css").toString());

        primaryStage.setTitle("Hello World!");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
    
}
