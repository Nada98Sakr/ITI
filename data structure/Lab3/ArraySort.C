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
void   BubbleSort();
void   MergeSort(int LB, int UB);
void   Merge(int low, int middle, int high);
void   BinarySearch(int LB, int UB);
void   fillStd(void);
void   printStd(struct student std);
void   PrintAll(void);


int row =1;
int last;

struct student std[size];


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
		       BubbleSort();
		       break;

		   case 2:
		       MergeSort(0,last-1);
		       break;

		   case 3:
		       BinarySearch(0, last-1);
		       break;

		   case 4:
		       fillStd();
		       break;

		   case 5:
		       PrintAll();
		       break;

		   case 6:
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
    printf("1. Bubble Sort by ID");
    gotoxy(1,2);
    printf("2. Merge Sort by Name");
    gotoxy(1,3);
    printf("3. Binary Search by ID");
    gotoxy(1,4);
    printf("4. Fill student");
    gotoxy(1,5);
    printf("5. Print All");
    gotoxy(1,6);
    printf("6. Exit\n");

    gotoxy(1,row);
}


void MoveCrusor(char ch)
{
    switch (ch)
    {
	case 80:
	    if (row == 6)
	    {
		row = 0;
	    }

	    row++;
	    break;

	case 72:
	    if (row == 1)
	    {
		row = 7;
	    }

	    row--;
	    break;

	case 71:
	    row = 1;
	    break;

	case 79:
	    row = 6;
	    break;
    }
    gotoxy(1,row);
}

void fillStd(void)
{
    struct student s;
    int i;

    if (last< size)
    {
	printf("Please enter student ID: ");
	scanf("%d", &s.ID);
	printf("Please enter student name: ");
	scanf("%s", s.Name);

	for(i = 0; i<3; i++)
	{
	    printf("please enter grade %d: ",i+1);
	    scanf("%d", &s.grade[i]);
	}

	std[last] = s;
	last++;
    }
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


void   BubbleSort()
{
    int i,j, flag=1;
    struct student temp;

    for(i=0; (i<last-1) &&flag ; i++)
    {
	flag = 0;
	for(j=0; j<last-i-1; j++)
	{
	    if(std[j].ID > std[j+1].ID)
	    {
		temp = std[j];
		std[j] = std[j+1];
		std[j+1] = temp;
		flag = 1;
	    }
	}
    }

    if (last)
    {
	printf("List Sorted");
    }
    else
    {
	printf("No list to Sort");
    }
}

void   MergeSort(int LB, int UB)
{
    int middle, flag=0;
    if(LB < UB)
    {
	middle = (LB+UB)/2;
	MergeSort(LB, middle);
	MergeSort(middle+1 , UB);
	Merge(LB,middle,UB);
	flag = 1;
    }

    if (flag)
    {
	printf("List Sorted");
    }
    else
    {
	printf("No list to Sort");
    }
}

void   Merge(int low, int middle, int high)
{
    struct student temp[size];
    int list1, list2, i;

    list1 = low;
    list2 = middle+1;
    i = low;

    while((list1<=middle) && (list2 <= high))
    {
	if(strcmp(std[list1].Name, std[list2].Name)<0)
	{
	    temp[i] = std[list1];
	    list1++;
	    i++;
	}

	else
	{
	    temp[i] = std[list2];
	    list2++;
	    i++;
	}
    }

    while(list1 <= middle)
    {
	temp[i] = std[list1];
	list1++;
	i++;
    }

    while(list2 <= high)
    {
	temp[i] = std[list2];
	list2++;
	i++;
    }

    for(i=low; i<=high; i++)
    {
	std[i] = temp[i];
    }
}

void   BinarySearch(int LB, int UB)
{
    int id, middle, loc=-1;

    printf("Enter The ID:");
    scanf("%d", &id);

    while((LB<= UB) && (loc==-1))
    {
	middle = (LB+UB)/2;

	if(std[middle].ID == id)
	{
	    loc = middle;
	}

	else
	{
	    if(std[middle].ID < id)
	    {
		LB = middle + 1;
	    }

	    else
	    {
		UB = middle - 1;
	    }
	}
    }

    if(loc != -1)
    {
	printf("\n\nFound in loc: %d\n", loc);
	printStd(std[middle]);
    }

}


void PrintAll(void)
{
    int i;

    for(i=0; i<last; i++)
    {
	printStd(std[i]);
    }
}
