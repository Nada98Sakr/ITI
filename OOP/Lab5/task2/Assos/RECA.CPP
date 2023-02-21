#include <iostream.h>
#include <conio.h>
#include <math.h>

class point
{
    int X;
    int Y;

    public:
	void setX(int x)
	{
	     X = x;
	}

	void setY(int y)
	{    Y = y;
	}

	int  getX()
	{
	     return X;
	}

	int  getY()
	{
	     return Y;
	}

	point()
	{
	    X = Y = 0;
	}

	point(int x, int y)
	{
	    X = x;
	    Y = y;
	}
};

class Rectangle_A
{
    point *P1;
    point *P2;

    int length;
    int width;

    public:
	Rectangle_A()
	{
	    P1 = P2 = NULL;
	    length = width  = 0;
	}

	Rectangle_A(point *p1, point *p2)
	{
	    P1 = p1;
	    P2 = p2;

	    if ((P1 != NULL) && (P2 != NULL))
	    {
		length = abs(P2->getX() - P1->getX());
		width  = abs(P2->getY() - p2->getY());
	    }
	    else
	    {
		length = width = 0;
	    }
	}

	int Area()
	{
	    return (length*width);
	}

	void setPoint1(point *p)
	{
	    P1 = p;

	    if((P1 != NULL) && (P2 != NULL))
	    {
		length = abs(P2->getX() - P1->getX());
		width  = abs(P2->getY() - P1->getY());
	    }

	    else
	    {
		length = width = 0;
	    }
	}

	void setPoint2(point *p)
	{
	    P2 = p;

	    if((P2 != NULL) && (P2 != NULL))
	    {
		length = abs(P2->getX() - P1->getX());
		width  = abs(P2->getY() - P1->getY());
	    }

	    else
	    {
		length = width = 0;
	    }
	}
};



int main()
{
    point p1(3,5), p2(20,25);
    Rectangle_A R;

    R.setPoint1(&p1);
    R.setPoint2(&p2);

    cout<< R.Area()<< endl;



    getch();
    clrscr();
    return 0;
}