#include <iostream.h>
#include <conio.h>
#include <string.h>


class student
{
    private:
	int  ID;
	char Name[20];
	int  grade;

    public:
	int   getID();
	char* getName();
	int   getGrade();
	void  setID(int id);
	void  setName(char name[]);
	void  setGrade(int g);

};


int main()
{
    student std;
    int id, grade;
    char name[20];

    cout << "Enter std ID:";
    cin  >> id;
    cout << "Enter std Name:";
    cin  >> name;
    cout << "Enter std grade:";
    cin  >> grade;

    std.setID(id);
    std.setName(name);
    std.setGrade(grade);
    cout << endl << "***********" <<endl<<endl;
    cout << "Student ID   : " <<  std.getID() << endl;
    cout << "Student Name : " <<  std.getName() << endl;
    cout << "Student grade: " <<  std.getGrade() << endl;

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
    strcpy(Name, name);
}

void student:: setGrade(int g)
{
    grade = g;
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
    return grade;
}
