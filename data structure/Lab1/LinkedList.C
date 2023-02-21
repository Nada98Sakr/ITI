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
    struct Node *pPrev;
    struct Node *pNext;
};


void   Menu(int row);
void   MoveCrusor(char ch);
struct student fillStd(void);
void   printStd(struct student std);
struct Node * CreateNode(struct student std);
int    AddNode(void);
int    InsertNode(void);
struct Node * SearchById(int id);
struct Node * SearchByName(char Name[]);
void   DeleteNode(void);
void   PrintAll(void);
void   FreeList(void);


struct Node *pHead;
struct Node *pTail;
int row =1;


int main()
{

    int id, flag=1, flag2 = 1, retVal = 0;
    char ch, Name[20];
    struct Node * ptr = NULL;

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
		       retVal = AddNode();
		       if(retVal)
		       {
			   printf("\nNode Added Successfuly");
		       }
		       break;

		   case 2:
		       retVal = InsertNode();
		       if(retVal)
		       {
			   printf("\nNode inserted Successfuly");
		       }
		       break;

		   case 3:
		       printf("Please Enter student id: ");
		       scanf("%d",&id);
		       ptr = SearchById(id);

		       if (ptr == NULL)
		       {
			   printf("\n\nNo match");
		       }

		       else
		       {
			   printStd(ptr->std);
		       }

		       break;

		   case 4:
		       printf("Enter student name:");
		       scanf("%s", Name);
		       ptr = SearchByName(Name);

		       if (ptr == NULL)
		       {
			   printf("\n\nNo match");
		       }

		       else
		       {
			   printStd(ptr->std);
		       }

		       break;

		   case 5:
		       DeleteNode();
		       break;

		   case 6:
		       PrintAll();
		       break;

		   case 7:
		       FreeList();
		       break;

		   case 8:
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
    printf("1. Add Node");
    gotoxy(1,2);
    printf("2. Insert Node");
    gotoxy(1,3);
    printf("3. Search by student ID");
    gotoxy(1,4);
    printf("4. Search by student Name");
    gotoxy(1,5);
    printf("5. Delete Node");
    gotoxy(1,6);
    printf("6. Print All");
    gotoxy(1,7);
    printf("7. Free Node");
    gotoxy(1,8);
    printf("8. Exit\n");
    gotoxy(1,row);
}


void MoveCrusor(char ch)
{
    switch (ch)
    {
	case 80:
	    if (row == 8)
	    {
		row = 0;
	    }

	    row++;
	    break;

	case 72:
	    if (row == 1)
	    {
		row = 9;
	    }

	    row--;
	    break;

	case 71:
	    row = 1;
	    break;

	case 79:
	    row = 8;
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
	ptr->std = std;
	ptr->pPrev = NULL;
	ptr->pNext = NULL;
    }
    return ptr;
}

int AddNode(void)
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
    return retVal;
}

int InsertNode(void)
{
    int retVal = 0, loc, i;
    struct student std = fillStd();
    struct Node *ptr, *pCur;

    ptr = CreateNode(std);
    printf("Please enter the location: ");
    scanf("%d", &loc);

    if(ptr)
    {
	retVal = 1;
	if (pHead == NULL)
	{
	    pHead = pTail = ptr;
	}

	else
	{
	    if(loc == 0)
	    {
		ptr->pNext = pHead;
		pHead->pPrev = ptr;
		pHead = ptr;
	    }

	    else
	    {
		pCur = pHead;

		for(i=0; i<(loc-1)&&pCur; i++)
		{
		    pCur = pCur->pNext;
		}

		if((pCur == pTail) || (pCur == NULL))
		{
		    pTail->pNext = ptr;
		    ptr->pPrev = pTail;
		    pTail = ptr;
		}
		else
		{
		    pCur->pNext->pPrev = ptr;
		    ptr->pNext = pCur->pNext;
		    ptr->pPrev = pCur;
		    pCur->pNext= ptr;
		}
	    }
	}
    }
    return retVal;
}

struct Node * SearchById(int id)
{

    struct Node *ptr;

    ptr = pHead;

    while((ptr->std.ID != id) && ptr)
    {
	ptr = ptr->pNext;
    }

    return ptr;
}

struct Node * SearchByName(char Name[])
{
    struct Node *ptr;
    int match;

    ptr = pHead;
    while((match != 0)&& ptr)
    {
	match = strcmp(ptr->std.Name,Name);
	if(match != 0)
	{
	    ptr = ptr->pNext;
	}
    }

    return ptr;
}

void DeleteNode(void)
{
    int loc,i;
    struct Node *ptr;

    printf("Please Enter the location: ");
    scanf("%d", &loc);

    if(pHead)
    {
	ptr = pHead;
	if(loc == 0)
	{
	    if(pHead == pTail)
	    {
		pTail = pHead = NULL;
	    }

	    else
	    {
		pHead->pNext->pPrev = NULL;
		pHead = pHead->pNext;
	    }

	    free(ptr);
	    printf("Node deleted");
	}

	else
	{
	    for(i=0; (i<loc)&&ptr; i++)
	    {
		ptr = ptr->pNext;
	    }

	    if(ptr)
	    {
		if(ptr == pTail)
		{
		    pTail = ptr->pPrev;
		    pTail->pNext = NULL;
		}

		else
		{
		    ptr->pNext->pPrev = ptr->pPrev;
		    ptr->pPrev->pNext = ptr->pNext;
		}

		free(ptr);
		printf("Node deleted");
	    }
	    else
	    {
		printf("Node not found");
	    }
	}
    }

    else
    {
	printf("List is already empty");
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
