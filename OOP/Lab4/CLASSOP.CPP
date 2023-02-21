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
	void  setID(int id);
	int   getID();
	void  setName(char name[]);
	char *getName();
	void  setGrade(int grade);
	int   getGrade();

	student operator +     (student std);
	student operator +     (int d);
	student operator +     (char name[]);
	student operator ++    ();
	student operator ++    (int d);
	student operator =     (student std);
	int     operator ==    (student std);
		operator int   ();
		operator char* ();
	friend  student operator + (int d, student std);
	friend  student operator + (char name[], student std);

	student()
	{
	    ID   = 0;
	    Name = new char[5];
	    strcpy(Name, "NULL");
	    Grade= 0;
	}

	student(int id, char name[], int grade)
	{
	    ID   = id;
	    Name = new char[strlen(name)+1];
	    strcpy(Name, name);
	    Grade= grade;
	}

	student(student &std)
	{
	    ID   = std.ID;
	    Name = new char[strlen(std.Name)+1];
	    strcpy(Name, std.Name);
	    Grade= std.Grade;
	}

	~ student()
	{
	    delete(Name);
	}
};

//----------------------------------------------------------------------

void   Menu(int row);
void   MoveCrusor(char ch);
student fillStd();
void    printStd(student std);
char *  ConcatName(char n1[], char n2[]);
int row = 1;

//----------------------------------------------------------------------
int main()
{
    int flag=1, flag2 = 1;
    char ch;
    student st1 = fillStd(), st2, st3, st;
    clrscr();

    Menu(row);

    do{
       ch = getch();

       if (ch == 0)
       {
	   ch = getch();
	   MoveCrusor(ch);
       }

       else
       {
	   if(ch == 27)
	   {
	       flag = 0;
	   }

	   if (ch == 13)
	   {
	       clrscr();
	       switch(row)
	       {

		   case 1:
		       st2 = st1;
		       cout<<endl << "---------------------------------"<<endl;
		       cout<< "1- ST1: ";
		       printStd(st1);
		       cout<<"---------------------------------"<<endl;

		       cout<< endl;
		       cout<< "   ST2: ";
		       printStd(st2);
		       cout<<"---------------------------------"<<endl;

		       break;

		   case 2:

st3 = st1 + st2;
		       cout<< "---------------------------------"<<endl;
		       cout<< "2- ST1 + ST2: ";
		       printStd(st3);
		       cout<< "---------------------------------"<<endl;
		       break;

		   case 3:
		       st = st + 5;
		       cout<< "---------------------------------"<<endl;
		       cout<< "3- ST + 5: ";
		       printStd(st);
		       cout<< "---------------------------------"<<endl;
		       break;

		   case 4:
		       st = 5 + st;
		       cout<< "---------------------------------"<<endl;
		       cout<< "4- 5 + ST: ";
		       printStd(st);
		       cout<< "---------------------------------"<<endl;
		       break;

		   case 5:
		       st = st1 + "Aly";
		       cout<< "---------------------------------"<<endl;
		       cout<< "5- ST+ Aly: ";
		       printStd(st);
		       cout<< "---------------------------------"<<endl;
		       break;

		   case 6:
		       st = "Ali" + st;
		       cout<< "---------------------------------"<<endl;
		       cout<< "6- Ali + ST: ";
		       printStd(st);
		       cout<< "---------------------------------"<<endl;
		       break;

		   case 7:
		       int x = st1 == st2;
		       cout<< "---------------------------------"<<endl;
		       cout << "7- st1 == st2: "<<endl;
		       if (x==0)
		       {

		   cout<< "   Not equal." << endl;
		       }
		       else
		       {

			   cout<< "   They are equal."<< endl;
		       }
		       cout<<"---------------------------------"<<endl;
		       break;

		   case 8:
		       char *ch = (char *)st;
		       cout<< "---------------------------------"<<endl;
		       cout<< "8- (char*)ST: ";
		       cout << ch <<endl;
		       cout<<"---------------------------------"<<endl;
		       break;

		   case 9:
		       x = (int)st;
		       cout<< "---------------------------------"<<endl;
		       cout<< "9- (int)St: ";
		       cout<< x << endl;
		       cout<<"---------------------------------"<<endl;
		       break;

		   case 10:
		       student s = st++;
		       cout<< "---------------------------------"<<endl;
		       cout<< "10- ST++: ";
		       printStd(s);
		       cout<<"---------------------------------"<<endl;
		       break;


		   case 11:
		       cout<< "---------------------------------"<<endl;
		       cout<< "11- ++ST: ";
		       printStd(++st);
		       cout<<"---------------------------------"<<endl;
		       break;

		   case 12:
		       flag = 0;
		       break;
	       }

	       if (flag)
	       {
		   cout <<"\n\nDo you want to return to menu press - if not press ESC:";
		   flag2 = getch();
		   if (flag2 == 45)
		   {
		       Menu(row);
		   }
	       }
	   }
       }
    }

    while(flag);

    getch();
    clrscr();
    return 0;
}

