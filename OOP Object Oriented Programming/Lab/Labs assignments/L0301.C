
#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct employee
{
	int code;
	char name[20];
	double salary;
	double bonus;
	double netsal;
}emp;

void menuDisplay(void);
emp readEmp(void);
void displayEmp(emp);



void main(void)
{
	emp e;
	int choice;

	e.salary = 0;

	do
	{
		clrscr();

		menuDisplay();

		choice = getch();

		switch(choice)
		{
			case '1':
			e = readEmp();
			break;

			case '2':
			if(e.salary == 0)
			{
				printf("No entered employees to display!");
				getch();
				break;
			}
			displayEmp(e);
			getch();
			break;


			case '3':
																											return;
		}
	}while(1);

}




void menuDisplay(void)
{
	gotoxy(50, 2);
	printf("Service table \n");

	gotoxy(50, 3);
	printf("1. Enter employee data \n");

	gotoxy(50, 4);
	printf("2. Display employee data \n");

	gotoxy(50, 5);
	printf("3. Exit \n");

	gotoxy(0, 3);
}



emp readEmp(void)
{
	emp temp;

	printf("Enter Employee data: \n\n");
	printf("Enter employee code>>");
	scanf("%d", &temp.code);

	printf("Enter employee name>>");
	flushall();
	gets(temp.name);

	printf("Enter employee salary>>");
	scanf("%lf", &temp.salary);

	printf("Enter employee bonus>>");
	scanf("%lf", &temp.bonus);

	return temp;
}


void displayEmp(emp e)
{
	printf("Employee data \n");
	printf("Code: %d \n", e.code);
	printf("Name: %s \n", e.name);
	printf("Net salary = %lf \n", (e.salary + e.bonus));
}
