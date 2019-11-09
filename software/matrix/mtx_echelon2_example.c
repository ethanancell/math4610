#include <stdio.h>
#include <stdlib.h>
#include "../headers/mtx_echelonsolve.h"

int main()
{
	// System we solve
	double A[3][3] = {{9, 3, 4},
				    {4, 3, 3},
			  	    {1, 1, 1}};

	double b[3] = {7, 8, 3};

	// Function mtx_echelon requires these to be in pointer form.
	// We'll actually pass in these below.
	double* AA = malloc(9 * sizeof(double));
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			*(AA+(i*3)+j) = A[i][j];
		}
	}

	double* bb = malloc(3 * sizeof(double));
	for (int i=0; i<3; i++)
	{
		*(bb+i) = b[i];
	}

	// Now perform Gaussian elimination
	double* x = malloc(3 * sizeof(double));
	mtx_echelonsolve(3, AA, bb, x);

	// Print the result
	printf("\nSolution is:\n");
	for(int i=0; i<3; i++)
	{
		printf("%f\n", *(x+i));
	}
	printf("\n");

	free(AA);
	free(bb);
	free(x);

	return 0;
}
