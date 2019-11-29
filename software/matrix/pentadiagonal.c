#include <stdio.h>
#include <stdlib.h>

#include "../headers/mtx_pentadiagonal_multiply.h"

int main()
{
	double a[7][7] = {{1, 2, 3, 0, 0, 0, 0},
					  {3, 4, 5, 4, 0, 0, 0},
				  	  {6, 6, 7, 8, 1, 0, 0},
				  	  {0, 9, 9, 1, 2, 3, 0},
				  	  {0, 0, 7, 3, 4, 5, 9},
				  	  {0, 0, 0, 1, 6, 7, 8},
				  	  {0, 0, 0, 0, 2, 9, 1}};

	// Create the vectors
	double ad[7];
	for (int i=0; i<7; i++)
	{
		ad[i] = a[i][i];
	}

	double au[7];
	for (int i=0; i<6; i++)
	{
		au[i] = a[i][i+1];
	}
	au[6] = 0;

	double auu[7];
	for (int i=0; i<5; i++)
	{
		auu[i] = a[i][i+2];
	}
	auu[5] = 0;
	auu[6] = 0;

	double al[7];
	al[0] = 0;
	for (int i=0; i<6; i++)
	{
		al[i+1] = a[i+1][i];
	}

	double all[7];
	all[0] = 0;
	all[1] = 0;
	for (int i=0; i<5; i++)
	{
		all[i+2] = a[i+2][i];
	}

	// The x-vector
	double x[7];
	for (int i=0; i<7; i++)
	{
		x[i] = 1;
	}

	// Multiply
	double* y = malloc(7 * sizeof(double));
	mtx_pentadiagonal_multiply(7, auu, au, ad, al, all, x, y);

	// Print solution
	printf("\nResult from multiplication:\n");
	for (int i=0; i<7; i++)
	{
		printf("%.3f ", *(y+i));
	}
	printf("\n\n");

	free(y);
	return 0;
}
