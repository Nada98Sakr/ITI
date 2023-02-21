#include <stdio.h>
#include <conio.h>

int main()
{
    int arr[10] = {0};
    int i, max, min;

    for(i=0 ; i<5; i++)
    {
	printf("Please Enter %d number: ",i);
	scanf("%d", &arr[i]);
    }

    max = arr[0];
    min = arr[0];

    for(i=1; i<5; i++)
    {
	if(max < arr[i])
	{
	    max = arr[i];
	}
	else{
	    if (min > arr[i])
	    {
		min = arr[i];
	    }
	}
    }

    printf("Max is %d \nMin is %d",max,min);

    getch();
    clrscr();
    return 0;
}