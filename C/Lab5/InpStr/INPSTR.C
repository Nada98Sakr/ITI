#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define len 15

void MoveCursor(char ch, int end);

int col = 1;

int main()
{
    int flag = 1;
    char Arr[len]={0};
    char ch;

    printf("Enter text: \n");

    do
    {
	ch = getch();

	if (ch == 27)
	{
	    flag = 0;
	}
	else
	{
	    if (ch == 0)
	    {
		ch = getch();
		MoveCursor(ch , strlen(Arr)+1);
	    }

	    else
	    {

	       if(isprint(ch))
	       {
		   if(col < len)
		   {
		       Arr[col-1] = ch;
		       printf("%c",ch) ;
		       col++;
		   }
	       }
	    }
	}

	if (ch == 13)
	{
	    printf("\n\nYou typed:\n%s",Arr);
	    flag = 0;
	}
    }
    while(flag);

    getch();
    clrscr();
    return 0;
}

void MoveCursor(char ch, int end)
{
    switch(ch)
    {
	 case 77:
	     if(col == end)
	     {
		 col = 0;
	     }
	     col++;
	     break;

	 case 75:
	     if(col == 1)
	     {
		 col = end+1;
	     }
	     col--;
	     break;

	 case 71:
	     col = 1;
	     break;

	 case 79:
	     col = end;
	     break;
    }

    gotoxy(col,2);
}