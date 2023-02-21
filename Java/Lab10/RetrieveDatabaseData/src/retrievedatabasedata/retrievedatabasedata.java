/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package retrievedatabasedata;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class retrievedatabasedata extends Application{
    @Override
    public void start(Stage stage) throws Exception {
        PersonInformationGUI root = new PersonInformationGUI(stage);
        
        Scene scene = new Scene(root);
        
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
