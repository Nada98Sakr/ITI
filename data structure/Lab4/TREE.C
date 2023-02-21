#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <string.h>


struct Node
{
    int ID;
    struct Node *pLeft;
    struct Node *pRight;
};


void   Menu(int row);
void   MoveCrusor(char ch);
struct Node * CreateNode(int id);
struct Node * AddNode(struct Node *pNode, int id);
void   InOrder(struct Node * pRoot);
void   PreOrder(struct Node * pRoot);
void   PostOrder(struct Node * pRoot);

int row =1;


int main()
{

    int flag=1, flag2 = 1, id;
    char ch;
    struct Node *PRoot = NULL;

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
		       printf("please Enter ID: ");
		       scanf("%d", &id);
		       PRoot = AddNode(PRoot, id);
		       break;

		   case 2:
		       InOrder(PRoot);
		       break;

		   case 3:
		       PreOrder(PRoot);
		       break;

		   case 4:
		       PostOrder(PRoot);
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
    printf("1. Add Node");
    gotoxy(1,2);
    printf("2. Traverse In order");
    gotoxy(1,3);
    printf("3. Traverse Pre-Order");
    gotoxy(1,4);
    printf("4. Traverse Post-Order");
    gotoxy(1,5);
    printf("5. Exit\n");
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

struct Node * CreateNode(int id)
{
    struct Node *ptr;
    ptr = (struct Node *) malloc(sizeof(struct Node));
    if(ptr)
    {
	ptr->ID = id;
	ptr->pLeft = NULL;
	ptr->pRight = NULL;
    }
    return ptr;
}

struct Node * AddNode(struct Node *pNode, int id)
{

    if(pNode == NULL)
    {
	pNode = CreateNode(id);
    }

    else
    {
	if(pNode->ID >= id)
	{
	    pNode->pLeft = AddNode(pNode->pLeft, id);
	}

	else
	{
	    pNode->pRight = AddNode(pNode->pRight, id);
	}
    }


    return pNode;
}


void InOrder(struct Node * pRoot)
{
    if(pRoot)
    {
       InOrder(pRoot->pLeft);
       printf("%d ",pRoot->ID);
       InOrder(pRoot->pRight);
    }

}

void PreOrder(struct Node * pRoot)
{
    if(pRoot)
    {
       printf("%d ",pRoot->ID);
       PreOrder(pRoot->pLeft);
       PreOrder(pRoot->pRight);
    }
}

void PostOrder(struct Node * pRoot)
{
    if(pRoot)
    {
       PostOrder(pRoot->pLeft);
       PostOrder(pRoot->pRight);
       printf("%d ",pRoot->ID);
    }
}