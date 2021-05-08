#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>



/* Point class */
class Point
{
	private:
		int x;
		int y;

	public:
		Point();           // Default constructor
		Point(int);
		Point(int, int);
		~Point();          // Destructor
		Point(Point& p);   // Copy constructor
		/* Setters */
		void setX(int x);
		void setY(int y);
		void setXY(int x, int y);
		/* Getters */
		int getX();
		int getY();
		/* Printing */
		void print();
};


Point :: Point()
{
	x = 0;
	y = 0;
//	cout << "Point class default constuctor" << endl;
}

Point :: Point(int xy)
{
	x = y = xy;
//	cout << "Point constructor with one parameters" << endl;
}

Point :: Point(int x, int y)
{
	this -> x = x;
	this -> y = y;

	// cout << "Point constructor with two parameters" << endl;
}

Point :: Point(Point& p)
{
	this -> x = p.x;
	this -> y = p.y;

   //	cout << "Point copy constructor" << endl;
}

Point :: ~Point()
{
   //	cout << "Point destructor" << endl;
}

void Point :: setX(int x)
{
	this -> x = x;
}

void Point :: setY(int y)
{
	this -> y = y;
}
void Point :: setXY(int x, int y)
{
	this -> x = x;
	this -> y = y;
}
int Point :: getX()
{
	return x;
}
int Point :: getY()
{
	return y;
}

void Point :: print()
{
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
}




class Line
{
	private:
		Point start, end;

	public:
		Line();
		Line(int x1, int y1, int x2, int y2);
		~Line();
		void print();
};


Line :: Line()
{
	start.setXY(0, 0);
	end.setXY(0, 0);

   //	cout << "Line default constructor" << endl;
}

Line :: Line(int x1, int y1, int x2, int y2)
{
	start.setXY(x1, y1);
	end.setXY(x2, y2);

	//cout << "Line constructor with four parameters" << endl;
}

Line :: ~Line()
{
	//cout << "Line destructor" << endl;
}

void Line :: print()
{
	line(start.getX(), start.getY(), end.getX(), end.getY());

//	line(0, 0, 400, 500);

	//cout << "Line data" << endl;
	//start.print();
	//end.print();
}




class Circle
{
	private:
		int rad;
		Point center;

	public:
		Circle();
		Circle(int x, int y, int r);
		~Circle();
		void print();

};


Circle :: Circle()
{
	rad = 0;
	center.setXY(0, 0);

//	cout << "Circle default constructor" << endl;
}



Circle :: Circle(int x, int y, int r)
{
	rad = r;
	center.setXY(x, y);
//	cout << "Circle constructor with parameters" << endl;
}


Circle :: ~Circle()
{
// 	cout << "Circle destructor" << endl;
}


void Circle :: print()
{
	//cout << "Circle data is" << endl;
	//cout << "Radius = " << rad << endl;
	//center.print();
	circle(center.getX(), center.getY(), rad);

}

class Rect
{
	private:
		Point p1;
		Point p2;

	public:
		Rect();
		Rect(int x1, int y1, int x2, int y2);
		~Rect();
		void print();
};


Rect :: Rect()
{
	p1.setXY(0, 0);
	p2.setXY(0, 0);

	//cout << "Rectangle default constructor" << endl;
}



Rect :: Rect(int x1, int y1, int x2, int y2)
{
	p1.setXY(x1, y1);
	p2.setXY(x2, y2);

	//cout << "Rectangle constructor with parameters" << endl;
}


Rect :: ~Rect()
{
	//cout << "Rectangle destructor" << endl;
}

void Rect :: print()
{
	//cout << "Rectangle data is" << endl;
	//p1.print();
	//p2.print();
	rectangle(p1.getX(), p1.getY(), p2.getX(), p2.getY());
}

class Pic
{
	private:
		int nL, nC, nR;

		Line * pL;
		Circle * pC;
		Rect * pR;

	public:
		Pic();
		Pic(int x, int y, int z, Line * l, Circle * c, Rect * r);
		~Pic();
		void print();

};



Pic :: Pic()
{
	nL = nC = nR = 0;
	pL = NULL;
	pC = NULL;
	pR = NULL;
	//cout << "Pic default constructor" << endl;
}

Pic :: Pic(int x, int y, int z, Line * l, Circle * c, Rect * r)
{
	nL = x;
	nC = y;
	nR = z;

	pL = l;
	pC = c;
	pR = r;
	//cout << "Pic constructor with parameters" << endl;
}

Pic :: ~Pic()
{
	//cout << "Pic destructor" << endl;
}

void Pic :: print()
{
	cout << "Picture data" << endl;
	for(int i = 0 ; pL && i < nL ; i++)
	{
		pL[i].print();
	}
	for(i = 0 ; pC && i < nC ; i++)
	{
		pC[i].print();
	}
	for(i = 0 ; pR && i < nR ; i++)
	{
		pR[i].print();
	}
}

int main()
{
	/* request auto detection */
	int gdriver = DETECT, gmode, errorcode;

	/* initialize graphics and local variables */
	initgraph(&gdriver, &gmode, "D://BGI");

	/* read result of initialization */
	errorcode = graphresult();

	/* an error occurred */
	if (errorcode != grOk)
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1);
	}

	setcolor(100);

	clrscr();

	Line larr[2] = {Line(10,20,30,40), Line(30,50,60,20)};
//	larr[0].print();
//	larr[1].print();

	Line l1(20, 20, 200, 200);
//	l1.print();

	Circle c1(450, 150, 40);
	Circle c11(435, 135, 8);
	Circle c12(460, 135, 8);
	c11.print();
	c12.print();
	c1.print();


	Rect rect(410, 190, 490, 300);
	rect.print();

	getch();
	closegraph();
	return 0;
}