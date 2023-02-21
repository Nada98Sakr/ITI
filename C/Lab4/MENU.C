#include <stdio.h>
#include <conio.h>


void Menu(int row);
void Add();
void Sub();
void Mul();
void Div();


int main()
{

    int ch, row=1, flag=1, flag2 = 1;
    Menu(row);
    do{
       ch = getch();

       if (ch == 0){
           ch = getch();
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

       else{
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
		       Add();
		       break;

	           case 2:
		       Sub();
		       break;

	           case 3:
		       Mul();
		       break;

	           case 4:
		       Div();
		       break;

	           case 5:
		       flag = 0;
	    	       break;
	       }
	       printf("\nDo you want to return to menu press - if not press ESC:");
	       flag2 = getch();
	       if (flag2 == 45){
	           Menu(row);
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
    printf("1. ADD");
    gotoxy(1,2);
    printf("2. Subtract");
    gotoxy(1,3);
    printf("3. Multiply");
    gotoxy(1,4);
    printf("4. Division");
    gotoxy(1,5);
    printf("5. Exit\n");
    gotoxy(1,row);
}



void Add()
{
    float Num1, Num2, Result;
    printf("Please enter first number: ");
    scanf("%f",&Num1);
    printf("Please enter second number: ");
    scanf("%f",&Num2);

    Result = Num1 + Num2;
    printf("The Sum of %f and %f = %f",Num1, Num2, Result);

}

void Sub()
{
    float Num1, Num2,Result;
    printf("Please enter first number: ");
    scanf("%f",&Num1);
    printf("Please enter second number: ");
    scanf("%f",&Num2);

    Result = Num1 - Num2;
    printf("The difference of %f and %f = %f",Num1, Num2, Result);

}

void Mul()
{
    float Num1, Num2,Result;
    printf("Please enter first number: ");
    scanf("%f",&Num1);
    printf("Please enter second number: ");
    scanf("%f",&Num2);

    Result = Num1 * Num2;
    printf("The product of %f and %f = %f",Num1, Num2, Result);

}

void Div()
{
    float Num1, Num2,Result;
    printf("Please enter first number: ");
    scanf("%f",&Num1);
    printf("Please enter second number: ");
    scanf("%f",&Num2);

    Result = Num1 / Num2;
    printf("The quotient of %f and %f = %f",Num1, Num2, Result);
}