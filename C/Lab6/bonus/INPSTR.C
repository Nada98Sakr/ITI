#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <alloc.h>

void ExtendedKey(char ch, int end);
void ControlKey(char ch, char *ptr);
void EditText(char *ptr, int col);


int col = 1;

int main()
{
    int flag = 1, len, i=0;
    char ch, *ptr;

    printf("Please Enter the size of words: ");
    scanf("%d", &len);
    len += 1;

    ptr = (char *)malloc(len * sizeof(char));

    for(i=0; i <= len; i++)
    {
	ptr[i] = 0;
    }

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
		ExtendedKey(ch , strlen(ptr)+1);
	    }

	    else
	    {

	       if(isprint(ch))
	       {
		   if(col < len)
		   {
		       printf("%c" ,ch);
		       ptr[col-1] = ch;
		       col++;
		   }
	       }
	       else{
		   ControlKey(ch,ptr);
	       }
	    }
	}

	if (ch == 13)
	{
	    if(ptr != NULL)
	    {
		printf("\n\nYou typed:\n%s", ptr);
		flag = 0;
	    }
	}
    }
    while(flag);

    free(ptr);
    getch();
    clrscr();
    return 0;
}

void ExtendedKey(char ch, int end)
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

    gotoxy(col,3);
}

void ControlKey(char ch, char *ptr)
{
    switch(ch)
    {
	case 127:
	    EditText(ptr, col);
	    break;

	case 8:
	    EditText(ptr, col-1);
	    break;
    }
}

void EditText(char *ptr, int col)
{
    int i;
    for(i=col-1; i<strlen(ptr); i++)
    {
	ptr[i]= ptr[i+1];
	gotoxy(i+1,3);
	printf("%c",ptr[i]);

    }

    printf(" ");
    gotoxy(col,3);
}