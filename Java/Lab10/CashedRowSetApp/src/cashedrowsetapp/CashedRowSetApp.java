
package cashedrowsetapp;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import javax.sql.rowset.CachedRowSet;
import javax.sql.rowset.RowSetFactory;
import javax.sql.rowset.RowSetProvider;


public class CashedRowSetApp {

    
    public static void main(String[] args) throws SQLException {
        DriverManager.registerDriver(new com.mysql.jdbc.Driver());
        Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/persondata", "root", "Nadaahmed66##");
        
        con.setAutoCommit(false);
        RowSetFactory factory = RowSetProvider.newFactory();
        CachedRowSet rowSet = factory.createCachedRowSet();
        
        rowSet.setCommand("select * from person");
        rowSet.execute(con);
        
        //update
        while(rowSet.next()) {
            if(rowSet.getInt(1) == 12) {
                rowSet.deleteRow();
                System.out.println("Row deleted...");
            }
            
            if(rowSet.getInt(1) == 10) {
                rowSet.updateString(3, "Khaled");
                rowSet.updateRow();
                System.out.println("Row Updated...");
            }
        }
        
        rowSet.acceptChanges(con);
        rowSet.beforeFirst();
        
        //Insert
        rowSet.moveToInsertRow();
        rowSet.updateInt(1, 13);
        rowSet.updateString(2, "Radwa");
        rowSet.updateString(3, "Mahmoud");
        rowSet.updateString(4, "Samy");
        rowSet.updateString(5,"Radwa@gmail.com");
        rowSet.updateString(6, "01022");
        rowSet.insertRow();
        rowSet.moveToCurrentRow();
        
        System.out.println("Contents of the row set");
        while(rowSet.next()) {
           System.out.print("ID: "+rowSet.getInt(1)+", ");
           System.out.print("First Name: "+rowSet.getString(2)+", ");
           System.out.print("Middle Namme: "+rowSet.getString(3)+", ");
           System.out.print("Last Name: "+rowSet.getString(4)+", ");
           System.out.print("Email: "+rowSet.getString(5));
           System.out.print("Phone: "+rowSet.getString(6));
           System.out.println("");
        }
        
        
    }
    
}
