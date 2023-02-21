#include <iostream.h>
#include <conio.h>

struct student
{
    int  ID;
    char name[10];
    int  grade[3];
};

student fillStd(void);
void printStd(student std);

int main()
{
    student * ptr;
    int size;

    cout << "Enter Number of students: ";
    cin >> size;
    cout <<endl;

    ptr = new student[size];

    if(ptr)
    {
	for(int i=0; i<size; i++)
	{
	     ptr[i] = fillStd();
	}

	for(i=0; i<size; i++)
	{
	    printStd(ptr[i]);
	}
    }

    getch();
    clrscr();
    return 0;
}


student fillStd(void)
{
    student std;

    cout << "Please enter student ID: ";
    cin >> std.ID;
    cout << "Please enter student name: ";
    cin >> std.name;

    for(int i = 0; i<3; i++)
    {
	cout << "please enter grade "<< i+1 <<":" ;
	cin >> std.grade[i];
    }
    cout << endl;

    return std;
}

void printStd(student std)
{
    cout << endl << endl;
    cout << "Student info: ";
    cout << "\n     ID     :" << std.ID<<endl;
    cout << "\n     Name   : " << std.name<<endl;

    for (int i=0; i<3; i++)
    {
	cout << "    Grade " << i+1 << " : " << std.grade[i];
    }

}