import java.util.*;

class StudentNotFoundException extends Exception
{
	public StudentNotFoundException(String Message)
	{
		super(Message);
	}
}


class StudentData{
    public String checkID(String ID) throws StudentNotFoundException {
		Integer studentID = Integer.parseInt(ID);
		
        if (studentID > 0 && studentID < 100) 
		{
            return ID;
        } 
		else 
		{
            throw new StudentNotFoundException(
                "Could not find student with ID " + studentID);
        }
    }
 
    public String checkName(String Name) throws StudentNotFoundException {
        if (Name.equals("Nada")) 
		{
            return Name;
        } 
		
		else 
		{
            throw new StudentNotFoundException(
                "Could not find student with Name " + Name);
        }
    }
	
	    public String checkSubject(String Subject) throws StudentNotFoundException {
        if (Subject.equals("Math")) 
		{
            return Subject;
        } 
		else 
		{
            throw new StudentNotFoundException(
                "Could not find student Studies Subject " + Subject);
        }
    }
}


class StudentTest {
    public static void main(String[] args) {
        StudentData Student = new StudentData();
		
        if(args.length == 3)
		{
			try 
			{
				Integer StudentID = Integer.parseInt(Student.checkID(args[0]));
				String StudentName = Student.checkName(args[1]);
				String StudentSubject = Student.checkSubject(args[2]);
			} 
			catch (StudentNotFoundException ex) 
			{
				System.err.print(ex);
			}
		}
		else
		{
			System.out.println("Please Enter 3 Arguments");
		}
    }
}
