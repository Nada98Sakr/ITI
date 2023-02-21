#include<iostream.h>
#include<CONIO.h>
#include<string.h>

class Base{

    protected:
	int z;
    public:
	Base(){

	    z=0;
	}

	Base(int m){

	    z=m;

	}

	void setZ(int m){

	    z=m;
	}

	int getZ(){

	    return z;
	}
};

class Base1:virtual public Base{

    protected:
	int x;
    public:
	Base1(){
	    x=0;
	}

	Base1(int m):Base(m){
	   x=m;
	}

	void setx(int m){
	   x=m;
	}
	int getx(){

	   return x;
	}

};

class Base2:virtual public Base{

    protected:
	int y;
    public:
	Base2()
	{
	   y=0;
	}

	Base2(int m):Base(m)
	{
	   y=m;
	}

	void sety(int m)
	{
	   y=m;
	}
	int gety(){
	   return y;
	}

};

class Derived:public Base1,public Base2{

    public:
	Derived()
	{}

	Derived(int l,int m):Base2(l),Base1(m)
	{}

	int product()
	{
	    return (x*y*z);
	}

	int sum()
	{
	   return (x+y+z);
	}

};

int main(){

    Derived drv(3,4);
    cout<<"Product is: ";
    cout<<drv.product()<<endl;
    cout<<"Sum is: ";
    cout<<drv.sum()<<endl;

    getch();
    clrscr();
    return 0;
}
