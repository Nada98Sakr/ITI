/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sqlusingfile;

import com.mysql.cj.jdbc.MysqlDataSource;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.Properties;
import javax.sql.DataSource;

public class SqlUsingFile {
    
    public static void CreatePropertiesFile(String url, String userName, String pass)
    {
        Properties prop = new Properties();
        OutputStream out = null;
        try {
            out = new FileOutputStream("db.properties");
            prop.setProperty("MYSQL_DB_URL", url);
            prop.setProperty("MYSQL_DB_USERNAME", userName);
            prop.setProperty("MYSQL_DB_PASSWORD", pass);
            prop.store(out, null);
            
        } catch (Exception e) {
            e.printStackTrace();
        }
        finally{
            if (out == null) {
                try {
                    out.close();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }
    
    public static DataSource GetSqlDataSource()
    {
        Properties prop = new Properties();
        FileInputStream in = null;
        MysqlDataSource sqlDataSource = null;
        
        try {
            in = new FileInputStream("db.properties");
            prop.load(in);
            sqlDataSource = new MysqlDataSource();
            
            sqlDataSource.setURL(prop.getProperty("MYSQL_DB_URL"));
            sqlDataSource.setUser(prop.getProperty("MYSQL_DB_USERNAME"));
            sqlDataSource.setPassword(prop.getProperty("MYSQL_DB_PASSWORD"));
            
            
        } catch (Exception e) {
            e.printStackTrace();
        }
        
        return (DataSource) sqlDataSource;
    }
    
    public static void TestDataSource()
    {
        DataSource ds = null;
        ds = SqlUsingFile.GetSqlDataSource();
        Connection con = null;
        Statement st = null;
        ResultSet rs = null;
        try {
            con = ds.getConnection();
            st = con.createStatement();
            rs =  st.executeQuery("select * from person");
            
            while(rs.next())
            {
                System.out.println(rs.getString(1)+ " " +rs.getString(2) + " " +rs.getString(3) + " " +rs.getString(4)+ " " +rs.getString(5)+ " " +rs.getString(6));
            }
            
        } catch (Exception e) {
            e.printStackTrace();
        } finally{
            try {
                if(rs != null)
                    rs.close();
                if(st != null)
                    st.close();
                if(con != null)
                    con.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
    
    public static void main(String[] args) {
       // CreatePropertiesFile("jdbc:mysql://localhost:3306/persondata", "root", "Nadaahmed66##");
        TestDataSource();
    }
    
}
