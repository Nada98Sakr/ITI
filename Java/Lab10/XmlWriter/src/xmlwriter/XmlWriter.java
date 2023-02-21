
package xmlwriter;

import com.sun.rowset.WebRowSetImpl;
import java.io.FileWriter;
import java.io.IOException;
import java.sql.SQLException;

public class XmlWriter {
    
    public static void main(String[] args) throws SQLException, IOException{
        FileWriter personFileWriter;
        WebRowSetImpl ListOfPersons = new WebRowSetImpl();
        ListOfPersons.setUrl("jdbc:mysql://localhost:3306/persondata");
        ListOfPersons.setUsername("root");
        ListOfPersons.setPassword("Nadaahmed66##");
        int key[] = {1};
        ListOfPersons.setCommand("select * from person");
        ListOfPersons.setKeyColumns(key);
        
        ListOfPersons.execute();
        
        while(ListOfPersons.next())
        {
            System.out.print(ListOfPersons.getInt("ID") + " , " );
            System.out.print(ListOfPersons.getString("Fname") + " , " );
            System.out.print(ListOfPersons.getString("Mname") + " , " );
            System.out.print(ListOfPersons.getString("Lname") + " , " );
            System.out.print(ListOfPersons.getString("Email") + " , " );
            System.out.println(ListOfPersons.getString("Phone"));            
        }
        
        personFileWriter = new FileWriter("personFile.xml");
        ListOfPersons.writeXml(personFileWriter);
        personFileWriter.close();
        
        
    }
    
}
