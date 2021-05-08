#include <iostream.h>
#include <stdio.h>
#include <conio.h>
//#include <math.h>

double fabs(double);

struct complex
{
	private:
		float real;
		float imag;

	public:
		complex();
		complex(float);
		complex(float r, float i);
		~complex();
		void setReal(float r);
		void setImag(float i);
		float getReal();
		float getImag();
		complex add(complex c);
		complex sub(complex c);
		void print();
};

complex :: complex()
{
	real = imag = 0;
	cout << "\n Default constructor is calling";
}

complex :: complex(float r, float i)
{
	real = r;
	imag = i;
	cout << "\n Constructor with two parameters is calling";
}

complex :: complex(float r)
{
	real = r;
	cout << "\n Constructor with one parameter is calling";
}

complex :: ~complex()
{
	cout << "\n Destructor is calling";
}

void complex :: setReal(float r)
{
	real = r;
}

void complex :: setImag(float i)
{
	imag = i;
}

float complex :: getReal()
{
	return real;
}

float complex :: getImag()
{
	return imag;
}

complex complex :: add(complex c)
{
	complex temp;
	temp.real = real + c.real;
	temp.imag = imag + c.imag;

	return temp;
}

complex complex :: sub(complex c)
{
	complex temp;
	temp.real = real - c.real;
	temp.imag = imag - c.imag;

	return temp;
}

void complex :: print()
{
	if(imag < 0)
	{
		cout << real << " - " << fabs(imag) << "i" << endl;
	}
	else
	{
		cout << real << " + " << imag << "i" << endl;
	}
}






int main()
{
	clrscr();

	complex myComp1;
	complex myComp2(3, 4);
	complex resultComp(5);

	myComp1.setReal(7);
	myComp1.setImag(2);

	resultComp = myComp1.add(myComp2);

	cout << endl;

	resultComp.print();

	resultComp = myComp1.sub(myComp2);

	cout << endl;

	resultComp.print();

	getch();

	return 0;
}




double fabs(double d)
{
	if(d < 0)
		return (d * -1);
	else
		return d;
}
