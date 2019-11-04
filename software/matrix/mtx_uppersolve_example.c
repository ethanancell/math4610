#include <stdio.h>
#include <stdlib.h>
#include "../headers/mtx_uppersolve.h"

int main()
{
	// Matrices and vectors we use
	double A[5][5] = {{3, 5, 7, 30, 2},
					  {0, 6, 3, 20, 4},
				  	  {0, 0, 9,  4, 2},
				      {0, 0, 0,  1, 4},
				      {0, 0, 0,  0, 8}};

	double b[5] = {9, 12, 3, 2, 8};

	double* x = malloc(5 * sizeof(double));

	// Solving diagonal system
	mtx_uppersolve(5, A, b, x);

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
