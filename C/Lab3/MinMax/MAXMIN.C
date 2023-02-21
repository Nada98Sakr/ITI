#include <stdio.h>
#include <conio.h>

int main()
{

    int range, i, Num, Max = 0, Min = 0;
    do{
        printf("please enter how many numbers: ");
        scanf("%d",&range);
    }
    while(range <= 0);


    for (i = 1; i<= range ; i++){
        printf("Please enter %d number: ",i);
        scanf("%d",&Num);
        if(Num > Max){
	    Max = Num;
        }
        else{
	    if(Num < Min){
	        Min = Num;
	    }
        }
    }

    printf("\n\nThe Max number = %d and Min number = %d",Max,Min);
    getch();
    clrscr();
    return 0;
}