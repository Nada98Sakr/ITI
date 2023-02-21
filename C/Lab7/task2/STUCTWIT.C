#include <stdio.h>
#include <conio.h>
#include <string.h>

struct student
{
    int  ID;
    char name[10];
    int  grade[3];
};

struct student fillStd(void);
void printStd(struct student std, int j);

int main()
{
    struct student std[3];
    int i;

    for(i=0; i<3; i++)
    {
	printf("For student %d:\n",i+1);
	std[i] = fillStd();
        printf("\n");
    }

    for(i=0; i<3; i++)
    {
	printStd(std[i],i+1);
    }

    getch();
    clrscr();
    return 0;
}


struct student fillStd(void)
{
    struct student std;
    int i;

    printf("Please enter student ID: ");
    scanf("%d", &std.ID);
    printf("Please enter student name: ");
    scanf("%s", std.name);

    for(i = 0; i<3; i++)
    {
	printf("please enter grade %d: ",i+1);
	scanf("%d", &std.grade[i]);
    }

    return std;
}

void printStd(struct student std, int j)
{
    int i;
    printf("\n\n\n");
    printf("Student %d info: ",j);
    printf("\n     ID     : %d", std.ID);
    printf("\n     Name   : %s",std.name);

    for (i=0; i<3; i++)
    {
	printf("\n     Grade %d: %d", i+1, std.grade[i]);
    }

}