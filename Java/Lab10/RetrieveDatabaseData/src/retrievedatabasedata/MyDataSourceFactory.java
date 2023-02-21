/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package retrievedatabasedata;

import com.mysql.cj.jdbc.MysqlDataSource;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.util.Properties;
import javax.sql.DataSource;

/**
 *
 * @author golden tech
 */
public class MyDataSourceFactory {
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
}
