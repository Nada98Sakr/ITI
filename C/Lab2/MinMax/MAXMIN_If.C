#include <stdio.h>
#include <conio.h>

int main()
{
    int Num1, Num2, Num3, Num4, Num5, Max, Min;

    printf("Please enter first number: ");
    scanf("%d", &Num1);
    printf("Please enter second number: ");
    scanf("%d", &Num2);
    printf("Please enter third number: ");
    scanf("%d", &Num3);
    printf("Please enter fourth number: ");
    scanf("%d", &Num4);
    printf("Please enter fifth number: ");
    scanf("%d", &Num5);

    Max = Num1;
    Min = Num1;
    clrscr();

    if (Num2 > Max){
        Max = Num2;
    }
    if(Num3 > Max){
        Max = Num3;
    }
    if (Num4 > Max){
        Max = Num4;
    }
    if (Num5 > Max){
        Max = Num5;
    }
    if (Min > Num2){
        Min = Num2;
    }
    if(Min > Num3){
        Min = Num3;
    }
    if (Min > Num4){
        Min = Num4;
    }
    if (Min > Num5){
        Min = Num5;
    }

    printf("The maximum number is: %d \nThe min number is: %d",Max,Min);
    getch();
    clrscr();
    return 0;
}