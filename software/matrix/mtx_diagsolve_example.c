#include <stdio.h>
#include <stdlib.h>
#include "../headers/mtx_diagsolve.h"

int main()
{
	// Matrices and vectors we use
	double A[5][5] = {{3, 0, 0, 0, 0},
					  {0, 6, 0, 0, 0},
				  	  {0, 0, 9, 0, 0},
				      {0, 0, 0, 1, 0},
				      {0, 0, 0, 0, 8}};

	double b[5] = {9, 12, 3, 2, 8};

	double* x = malloc(5 * sizeof(double));

	// Solving diagonal system
	mtx_diagsolve(5, A, b, x);

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
