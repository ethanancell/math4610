#include <stdio.h>
#include <stdlib.h>
#include "../headers/mtx_lowersolve.h"

int main()
{
	// Matrices and vectors we use
	double A[5][5] = {{3,   0,    0,  0, 0},
					  {6,   6,    0,  0, 0},
				  	  {1,   8.33, 9,  0, 0},
				      {4.5, 6.6,  0,  1, 0},
				      {9.8, 0.32, 4,  7, 8}};

	double b[5] = {4, 8, 3, 4, 8};

	double* x = malloc(5 * sizeof(double));

	// Solving diagonal system
	mtx_lowersolve(5, A, b, x);

	// Print the solution
	printf("\nThe x-vector (solution) is the following:\n<");
	for(int i=0; i<4; i++)
	{
		printf("%.2f, ", *(x+i));
	}
	printf("%.2f>\n\n", *(x+4));

	free(x);
	return 0;
}
