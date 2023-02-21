
package Insertion;
import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Insertion {
    Statement stmt;
    Connection con;
    
    public Insertion() {
    
        try {
            DriverManager.registerDriver(new com.mysql.cj.jdbc.Driver());
            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/employeedata", "root", "Nadaahmed66##");
            stmt =con.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_UPDATABLE);
        
            PreparedStatement pst = con.prepareStatement("insert into data values(?,?,?,?,?,?)");
            pst.setInt(1, 1);
            pst.setString(2, "Nada");
            pst.setString(3, "Saeed");
            pst.setString(4, "Female");
            pst.setInt(5, 24);
            pst.setInt(6, 30);
            pst.executeUpdate() ;
            
            PreparedStatement pst1 = con.prepareStatement("insert into data values(?,?,?,?,?,?)");
            pst1.setInt(1, 2);
            pst1.setString(2, "hager");
            pst1.setString(3, "khaled");
            pst1.setString(4, "Female");
            pst1.setInt(5, 25);
            pst1.setInt(6, 30);
            pst1.executeUpdate() ;
            
            PreparedStatement pst2 = con.prepareStatement("insert into data values(?,?,?,?,?,?)");
            pst2.setInt(1, 3);
            pst2.setString(2, "Mahmoud");
            pst2.setString(3, "Mohame");
            pst2.setString(4, "Male");
            pst2.setInt(5, 20);
            pst2.setInt(6, 30);
            pst2.executeUpdate() ;
            
            PreparedStatement pst3 = con.prepareStatement("insert into data values(?,?,?,?,?,?)");
            pst3.setInt(1, 4);
            pst3.setString(2, "Hager");
            pst3.setString(3, "Ahmed");
            pst3.setString(4, "Female");
            pst3.setInt(5, 23);
            pst3.setInt(6, 30);
            pst3.executeUpdate() ;
            
            PreparedStatement pst4 = con.prepareStatement("insert into data values(?,?,?,?,?,?)");
            pst4.setInt(1, 5);
            pst4.setString(2, "Mohab");
            pst4.setString(3, "Mohamed");
            pst4.setString(4, "Male");
            pst4.setInt(5, 45);
            pst4.setInt(6, 30);
            pst4.executeUpdate() ;
        
        } catch (SQLException ex) {
            ex.printStackTrace();
        }finally {
            try {
                stmt.close();
                con.close();
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
        }

        
        
    }


    public static void main(String[] args) {
     new Insertion();
    }
}
