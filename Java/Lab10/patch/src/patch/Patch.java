
package patch;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.logging.Level;
import java.util.logging.Logger;


public class Patch {

    Statement st;
    Connection con;
    
    public  Patch(){
        try {
            DriverManager.registerDriver(new com.mysql.cj.jdbc.Driver());
            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/employeedata", "root", "Nadaahmed66##");
            st =con.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_UPDATABLE);
            
            st = con.createStatement() ;
            con.setAutoCommit(false);
            String queryString = "UPDATE data SET Vac_balance = 45 WHERE age >= 45";
            
            st.addBatch(queryString);
            
            queryString= "UPDATE data SET first = CONCAT('MRs. ',first) WHERE gender = 'Female'";
            st.addBatch(queryString);
            queryString="UPDATE data SET first = CONCAT('MR. ',first) where gender = 'Male'";
            st.addBatch(queryString);
            
            int[] count=st.executeBatch();
            con.commit();
            
            
            
        } catch (SQLException ex) {
           ex.printStackTrace();
        }finally {
            try {
                st.close();
                con.close();
            } catch (SQLException ex) {
                Logger.getLogger(Patch.class.getName()).log(Level.SEVERE, null, ex);
            }
    
        }
    }
    public static void main(String[] args) {
        new Patch();
    }
    
}
