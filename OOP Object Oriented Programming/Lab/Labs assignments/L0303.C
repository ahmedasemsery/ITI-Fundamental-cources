#include <stdio.h>
#include <conio.h>

int getPower(int, int);

void main(void)
{
	int n;
	int p;
	int	result;

	clrscr();

	printf("Enter number to get its power>> ");
	scanf("%d", &n);

	do
	{
		printf("Enter positive power>> ");
		scanf("%d", &p);
	}while(p < 0);

	result = getPower(n, p);
	printf("Result = %d \n", result);

	printf("Press any button to exit..");
	getch();


}


int getPower(int n,int p)
{
	if(p == 0)
		return 1;

	if(p == 1)
		return n;

	return n * getPower(n, --p);

}