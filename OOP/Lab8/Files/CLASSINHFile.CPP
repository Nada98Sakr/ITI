#include <iostream.h>
#include <fstream.h>
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
    fstream obj;
    Employee emp;
    cout<< endl<< "---------------TEXT FILE--------------"<<endl;
    cout<< "Enter Employee Info"<< endl;
    cin >> emp;
    cout<< endl<< "--------------------------------------" << endl<< endl;

    obj.open("DEMO.txt", ios::out);
    obj << emp;
    obj.close();

    obj.open("DEMO.txt", ios::in);
    obj >> emp;
    cout<< emp;
    obj.close();

    cout<< endl<< "--------------Binary File-------------" << endl;
    cout<< "Enter employee info"<< endl;
    cin >> emp;
    cout<< endl<< "--------------------------------------" << endl<< endl;

    obj.open("DEMO.bin", ios::binary);
    obj.write((char *) &emp, sizeof(Employee));
    obj.close();

    obj.open("DEMO.bin", ios::binary);
    obj.read((char *) &emp, sizeof(Employee));
    cout<< emp;
    obj.close();

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
    out<< emp.ID <<endl;
    out<< emp.Name <<endl;
    out<< emp.Salary <<endl;

    return out;
}

istream & operator >> (istream &in,  Employee &emp)
{
    //cout<< "Enter Employee ID: ";
    in >> emp.ID;
    //cout<< "Enter Employee Name: ";
    in >> emp.Name;
    //cout<< "Enter Employee Salary: ";
    in >> emp.Salary;

    return in;
}
