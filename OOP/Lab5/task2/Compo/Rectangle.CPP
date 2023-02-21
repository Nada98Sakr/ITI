#include <iostream.h>
#include <conio.h>
#include <math.h>

class point
{
    int X;
    int Y;

    public:
	void setX(int x);
	void setY(int y);
	int  getX();
	int  getY();

	point(int x, int y)
	{
	    X = x;
	    Y = y;
	}
};

class Rectangle
{
    point p1;
    point p2;
    int length;
    int width;

    public:
	int Area()
	{
	    return length* width;
	}

	Rectangle(int x1, int y1, int x2, int y2):p1(x1, y1), p2(x2, y2)
	{
	    length = abs(x2-x1);
	    width  = abs(y2-y1);
	}
};



int main()
{
    Rectangle R(3,5,20,25);
    cout<< R.Area()<< endl;


    getch();
    clrscr();
    return 0;
}

void point::setX(int x)
{
    X = x;
}

void point::setY(int y)
{
    Y = y;
}

int  point::getX()
{
    return X;
}

int  point::getY()
{
    return Y;
}