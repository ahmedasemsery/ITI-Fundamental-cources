#include <stdio.h>
#include <conio.h>

void main (void)
{
	char c;

	clrscr();

	printf("Enter character to print its ASCII>> ");

	scanf("%c", &c);

	printf("Hex %x \n", c);
	printf("Dec %d \n", c);
	printf("Oct %o \n", c);

	printf("Press any button to exit");
	getch();
}