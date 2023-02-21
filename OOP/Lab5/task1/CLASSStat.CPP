#include <iostream.h>
#include <conio.h>
#include <string.h>

class student
{
    private:
	int   ID;
	char *Name;
	int   Grade;
	static int count;
	static char schoolName[10];
    public:
	void  setID(int id);
	int   getID();
	void  setName(char name[]);
	char *getName();
	void  setGrade(int grade);
	int   getGrade();
	static int getCount()
	{
	    return count;
	}
	static void setSchoolName(char school[10])
	{
	    strcpy(schoolName, school);
	}
	static char * getSchoolName()
	{
	    return schoolName;
	}


	student operator = (student std);

	student()
	{
	    ID   = 0;
	    Name = new char[5];
	    strcpy(Name, "NULL");
	    Grade= 0;
	    count++;
	}

	student(int id, char name[], int grade)
	{
	    ID   = id;
	    Name = new char[strlen(name)+1];
	    strcpy(Name, name);
	    Grade= grade;
	    count++;
	}

	student(student &std)
	{
	    ID   = std.ID;
	    Name = new char[strlen(std.Name)+1];
	    strcpy(Name, std.Name);
	    Grade= std.Grade;
	    count++;
	}

	~ student()
	{
	    delete(Name);
	    count--;
	}
};

//----------------------------------------------------------------------

student fillStd();
void    printStd(student std);
inline char *  ConcatName(char n1[], char n2[]);

int student::count = 0;
char student::schoolName[10] = "ITI";

//----------------------------------------------------------------------
int main()
{
    int stdN;
    cout << "Eneter Number of studnet: ";
    cin >> stdN;
    cout <<endl;

    student * ptr;
    ptr = new student[stdN];

    char school[10];

    cout <<"Please enter school Name: ";
    cin  >> school;
    student::setSchoolName(school);

    for(int i = 0; i<stdN; i++)
    {
	ptr[i] = fillStd();
    }

    cout<<"Number of student in the "<<student::getSchoolName()<<" = "<<student::getCount()<<endl;

    for(i = 0; i< stdN; i++)
    {
	printStd(ptr[i]);
    }

    delete []ptr;

    getch();
    clrscr();
    return 0;
}

//----------------------------------------------------------------------
student fillStd()
{
    student std;
    int ID, Grade;
    char Name[20];

    cout <<endl;
    cout << "Enter student ID: ";
    cin  >> ID;
    std.setID(ID);

    cout << "Enter student Name: ";
    cin  >> Name;
    std.setName(Name);

    cout << "Enter student Grade: ";
    cin  >> Grade;
    std.setGrade(Grade);

    cout<< endl;

    return std;
}


void printStd( student std)
{
    cout<< endl;
    cout<< "   Student Info:"<<endl;
    cout<< "      Student ID   : "<< std.getID()<< endl;
    cout<< "      Student Name : "<< std.getName()<< endl;
    cout<< "      Student Grade: "<< std.getGrade()<< endl;
}

char * ConcatName(char n1[], char n2[])
{
    char name[100] = {0};

    strcpy(name, n1);
    strcat(name," ");
    strcat(name, n2);

    return name;
}

//----------------------------------------------------------------------
void student::setID(int id)
{
    ID = id;
}

int student::getID()
{
    return ID;
}

void student::setName(char name[])
{
    delete (Name);
    Name = new char[strlen(name)+1];
    strcpy(Name, name);
}

char * student::getName()
{
    return Name;
}

void student::setGrade(int grade)
{
    Grade = grade;
}

int student::getGrade()
{
    return Grade;
}
//----------------------------------------------------------------------

student student::operator = (student std)
{
    ID = std.ID;
    setName(std.Name);
    Grade = std.Grade;
    return * this;
}

