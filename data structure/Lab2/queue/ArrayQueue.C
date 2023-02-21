#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <string.h>

#define size 10

struct student
{
    int ID;
    char Name[20];
    int grade[30];
};


void   Menu(int row);
void   MoveCrusor(char ch);
struct student fillStd(void);
void   printStd(struct student std);
void   Push(void);
void   Pop(void);
void   PrintAll(void);


int row =1;

struct student std[size];

int first, last;

int main()
{

    int flag=1, flag2 = 1;
    char ch;

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
		       Push();
		       break;

		   case 2:
		       Pop();
		       break;

		   case 3:
		       PrintAll();
		       break;

		   case 4:
		       flag = 0;
		       break;
	       }

	       if (flag)
	       {
		   printf("\n\nDo you want to return to menu press - if not press ESC:");
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
    return 0;
}



void Menu(int row)
{
    clrscr();
    gotoxy(1,1);
    printf("1. Push");
    gotoxy(1,2);
    printf("2. Pop");
    gotoxy(1,3);
    printf("3. Print All");
    gotoxy(1,4);
    printf("4. Exit\n");

    gotoxy(1,row);
}


void MoveCrusor(char ch)
{
    switch (ch)
    {
	case 80:
	    if (row == 4)
	    {
		row = 0;
	    }

	    row++;
	    break;

	case 72:
	    if (row == 1)
	    {
		row = 5;
	    }

	    row--;
	    break;

	case 71:
	    row = 1;
	    break;

	case 79:
	    row = 4;
	    break;
    }
    gotoxy(1,row);
}

struct student fillStd(void)
{
    struct student std;
    int i;

    printf("Please enter student ID: ");
    scanf("%d", &std.ID);
    printf("Please enter student name: ");
    scanf("%s", std.Name);

    for(i = 0; i<3; i++)
    {
	printf("please enter grade %d: ",i+1);
	scanf("%d", &std.grade[i]);
    }

    return std;
}

void printStd(struct student std)
{
    int i;
    printf("\n\n\n");
    printf("Student info: ");
    printf("\n     ID     : %d", std.ID);
    printf("\n     Name   : %s",std.Name);

    for (i=0; i<3; i++)
    {
	printf("\n     Grade %d: %d", i+1, std.grade[i]);
    }

}

void Push(void)
{
    if(last < size)
    {
	struct student s = fillStd();
	std[last] = s;
	last++;
	printf("\nStudent Added Successfuly");

    }
    else
    {
	printf("\nOut of Range");
    }
}

void Pop(void)
{
    int i;

    if(first <= last)
    {
	printStd(std[first]);
	while(first < last)
	{
	    std[first] = std[first+1];
	    first++;
	}

	first = 0;
        last--;
    }
    else
    {
	printf("No data");
    }

}


void PrintAll(void)
{
    int i;

    for(i=first; i<last; i++)
    {
	printStd(std[i]);
    }
}