//----------------------------------------------------------------------

void Menu(int row)
{
    clrscr();
    gotoxy(1,1);
    cout<< "1.  Copy object to another objects.";
    gotoxy(1,2);
    cout<< "2.  Add two objects.";
    gotoxy(1,3);
    cout<< "3.  Add int before object.";
    gotoxy(1,4);
    cout<< "4.  Add int after objects.";
    gotoxy(1,5);
    cout<< "5.  Add string before object.";
    gotoxy(1,6);
    cout<< "6.  Add string after objec.";
    gotoxy(1,7);
    cout<< "7.  check equality of two object.";
    gotoxy(1,8);
    cout<< "8.  return Name";
 
   gotoxy(1,9);
    cout<< "9.  return Grade";

    gotoxy(1,10);
    cout<< "10. Pre-Increment Grade";

    gotoxy(1,11);
    cout<< "11. Post-Increment Grade";
    gotoxy(1,12);
    cout<< "12. Exit\n";

    gotoxy(1,row);
}


void MoveCrusor(char ch)
{
    switch (ch)
    {
	case 80:
	    if (row == 12)
	    {
		row = 0;
	    }

	    row++;
	    break;

	case 72:
	    if (row == 1)
	    {
		row = 13;
	    }

	    row--;
	    break;

	case 71:
	    row = 1;
	    break;

	case 79:
	    row = 12;
	    break;
    }
    gotoxy(1,row);
}


student fillStd()
{
    student std;
    int ID, Grade;
    char Name[20];

    cout << "Enter student ID: ";
    cin  >> ID;
    std.setID(ID);

    cout << "Enter student Name: ";
    cin  >> Name;
    std.setName(Name);

    cout << "Enter student Grade: ";
    cin  >> Grade;
    std.setGrade(Grade);

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
student student::operator + (student std)
{
    char *name = ConcatName(Name, std.Name);
    student temp(ID + std.ID, name, Grade + std.Grade);

    return temp;
}

student student::operator + (int d)
{
    student temp(ID, Name, Grade + d);
    return temp;
}

student student::operator + (char name[])
{
    char *n = ConcatName(Name, name);
    student temp(ID, n, Grade);
    return temp;
}

student student::operator ++()
{
    Grade++;
    return *this;
}

student student::operator ++(int d)
{
    student old(ID, Name, Grade);
    Grade++;

    return old;
}

student student::operator = (student std)
{
    ID = std.ID;
    setName(std.Name);
    Grade = std.Grade;
    return * this;
}

int student::operator == (student std)
{
    return ((ID==std.ID) && !(strcmp(Name, std.Name))  &&(Grade==std.Grade));
}

student::operator int()
{
    return Grade;
}

student::operator char* ()
{
    return Name;
}

student operator + (int d, student std)
{
    student temp(std.ID, std.Name, std.Grade+d);
    return temp;
}

student operator + (char name[],student std)
{
    char *n = ConcatName(name, std.Name);
    student temp(std.ID, n, std.Grade);
    return temp;
}