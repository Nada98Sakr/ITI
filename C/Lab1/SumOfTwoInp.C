#include <stdio.h>
#include <conio.h>

int main()
{

    clrscr();
    int x,y;
    printf("Please enter first number:\n");
    scanf("%d",&x);
    printf("Please enter second number: \n");
    scanf("%d",&y);
    printf("The sum of %d and %d is %d \n", x, y, x+y);
    getch();

    return 0;
}