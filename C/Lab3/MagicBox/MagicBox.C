#include <stdio.h>
#include <conio.h>

int main()
{
    int size, i, step, endCol, row=1, col=1;
    do{
        printf("Please enter odd number for the size of magic box: ");
        scanf("%d", &size);
    }
    while ((size%2) == 0);

    col = (size+1)/2;
    gotoxy(col*3,(row*3)+2);
    printf("1");

    for (i=2 ; i <= size*size; i++){
        if((i-1) % size){
	    row--;
	    col--;

	    if (row < 1){
	        row = size;
	    }

	    if (col < 1){
	        col = size;
	    }
        }

        else{
	    row++;
	    if (row > size){
	        row = 1;
	    }
        }
        gotoxy(col*3,(row*3)+2);
        printf("%d",i);
    }

    getch();
    clrscr();
    return 0;
}