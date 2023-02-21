#include <iostream.h>
#include <conio.h>

void Swap(int &a, int &b);
inline void Print(int a, int b);

int main()
{
    int x = 3, y = 4;
    Swap(x, y);
    Print(x, y);

    getch();
    clrscr();
    return 0;
}

void Swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

inline void Print(int a, int b)
{
    cout << "The Value of a = " << a << endl;
    cout << "The value of b = " << b << endl;
}