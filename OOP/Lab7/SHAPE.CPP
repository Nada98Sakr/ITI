#include <iostream.h>
#include <conio.h>
#include <string.h>

class shape
{
    protected:
	int dim1, dim2;

    public:
	void  setDim1(int d1);
	void  setDim2(int d2);
	int   getDim1();
	int   getDim2();

	shape()
	{
	    dim1 = dim2 = 0;
	}

	shape(int d)
	{
	    dim1 = dim2 = d;
	}

	shape(int d1, int d2)
	{
	    dim1 = d1;
	    dim2 = d2;
	}

	virtual float Area() = 0;
};

class Circule: public shape
{
    public:
	Circule()
	{}

	Circule(int r): shape(r)
	{}

	float Area()
	{
	    return (3.14* dim1* dim2);
	}
};

class Rectangle: public shape
{
    public:
	Rectangle()
	{}

	Rectangle(int d1, int d2): shape(d1, d2)
	{}

	float Area()
	{
	    return (dim1 *dim2);
	}
};

class Triangle: public shape
{
    public:
	Triangle()
	{}

	Triangle(int h, int b): shape(h, b)
	{}

	float Area()
	{
	    return (0.5* dim1* dim2);
	}
};

class Square: public Rectangle
{
    public:
	Square()
	{}

	Square(int s): Rectangle(s,s)
	{}
};

class GeoShape
{
    shape ** ptr;
    int size;

    public:
	GeoShape(shape **p, int s)
	{
	    ptr  = p;
	    size = s;
	}

	float TotalArea()
	{
	    float area = 0;

	    for(int i = 0; i<size ; i++)
	    {
		area += ptr[i]->Area();
	    }
	    return area;
	}

};


int main()
{
    Circule   c(7);
    Rectangle R(20, 5);
    Triangle  T(10, 20);
    Square    S(6);

    shape * myShapes[] = {&c, &R, &T, &S};

    GeoShape G(myShapes, 4);
    cout<< "Total area = "<< G.TotalArea();

    getch();
    clrscr();
    return 0;
}


void shape::setDim1(int d1)
{
    dim1 = d1;
}

void shape::setDim2(int d2)
{
    dim2 = d2;
}

int shape::getDim1()
{
    return dim1;
}

int shape::getDim2()
{
    return dim2;
}