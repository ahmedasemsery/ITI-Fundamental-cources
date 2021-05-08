#include <iostream.h>
#include <stdio.h>
#include <conio.h>

double fabs(double);

class Complex
{
	private:
		float real;
		float imag;

	public:
		/* Constructors */
		Complex();
		Complex(float);
		Complex(float r, float i);
		/* Copy constructor */
		Complex(Complex & c);
		/* Destructor */
		~Complex();

		/* Methods */
		void setReal(float r);
		void setImag(float i);
		float getReal();
		float getImag();

		void setAll();
		void setAll(float f);
		void setAll(float r, float i);

		void print();

		Complex add(Complex c);
		Complex sub(Complex c);

		/* Operators  overloading */
		Complex& operator = (const Complex & c);
		Complex operator + (const Complex & c);
		Complex operator + (float f);
		friend Complex operator + (float f, const Complex & c);

		Complex operator - (const Complex & c);

		int operator == (const Complex & c);

		Complex& operator += (const Complex & c);
		Complex& operator -= (const Complex & c);

		Complex& operator ++();
		Complex operator ++(int dumy);

		operator float ()
		{
			return real;
		}

		friend istream& operator >> (istream& in, Complex & c);
		friend ostream& operator << (ostream& out, Complex & c);
};



/* Constructors */
Complex :: Complex()
{
	real = imag = 0;
	cout << "\n Default constructor is calling" << endl;
}

Complex :: Complex(float r)
{
	real = r;
	cout << "\n Constructor with one parameter is calling" << endl;
//	cout << "The one argument is r = " << r << endl;
}

Complex :: Complex(float r, float i)
{
	real = r;
	imag = i;
	cout << "\n Constructor with two parameters is calling" << endl;
//	cout << "The two arguments are r = " << r << " i = " << i << endl;
}
/* Copy constructor */
Complex :: Complex(Complex & c)
{
	real = c.real;
	imag = c.imag;

	cout << "Copy constructor is calling" << endl;
}
/* Destructor */
Complex :: ~Complex()
{
	cout << "\n Destructor is calling" << endl;
}





/* Operators Overloading implementation */
Complex& Complex :: operator = (const Complex & c)
{

	real = c.real;
	imag = c.imag;

	cout << "Operator = overloading" << endl;

	return *this;
}

Complex Complex :: operator + (const Complex & c)
{
	Complex temp;

	temp.real = real + c.real;
	temp.imag = imag + c.imag;

	cout << "Operator + overloading" << endl;

	return temp;
}

Complex Complex :: operator + (float f)
{
	Complex temp(real + f, imag);

	return temp;
}

Complex operator + (float f, const Complex & c)
{
	Complex temp(f + c.real, c.imag);

	return temp;
}


Complex Complex :: operator - (const Complex & c)
{
	Complex temp;

	temp.real = real - c.real;
	temp.imag = imag - c.imag;

	cout << "Operator - overloading" << endl;

	return temp;
}

int Complex :: operator == (const Complex & c)
{
	if(real == c.real)
		if(imag == c.imag)
			return 1;
	return 0;
}


Complex& Complex :: operator += (const Complex & c)
{
	real += c.real;
	imag += c.imag;

	cout << "Operator += overloading" << endl;

	return *this;
}

Complex& Complex :: operator -= (const Complex & c)
{
	real -= c.real;
	imag -= c.imag;

	cout << "operator -= overloading" << endl;

	return *this;
}


Complex& Complex :: operator ++()
{
	real++;
	imag++;
	return * this;
}

Complex Complex :: operator ++(int dumy)
{
	Complex temp (*this);
	real++;
	imag++;
	if(dumy);
	return temp;
}



istream& operator >> (istream& in, Complex& c)
{
	cout << "\n Enter real part:";
	in >> c.real;
	cout << "Enter imag part";
	in >> c.imag;
	return in;
}

ostream& operator << (ostream& out, Complex& c)
{
	if(c.imag < 0)
		out << c.real << " - " << fabs(c.imag) << "i" << endl;
	else
		out << c.real << " + " << c.imag << "i" << endl;

	return out;
}




void Complex :: setReal(float r)
{
	real = r;
}

void Complex :: setImag(float i)
{
	imag = i;
}

void Complex :: setAll()
{
	real = imag = 0;
}


void Complex :: setAll(float f)
{
	real = imag = f;
}

void Complex :: setAll(float r, float i)
{
	real = r;
	imag = i;
}

float Complex :: getReal()
{
	return real;
}

float Complex :: getImag()
{
	return imag;
}

Complex Complex :: add(Complex c)
{
	Complex temp;
	temp.real = real + c.real;
	temp.imag = imag + c.imag;

	return temp;
}

Complex Complex :: sub(Complex c)
{
	Complex temp;
	temp.real = real - c.real;
	temp.imag = imag - c.imag;

	return temp;
}

void Complex :: print()
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

	Complex c1(3,4);
	Complex c2(3,4);
	Complex c3;

	cin >> c3;
	cout << c3;


	getch();
	clrscr();

	c3 = c1 + c2;
//	c3.print();

	c3 = c1 - c2;
//	c3.print();

	c3 = 5 + c1;
//	c3.print();

	c3 = c1 + 5;
//	c3.print();

	getch();
	clrscr();

	if(c1 == c2)
		cout << "OK" << endl;
	else
		cout << "Not ok" << endl;

	c3 += c2;
//	c3.print();
	c3-= c2;

	getch();
	clrscr();


	c1++;
//	c1.print();

	++c2;

	cout << ++c1;


/*	c1.print();

	Complex c2(c1);
	c2.print();

	Complex c3 = c1;
	c3.print();

	Complex result;
	result = c1 + c2;
	result.print();

	result = result - c1;
	result.print();

	if(result == c1)
		cout << "Result == c1." << endl;

	float r = result;
	cout << "r = " << r;*/

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

	return 0;
}




double fabs(double d)
{
	if(d < 0)
		return (d * -1);
	else
		return d;
}
