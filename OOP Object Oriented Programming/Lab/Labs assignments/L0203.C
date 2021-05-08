#include <stdio.h>
#include <conio.h>


void main(void)
{
	int n;
	int cnt = 1;

	int row = 10;
	int col = 30;

	int minR;
	int maxR;
	int minC;
	int maxC;
	int maxCNT;

	do
	{
		clrscr();

		printf("Enter the matrix length (Odd number) >>");
		scanf("%d", &n);
	}while(n % 2 == 0);

	minR = row - (n/2);
	maxR = row + (n/2);
	minC = col - ((n/2)*5);
	maxC = col + ((n/2)*5);
	maxCNT = n * n;

	row = minR;
	gotoxy(col, row);
	printf("%d", cnt);



	while(cnt < maxCNT)
	{
		if(cnt % n != 0)
		{
			row--;
			if(row < minR)
				row = maxR;

			col += 5;
			if(col > maxC)
				col = minC;

			gotoxy(col, row);
			printf("%d", ++cnt);
		}
		else if(cnt % n == 0)
		{
			row++;
			if(row > maxR)
				row = minR;

			gotoxy(col, row);
			printf("%d", ++cnt);
		}
	}


	gotoxy(150, 5);
	printf("\n Press any button to exit..");
	getch();
}