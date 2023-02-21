#include <iostream.h>
#include <conio.h>
#include <string.h>


class Person
{
    protected:
	int ID;
	char Name[20];
    public:
	Person()
	{
	    ID = 0;
	    strcpy(Name, "No Name");
	}

	Person(int id, char name[])
	{
	    ID = id;
	    strcpy(Name, name);
	}


	void   setName(char name[]);
	void   setID(int id);
	char * getName();
	int    getID();
};

class Employee :public Person
{
    private:
	int   Salary;

    public:

	Employee()
	{
	    Salary = 0;
	}

	Employee(int id, char name[], int sal):Person(id, name)
	{
	    Salary = sal;
	}

	void  setSalary(int sal);
	int   getSalary();
	friend ostream & operator << (ostream &out, Employee emp);
	friend istream & operator >> (istream &in,  Employee &emp);
};


int main()
{
    Employee emp;
    cout<< endl<<endl;
    cin >> emp;
    cout<< endl<< "----------------------------" << endl<< endl;
    cout<< emp;
    cout<< endl<< "----------------------------" << endl<< endl;

    getch();
    clrscr();
    return 0;
}



void Person:: setID(int id)
{
    ID = id;
}

void Person:: setName(char name[])
{
    strcpy(Name, name);
}

int Person:: getID()
{
    return ID;
}

char * Person:: getName()
{
    return Name;
}

void Employee:: setSalary(int sal)
{
    Salary = sal;
}

int Employee:: getSalary()
{
    return Salary;
}

ostream & operator << (ostream &out, Employee emp)
{
    out<< "Employee ID    :"<< emp.ID<< endl;
    out<< "Employee Name  :"<< emp.Name<< endl;
    out<< "Employee Salary:"<< emp.Salary<< endl;

    return out;
}

istream & operator >> (istream &in,  Employee &emp)
{
    cout<< "Enter Employee ID: ";
    in >> emp.ID;
    cout<< "Enter Employee Name: ";
    in >> emp.Name;
    cout<< "Enter Employee Salary: ";
    in >> emp.Salary;

    return in;
}
