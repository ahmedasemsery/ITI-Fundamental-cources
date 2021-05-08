#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int getRows(void);
int getColumns(void);

int * creatMatrix(int, int);
void displayMatrix(int *, int, int);



void main(void)
{
	int rows;
	int cols;

	int * matrix;
	int temp;

	clrscr();

	rows = getRows();
	cols = getColumns();

	matrix = creatMatrix(rows, cols);


	printf("Press 's' to show matrix..");
	while(getch() != 's');
	printf("\n");

	displayMatrix(matrix, rows, cols);

	free(matrix);

	printf("Press 'e' to exit..");
	while(getch() != 'e');
}




int getRows(void)
{
	int rows;

	clrscr();

	do
	{
		printf("Enter matrix rows (x) positive count>> ");
		scanf("%d", &rows);
	}
	while(rows <= 0);
	return rows;
}

int getColumns(void)
{
	int cols;

	clrscr();

	do
	{
		printf("Enter matrix columns (y) positive count>> ");
		scanf("%d", &cols);
	}
	while(cols <= 0);
	return cols;
}

int * creatMatrix(int rows, int cols)
{
	int x, y;
	int * matrix = (int *) malloc(rows * cols * sizeof(int));

	clrscr();

	printf("--------------------------------------\n");
	printf("--------------( x , y )---------------\n");
	printf("-----------Decimal Numbers only-------\n");

	for(x = 0 ; x < rows ; x++)
	{
		for(y = 0 ; y < cols ; y++)
		{
			int temp;
			do
			{
				printf("Enter element (%d, %d) >> ", x, y);
				scanf("%d", &temp);
			}while(temp < 0);
			*(matrix + x * cols + y) = temp;
		}
	}
	return matrix;
}



void displayMatrix(int * matrix, int rows, int cols)
{
	int x, y;

	clrscr();
	printf("\t");
	for(y = 0 ; y < cols ; y++)
		printf("col%d\t", y);

	printf("Sum \n");

	printf("\t");
	for(y = 0 ; y < cols ; y++)
		printf("----\t");
	printf("---\n");


	for(x = 0 ; x < rows ; x++)
	{
		double sum = 0;

		printf("Row %d\t", x);

		for(y = 0 ; y < cols ; y++)
		{
			printf("%d \t", *(matrix + x * cols + y));
			sum += *(matrix + x * cols + y);
		}

		printf("%.2lf \n\n", sum);
	}

	printf("Avg\t");

	for(y = 0 ; y < cols ; y++)
	{
		double avg = 0;

		for(x = 0 ; x < rows ; x++)
			avg += *(matrix + x * cols + y);

		printf("%.2lf\t", (avg / rows));
	}
	printf("\n\n");

}
