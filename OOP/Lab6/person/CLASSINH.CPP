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
	void  setSalary(int sal);
	int   getSalary();

	Employee()
	{
	    Salary = 0;
	}

	Employee(int id, char name[], int sal):Person(id, name)
	{
	    Salary = sal;
	}
};


class Customer :public Person
{
    private:
	char phone[12];

    public:
	Customer()
	{
	    strcpy(phone ,"0");
	}

	Customer(int id, char name[], char ph[]):Person(id, name)
	{
	    strcpy(phone, ph);
	}

	void   setPhone(char ph[]);
	char * getPhone();
};


int main()
{
    Employee emp(20, "Nada", 10000);
    cout<< "Employee ID    :"<< emp.getID()<< endl;
    cout<< "Employee Name  :"<< emp.getName()<< endl;
    cout<< "Employee Salary:"<< emp.getSalary()<< endl;
    cout<< endl<< "--------------------------" << endl<<endl;
    Customer c(20, "Nada", "01096233063");
    cout<< "Customer ID   :"<< c.getID()<< endl;
    cout<< "Customer Name :"<< c.getName()<< endl;
    cout<< "Customer phone:"<< c.getPhone()<< endl;
    cout<< endl<< "--------------------------" << endl<<endl;

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

void Customer::setPhone(char ph[])
{
    strcpy(phone, ph);
}
char * Customer::getPhone()
{
    return phone;
}
