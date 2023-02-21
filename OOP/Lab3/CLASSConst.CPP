#include <iostream.h>
#include <conio.h>
#include <string.h>


class student
{
    private:
	int   ID;
	char *Name;
	int   Grade;

    public:
	int   getID();
	char* getName();
	int   getGrade();
	void  setID(int id);
	void  setName(char name[]);
	void  setGrade(int grade);

	student()
	{
	    int size = 20;
	    Name  = new char[size];
	    strcpy(Name, "NULL");
	    ID    = 0;
	    Grade = 0;

	}

	student(char name[], int id, int grade)
	{
	    int size = strlen(name)+1;
	    Name  = new char[size];
	    strcpy(Name, name);
	    ID    = id;
	    Grade = grade;
	}

	student(student &std)
	{
	   ID = std.ID;
	   Name = new char[strlen(std.Name)+1];
	   strcpy(Name, std.Name);
	   Grade = std.Grade;
	}

	~student()
	{
	    delete(Name);
	}
};

student fillStd();
void printStd(student std);


int main()
{
    student std = fillStd();
    printStd(std);

    student s("radwa", 2, 10);
    printStd(s);

    student st;



    getch();
    clrscr();
    return 0;
}

void student:: setID(int id)
{
    ID = id;
}

void student:: setName(char name[])
{
    delete(Name);
    Name = new char[strlen(name)+1];
    strcpy(Name, name);
}

void student:: setGrade(int grade)
{
    Grade = grade;
}

int student:: getID()
{
    return ID;
}

char * student:: getName()
{
    return Name;
}

int student:: getGrade()
{
    return Grade;
}


student fillStd()
{
    int grade, id;
    char *name;
    student std;

    cout << "Please enter student ID: ";
    cin >> id;
    std.setID(id);

    cout << "Please enter student name: ";
    cin >> name;
    std.setName(name);

    cout << "please enter grade : ";
    cin >> grade;
    std.setGrade(grade);

    return std;
}

void printStd(student std)
{
    cout << endl << endl << endl;
    cout << "Student " << " info: "<<endl;
    cout << "     ID    : " << std.getID()<<endl;
    cout << "     Name  : " << std.getName()<<endl;
    cout << "     Grade : " << std.getGrade()<<endl;
}