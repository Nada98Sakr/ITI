#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    float a ,b ,c , x1, x2, rootValue,real,complex;

    printf("Please enter first coeff: ");
    scanf("%f", &a);
    printf("Please enter second coeff: ");
    scanf("%f", &b);
    printf("Please enter third coeff: ");
    scanf("%f", &c);
    rootValue = (b*b) - (4*a*c);

    if (rootValue > 0){
        x1 = ((-b + sqrt(rootValue)) / (2*a));
        x2 = ((-b - sqrt(rootValue)) / (2*a));
        printf("X1 = %f \nX2 = %f",x1,x2);
    }
    else{
        if (rootValue == 0){
	    x1 = x2 = (-b) / (2*a);
	    printf("X1 = %f \nX2 = %f",x1,x2);
        }
        else{
	    real = (-b)/(2*a);
	    complex = sqrt(abs(rootValue)) / (2*a);
	    printf("X1 = %f + j%f \nX2 = %f - j%f",real,complex,real,complex);
        }
    }

    getch();
    clrscr();
    return 0;
}