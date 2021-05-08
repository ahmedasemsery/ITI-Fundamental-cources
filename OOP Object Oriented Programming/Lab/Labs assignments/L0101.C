#include <stdio.h>
#include <conio.h>

void main (void)
{
	char   c;
	int    i;
	short  s;
	float  f;
	double d;
	long   l;

	clrscr();

	printf("Enter character>> ");
	scanf("%c", &c);
	printf("character = %c\n", c);
	printf("character = %d \n", c);

	printf("Enter ineger number>> ");
	scanf("%d", &i);
	printf("integer  = %d \n", i);

	printf("Enter short integer number>> ");
	scanf("%d", &s);
	printf("Short num = %hu \n", s);

	printf("Enter float number>> ");
	scanf("%f", &f);
	printf("float  = %f \n", f);

	printf("Enter double number>> ");
	scanf("%lf", &d);
	printf("double = %lf \n", d);


	printf("Press any button to exit..");
	getch();
}

