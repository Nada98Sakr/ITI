
package connectingtosql;
import java.sql.*;

public class ConnectingToSql {

    public ConnectingToSql()
    {
        
        try {
            DriverManager.registerDriver(new com.mysql.cj.jdbc.Driver());
            try (
                    Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/sakila", "root","Nadaahmed66##"); 
                    Statement st = con.createStatement(
                                                        ResultSet.CONCUR_UPDATABLE,
                                                        ResultSet.TYPE_SCROLL_SENSITIVE)) 
                    
                    {
                        //String querString = "insert into actor values(202, \"Saaed\", \"Aly\", \"2023-01-03 10:00:00\")";
                        //int insertResult = st.executeUpdate(querString);
                        
                        String querString = "UPDATE actor set first_name = \"radwa\" WHERE actor_id = 200";
                        int UpdateResult = st.executeUpdate(querString);
                        
                        if(UpdateResult>0)
                        {
                            System.out.println("Successful");
                        }
                                             
                        querString = "select * from actor";
                        ResultSet result = st.executeQuery(querString);
                        
                        while(result.next())
                        {
                            System.out.println(result.getString(1)+ " " +result.getString(2) + " " +result.getString(3) + " " +result.getString(4));
                        }
                    }
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        new ConnectingToSql();
    }
    
}
