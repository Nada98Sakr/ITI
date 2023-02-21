/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package stylehelloworld;

import java.awt.MultipleGradientPaint.CycleMethod;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.effect.Reflection;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.paint.LinearGradient;
import javafx.scene.paint.Paint;
import javafx.scene.paint.Stop;
import javafx.scene.text.Font;
import javafx.scene.text.FontPosture;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;

/**
 *
 * @author golden tech
 */
public class StyleHelloWorld extends Application {
    
    @Override
    public void start(Stage primaryStage) 
    {
        Text txt = new Text("Hello World");
        txt.setId("text");
        txt.setFill(Color.RED);
        Font font = Font.font("Verdana", FontWeight.EXTRA_BOLD, 25);
        txt.setFont(font);
        
        Stop[] stops = new Stop[] { new Stop(0, Color.BLACK), new Stop(0.5, Color.WHITE), new Stop(1, Color.BLACK)};
        LinearGradient lg = new LinearGradient(0, 0, 0, 1, true,javafx.scene.paint.CycleMethod.NO_CYCLE, stops);
        
        Reflection reflection = new Reflection();
        reflection.setFraction(0.8);
        txt.setEffect(reflection);
        
        StackPane root = new StackPane();
        root.getChildren().add(txt);
        
        Scene sc = new Scene(root, 300, 250);
        sc.setFill(lg);
        
        
        primaryStage.setTitle("Hello World!");
        primaryStage.setScene(sc);
        primaryStage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
    
}
