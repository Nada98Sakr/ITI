package retrievedatabasedata;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Separator;
import javafx.scene.control.TextField;
import javafx.scene.control.ToolBar;
import javafx.scene.layout.Pane;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javax.sql.DataSource;

public class PersonInformationGUI extends Pane {

    protected final ToolBar toolBar;
    protected final Text text;
    protected final Label label;
    protected final TextField PersonID;
    protected final Label label0;
    protected final TextField PersonFName;
    protected final Label label1;
    protected final TextField PersonMName;
    protected final Label label2;
    protected final TextField PersonLName;
    protected final Label label3;
    protected final TextField PersonEmail;
    protected final Label label4;
    protected final TextField PersonPhone;
    protected final Button NewButton;
    protected final Button UpdateButton;
    protected final Button DeleteButton;
    protected final Button FirstButton;
    protected final Button PrevButton;
    protected final Button NextButton;
    protected final Button LastButton;
    protected final Separator separator;
    protected final Separator separator0;
    protected final Separator separator1;
    protected final Separator separator2;
    protected final Separator separator3;
    protected final Text text0;

    protected int counter = 1;

    public void ManipulateShownData(int ButtonCase) {
        DataSource ds = null;
        ds = MyDataSourceFactory.GetSqlDataSource();
        Connection con = null;
        Statement st = null;
        ResultSet rs = null;
        int lastIndex = 0;

        try {
            con = ds.getConnection();
            st = con.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE,
                    ResultSet.CONCUR_UPDATABLE);

            rs = st.executeQuery("select ID, FName, MName, LName, Email, Phone from person");

            while (rs.next()) {
                lastIndex++;
            }

            rs.beforeFirst();

            try {

                switch (ButtonCase) {
                    case 1:   //New
                        rs.moveToInsertRow();
                        PersonID.clear();
                        PersonFName.clear();
                        PersonMName.clear();
                        PersonLName.clear();
                        PersonEmail.clear();
                        PersonPhone.clear();
                        rs.insertRow();
                        counter = lastIndex + 1;
                        rs.absolute(counter);
                        break;

                    case 2:   //Update
                        rs.absolute(counter);
                        rs.updateString("Fname", PersonFName.getText());
                        rs.updateString("Mname", PersonMName.getText());
                        rs.updateString("Lname", PersonLName.getText());
                        rs.updateString("Email", PersonEmail.getText());
                        rs.updateString("Phone", PersonPhone.getText());
                        rs.updateRow();
                        break;

                    case 3:   //Delete
                        rs.absolute(counter);
                        rs.deleteRow();
                        counter--;
                        rs.absolute(counter);
                        break;

                    case 4:   //First
                        rs.first();
                        counter = 1;
                        break;

                    case 5:   //Prev
                        counter--;
                        if (counter < 1) {
                            counter = lastIndex;
                        }
                        rs.absolute(counter);
                        break;

                    case 6:   //Next
                        counter++;
                        if (counter > lastIndex) {
                            counter = 1;
                        }
                        rs.absolute(counter);
                        break;

                    case 7:   //Last
                        rs.last();
                        counter = lastIndex;
                        break;
                }

                if(ButtonCase != 1)
                {
                    PersonID.setText(rs.getString("ID"));
                    PersonFName.setText(rs.getString("FName"));
                    PersonMName.setText(rs.getString("MName"));
                    PersonLName.setText(rs.getString("LName"));
                    PersonEmail.setText(rs.getString("Email"));
                    PersonPhone.setText(rs.getString("Phone"));
                    st.close();
                    con.close();
                }

            } catch (Exception e) {
                e.printStackTrace();
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public PersonInformationGUI(Stage stage) {

        toolBar = new ToolBar();
        text = new Text();
        label = new Label();
        PersonID = new TextField();
        label0 = new Label();
        PersonFName = new TextField();
        label1 = new Label();
        PersonMName = new TextField();
        label2 = new Label();
        PersonLName = new TextField();
        label3 = new Label();
        PersonEmail = new TextField();
        label4 = new Label();
        PersonPhone = new TextField();
        NewButton = new Button();
        UpdateButton = new Button();
        DeleteButton = new Button();
        FirstButton = new Button();
        PrevButton = new Button();
        NextButton = new Button();
        LastButton = new Button();
        separator = new Separator();
        separator0 = new Separator();
        separator1 = new Separator();
        separator2 = new Separator();
        separator3 = new Separator();
        text0 = new Text();
        PersonID.setEditable(false);

        setMaxHeight(USE_PREF_SIZE);
        setMaxWidth(USE_PREF_SIZE);
        setMinHeight(USE_PREF_SIZE);
        setMinWidth(USE_PREF_SIZE);
        setPrefHeight(400.0);
        setPrefWidth(600.0);

        toolBar.setLayoutY(-4.0);
        toolBar.setPrefHeight(46.0);
        toolBar.setPrefWidth(600.0);

        text.setFill(javafx.scene.paint.Color.valueOf("#195894"));
        text.setStrokeType(javafx.scene.shape.StrokeType.OUTSIDE);
        text.setStrokeWidth(0.0);
        text.setText("Person Information");
        text.setTextAlignment(javafx.scene.text.TextAlignment.RIGHT);
        text.setWrappingWidth(201.134765625);
        text.setFont(new Font("System Bold", 20.0));

        label.setLayoutX(52.0);
        label.setLayoutY(97.0);
        label.setPrefHeight(25.0);
        label.setPrefWidth(92.0);
        label.setText("ID");
        label.setFont(new Font("System Bold", 14.0));

        PersonID.setLayoutX(151.0);
        PersonID.setLayoutY(97.0);
        PersonID.setPrefHeight(25.0);
        PersonID.setPrefWidth(395.0);

        label0.setLayoutX(52.0);
        label0.setLayoutY(133.0);
        label0.setPrefHeight(25.0);
        label0.setPrefWidth(92.0);
        label0.setText("First name");
        label0.setFont(new Font("System Bold", 14.0));

        PersonFName.setLayoutX(151.0);
        PersonFName.setLayoutY(133.0);
        PersonFName.setPrefHeight(25.0);
        PersonFName.setPrefWidth(395.0);

        label1.setLayoutX(52.0);
        label1.setLayoutY(167.0);
        label1.setPrefHeight(25.0);
        label1.setPrefWidth(92.0);
        label1.setText("Middle Name");
        label1.setFont(new Font("System Bold", 14.0));

        PersonMName.setLayoutX(151.0);
        PersonMName.setLayoutY(167.0);
        PersonMName.setPrefHeight(25.0);
        PersonMName.setPrefWidth(395.0);

        label2.setLayoutX(52.0);
        label2.setLayoutY(203.0);
        label2.setPrefHeight(25.0);
        label2.setPrefWidth(92.0);
        label2.setText("Last Name");
        label2.setFont(new Font("System Bold", 14.0));

        PersonLName.setLayoutX(151.0);
        PersonLName.setLayoutY(203.0);
        PersonLName.setPrefHeight(25.0);
        PersonLName.setPrefWidth(395.0);

        label3.setLayoutX(52.0);
        label3.setLayoutY(236.0);
        label3.setPrefHeight(25.0);
        label3.setPrefWidth(92.0);
        label3.setText("Email");
        label3.setFont(new Font("System Bold", 14.0));

        PersonEmail.setLayoutX(151.0);
        PersonEmail.setLayoutY(236.0);
        PersonEmail.setPrefHeight(25.0);
        PersonEmail.setPrefWidth(395.0);

        label4.setLayoutX(52.0);
        label4.setLayoutY(270.0);
        label4.setPrefHeight(25.0);
        label4.setPrefWidth(92.0);
        label4.setText("Phone");
        label4.setFont(new Font("System Bold", 14.0));

        PersonPhone.setLayoutX(151.0);
        PersonPhone.setLayoutY(270.0);
        PersonPhone.setPrefWidth(395.0);

        NewButton.setLayoutX(63.0);
        NewButton.setLayoutY(322.0);
        NewButton.setMnemonicParsing(false);
        NewButton.setPrefHeight(33.0);
        NewButton.setPrefWidth(52.0);
        NewButton.setText("New");
        NewButton.setFont(new Font(14.0));
        NewButton.setOnAction(event -> {
            ManipulateShownData(1);
        });

        UpdateButton.setLayoutX(124.0);
        UpdateButton.setLayoutY(322.0);
        UpdateButton.setMnemonicParsing(false);
        UpdateButton.setPrefHeight(33.0);
        UpdateButton.setPrefWidth(72.0);
        UpdateButton.setText("Update");
        UpdateButton.setFont(new Font(14.0));
        UpdateButton.setOnAction(event -> {
            ManipulateShownData(2);
        });

        DeleteButton.setLayoutX(205.0);
        DeleteButton.setLayoutY(322.0);
        DeleteButton.setMnemonicParsing(false);
        DeleteButton.setPrefHeight(33.0);
        DeleteButton.setPrefWidth(62.0);
        DeleteButton.setText("Delete");
        DeleteButton.setFont(new Font(14.0));

        DeleteButton.setOnAction(event -> {
            ManipulateShownData(3);
        });

        FirstButton.setLayoutX(275.0);
        FirstButton.setLayoutY(322.0);
        FirstButton.setMnemonicParsing(false);
        FirstButton.setPrefHeight(33.0);
        FirstButton.setPrefWidth(52.0);
        FirstButton.setText("First");
        FirstButton.setFont(new Font(14.0));

        FirstButton.setOnAction(event -> {
            ManipulateShownData(4);
        });

        PrevButton.setLayoutX(336.0);
        PrevButton.setLayoutY(322.0);
        PrevButton.setMnemonicParsing(false);
        PrevButton.setPrefHeight(33.0);
        PrevButton.setPrefWidth(79.0);
        PrevButton.setText("Previous");
        PrevButton.setFont(new Font(14.0));

        PrevButton.setOnAction(event -> {
            ManipulateShownData(5);
        });

        NextButton.setLayoutX(425.0);
        NextButton.setLayoutY(322.0);
        NextButton.setMnemonicParsing(false);
        NextButton.setPrefHeight(33.0);
        NextButton.setPrefWidth(52.0);
        NextButton.setText("Next");
        NextButton.setFont(new Font(14.0));
        NextButton.setOnAction(event -> {
            ManipulateShownData(6);
        });

        LastButton.setLayoutX(485.0);
        LastButton.setLayoutY(322.0);
        LastButton.setMnemonicParsing(false);
        LastButton.setPrefHeight(33.0);
        LastButton.setPrefWidth(52.0);
        LastButton.setText("Last");
        LastButton.setFont(new Font(14.0));
        LastButton.setOnAction(event -> {
            ManipulateShownData(7);
        });

        separator.setLayoutX(29.0);
        separator.setLayoutY(374.0);
        separator.setPrefHeight(2.0);
        separator.setPrefWidth(542.0);

        separator0.setLayoutX(25.0);
        separator0.setLayoutY(69.0);
        separator0.setOrientation(javafx.geometry.Orientation.VERTICAL);
        separator0.setPrefHeight(305.0);
        separator0.setPrefWidth(11.0);

        separator1.setLayoutX(566.0);
        separator1.setLayoutY(69.0);
        separator1.setOrientation(javafx.geometry.Orientation.VERTICAL);
        separator1.setPrefHeight(305.0);
        separator1.setPrefWidth(11.0);

        separator2.setLayoutX(177.0);
        separator2.setLayoutY(68.0);
        separator2.setPrefHeight(3.0);
        separator2.setPrefWidth(395.0);

        separator3.setLayoutX(29.0);
        separator3.setLayoutY(67.0);
        separator3.setPrefHeight(3.0);
        separator3.setPrefWidth(43.0);

        text0.setLayoutX(89.0);
        text0.setLayoutY(74.0);
        text0.setStrokeType(javafx.scene.shape.StrokeType.OUTSIDE);
        text0.setStrokeWidth(0.0);
        text0.setText("person data");
        text0.setWrappingWidth(99.13671875);
        text0.setFont(new Font("System Bold", 14.0));

        toolBar.getItems().add(text);
        getChildren().add(toolBar);
        getChildren().add(label);
        getChildren().add(PersonID);
        getChildren().add(label0);
        getChildren().add(PersonFName);
        getChildren().add(label1);
        getChildren().add(PersonMName);
        getChildren().add(label2);
        getChildren().add(PersonLName);
        getChildren().add(label3);
        getChildren().add(PersonEmail);
        getChildren().add(label4);
        getChildren().add(PersonPhone);
        getChildren().add(NewButton);
        getChildren().add(UpdateButton);
        getChildren().add(DeleteButton);
        getChildren().add(FirstButton);
        getChildren().add(PrevButton);
        getChildren().add(NextButton);
        getChildren().add(LastButton);
        getChildren().add(separator);
        getChildren().add(separator0);
        getChildren().add(separator1);
        getChildren().add(separator2);
        getChildren().add(separator3);
        getChildren().add(text0);

    }
}
