#include <iostream.h>
#include <stdio.h>
#include <conio.h>

void swap(int *, int *);
void swap(int &, int &);
void swapByValue(int, int);

void main()
{
	int a = 20, b = 30;

	clrscr();

	cout << "Swapping by reference" << endl;
	cout << "Before swapping:" << endl;
	cout << "a = " << a << " " << "b = " << b << endl;

	swap(a, b);

	cout << "After swapping:" << endl;
	cout << "a = " << a << " " << "b = " << b << endl;

	cout << "----------------------------------------" << endl;

	cout << "Swapping by address" << endl;
	cout << "Before swapping:" << endl;
	cout << "a = " << a << " " << "b = " << b << endl;

	swap(&a, &b);

	cout << "After swapping:" << endl;
	cout << "a = " << a << " " << "b = " << b << endl;

	cout << "----------------------------------------" << endl;

	cout << "Swapping by value" << endl;
	cout << "Before swapping:" << endl;
	cout << "a = " << a << " " << "b = " << b << endl;

	swapByValue(a, b);

	cout << "After swapping:" << endl;
	cout << "a = " << a << " " << "b = " << b << endl;


	getch();
}


/* call by address */
void swap(int * x, int * y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/* call by reference */
void swap(int & x, int & y)
{
	int temp = x;
	x = y;
	y = temp;
}

/* call by value */
void swapByValue(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}