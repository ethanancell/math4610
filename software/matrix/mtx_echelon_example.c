#include <stdio.h>
#include <stdlib.h>
#include "../headers/mtx_echelon.h"

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
	mtx_echelon(3, AA, bb);

	// Print result
	printf("\nResult from Gaussian elimination:\n");
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			printf("%.4f ", *(AA+(i*3)+j));
		}
		printf("\n");
	}
	printf("(Only upper triangular components of matrix should be examined)\n\n");

	free(AA);
	free(bb);

	return 0;
}
