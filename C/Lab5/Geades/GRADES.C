#include <stdio.h>
#include <conio.h>

int main()
{

    float stdGrad[3][4], Avg, sum;
    int row, col;

    for(row=0; row<3; row++)
    {
	printf("For Student %d :\n", row+1);
	for(col=0; col<4; col++)
	{
	    printf("    Enter Grade %d: ",col+1);
	    scanf("%f", &stdGrad[row][col]);
	}
	printf("\n");
    }

    printf("\n");


    for(row=0; row<3; row++)
    {
	Avg = 0;
	for(col=0; col<4; col++)
	{
	    Avg += stdGrad[row][col];
	}

	Avg = Avg/4;
	printf("The average of Student %d = %0.2f\n",row+1 ,Avg);
    }

    printf("\n\n");

    for(col=0; col<4; col++)
    {
	sum = 0;
	for(row=0; row<3; row++)
	{
	    sum += stdGrad[row][col];
	}
	printf("The sum of Subject %d = %0.2f\n",row+1 ,sum);
    }

    getch();
    clrscr();
    return 0;


}

