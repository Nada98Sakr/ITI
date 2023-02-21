#include <iostream.h>
#include <conio.h>

int BoxVol(int l=1, int w=1, int h=1);

int main()
{
    int vol;

    vol = BoxVol(1,2);

    cout << "The volume = " << vol;

    getch();
    clrscr();
    return 0;
}

int BoxVol(int l, int w , int h)
{
    return l*w*h;
}