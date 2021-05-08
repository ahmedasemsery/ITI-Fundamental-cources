#include <iostream.h>
#include <stdio.h>
#include <conio.h>

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

		complex(complex & c);

		~complex();
		void setReal(float r);
		void setImag(float i);
		float getReal();
		float getImag();

		void stAll();
		void setAll(float f);
		void setAll(float r, float i);

		complex add(complex c);
		complex sub(complex c);

		complex& operator = (complex & const c);

		void print();
};

complex :: complex()
{
	real = imag = 0;
	cout << "Default constructor is calling" << endl;
}

complex :: complex(float r, float i)
{
	real = r;
	imag = i;
	cout << "Constructor with two parameters is calling" << endl;
}

complex :: complex(float r)
{
	real = r;
	cout << "Constructor with one parameter is calling" << endl;
}

/* Copy constructor */
complex :: complex(complex & c)
{
	real = c.real;
	imag = c.imag;

	cout << "Copy constructor is calling" << endl;
}

complex :: ~complex()
{
	cout << "\n Destructor is calling" << endl;
}

complex& complex :: operator = (complex & const c)
{
	real = c.real;
	imag = c.imag;

	return * this;
}

void complex :: setReal(float r)
{
	real = r;
}

void complex :: setImag(float i)
{
	imag = i;
}

void complex :: stAll()
{
	real = imag = 0;
}


void complex :: setAll(float f)
{
	real = imag = f;
}

void complex :: setAll(float r, float i)
{
	real = r;
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

	complex c1(3,4);
	c1.print();

	complex c2(c1);
	c2.print();

	complex c3 = c1;
	c3.print();

	complex * c5 = new complex[7];
	complex c6[10];

	/*
	complex resultComp(5);

	myComp1.setReal(7);
	myComp1.setImag(2);

	complex myComp3(2, 3);
	myComp3.setAll(3);
	myComp3.print();

	resultComp = myComp1.add(myComp2);

	cout << endl;

	resultComp.print();

	resultComp = myComp1.sub(myComp2);

	cout << endl;

	resultComp.print();
	*/

	getch();

	delete [] c5;

	return 0;
}




double fabs(double d)
{
	if(d < 0)
		return (d * -1);
	else
		return d;
}
