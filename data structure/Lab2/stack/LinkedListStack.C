#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <string.h>

struct student
{
    int ID;
    char Name[20];
    int grade[30];
};


struct Node
{
    struct student std;
    struct Node *pNext;
    struct Node *pPrev;
};


void   Menu(int row);
void   MoveCrusor(char ch);
struct student fillStd(void);
void   printStd(struct student std);
struct Node * CreateNode(struct student std);
void   PushNode(void);
void   PopNode(void);
void   PrintAll(void);
void   FreeList(void);


struct Node *pHead;
struct Node *pTail;
int row =1;


int main()
{

    int id, flag=1, flag2 = 1;
    char ch, Name[20];

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
		       PushNode();
		       break;

		   case 2:
		       PopNode();
		       break;

		   case 3:
		       PrintAll();
		       break;

		   case 4:
		       FreeList();
		       break;

		   case 5:
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
    printf("1. Push Node");
    gotoxy(1,2);
    printf("2. Pop Node");
    gotoxy(1,3);
    printf("3. Print All");
    gotoxy(1,4);
    printf("4. Free Node");
    gotoxy(1,5);
    printf("5. Exit\n");

    gotoxy(1,row);
}


void MoveCrusor(char ch)
{
    switch (ch)
    {
	case 80:
	    if (row == 5)
	    {
		row = 0;
	    }

	    row++;
	    break;

	case 72:
	    if (row == 1)
	    {
		row = 6;
	    }

	    row--;
	    break;

	case 71:
	    row = 1;
	    break;

	case 79:
	    row = 5;
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

struct Node *CreateNode(struct student std)
{
    struct Node *ptr;
    ptr = (struct Node *) malloc(sizeof(struct Node));
    if(ptr)
    {
	ptr->std   = std;
	ptr->pNext = NULL;
	ptr->pPrev = NULL;
    }
    return ptr;
}

void PushNode(void)
{
    int retVal = 0;
    struct student std = fillStd();
    struct Node *ptr;
    ptr = CreateNode(std);

    if(ptr)
    {
	retVal = 1;

	if (pHead == NULL)
	{
	    pHead = pTail = ptr;
	}

	else
	{
	    pTail->pNext = ptr;
	    ptr->pPrev = pTail;
	    pTail = ptr;
	}

    }
    if (retVal)
    {
	printf("\nNode Added Successfuly");
    }
}

void PopNode(void)
{
    struct Node *ptr;

    if(pTail != NULL)
    {
	ptr = pTail;
	pTail = pTail->pPrev;
	pTail->pNext =NULL;

	if(pTail == NULL)
	{
	    pHead = NULL;
	}

	printStd(ptr->std);
	free(ptr);
    }

}


void PrintAll(void)
{
    struct Node *ptr;
    ptr = pHead;
    while(ptr)
    {
	printStd(ptr->std);
	ptr = ptr->pNext;
    }
    if(!pHead)
    {
	printf("No Node to print");
    }
}

void FreeList(void)
{
    struct Node *temp;
    temp = pHead;
    while(pHead)
    {
	temp = pHead;
	pHead = pHead->pNext;
	free(temp);
    }
    pTail = NULL;
    printf("List Deleted");

}
