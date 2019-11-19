#include "../headers/mtx_gssolve.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// Set up system of equations
	double aa[3][3] = {{ 5, -2,  3},
					   {-3,  9,  1},
				   	   { 2, -1, -7}};

	double bb[3] = {-1, 2, 3};

	// Initial guess
	double xx[3] = {0, 0, 0};

	double* x = xx;

	// Put them into pointers
	double* a = malloc(9 * sizeof(double));
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			*(a+(i*3)+j) = aa[i][j];
		}
	}
	double* b = malloc(3 * sizeof(double));
	for (int i=0; i<3; i++)
	{
		*(b+i) = bb[i];
	}

	// Do the iteration
	mtx_gssolve(3, a, b, x, 0.00001, 1000);

	// Results
	printf("\n");
	for (int i=0; i<3; i++)
	{
		printf("%.4f\n", *(x+i));
	}
	printf("\n");

	return 0;
}
