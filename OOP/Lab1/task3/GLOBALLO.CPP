#include <iostream.h>
#include <conio.h>

int x;

int main()
{
    int x = 0;

    x++;

    cout << "Global X is  = " << ::x <<endl;
    cout << "Local X is = " << x;

    getch();
    clrscr();
    return 0;
}

int BoxVol(int l, int w , int h)
{
    return l*w*h;
}