#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct employee
{
int code;
char name[40];
double sal;
double bonus;
double netsal;
}emp;

emp readEmp(void);
void displayEmp(emp);





void main(void)
{
	int cnt;
	int i;

	emp * sptr;

	clrscr();

	printf("Enter employees count that will be entered>>");
	scanf("%d", &cnt);

	sptr = malloc(cnt * sizeof(emp));

	for(i = 0 ; i < cnt ; i++)
	{
		printf("\n\n Enter Employee #%d data..\n", (i+1));

		*(sptr + i) = readEmp();

		clrscr();
	}


	for(i = 0 ; i < cnt ; i++)
	{
		printf("\n\nEmployee %d data is:\n", (i+1));
		displayEmp(*(sptr + i));
	}

	free(sptr);

	printf("\n Press any button to exit..");
	getch();
}




emp readEmp(void)
{

	emp temp;

	printf("Enter code>>");
	flushall();
	scanf("%d", &temp.code);

	printf("Enter name>>");
	flushall();

	gets(temp.name);

	printf("Enter salary>>");
	flushall();
	scanf("%lf", &temp.sal);

	printf("Enter bonus>>");
	flushall();
	scanf("%lf", &temp.bonus);


	return temp;
}


void displayEmp(emp e)
{
	printf("Code: %d \n", e.code);
	printf("Name : %s \n", e.name);
	printf("Net salary = %lf \n", (e.sal + e.bonus));
}


