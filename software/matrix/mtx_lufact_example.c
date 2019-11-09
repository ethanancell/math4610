#include <stdio.h>
#include <stdlib.h>

#include "../headers/mtx_lufact.h"

int main()
{
	// System we solve
	double A[3][3] = {{9, 3, 4},
				    {4, 3, 3},
			  	    {1, 1, 1}};

	// Function mtx_lufact requires these to be in pointer form.
	// We'll actually pass in these below.
	double* AA = malloc(9 * sizeof(double));
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			*(AA+(i*3)+j) = A[i][j];
		}
	}

	// Now perform LU-factorization
	mtx_lufact(3, AA);

	// Print result
	printf("\nResult from LU factorization:\n");
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			printf("%.4f ", *(AA+(i*3)+j));
		}
		printf("\n");
	}
	printf("Upper triangular part is the U.\n");
	printf("Assuming a diagonal of 1's, the lower triangular part is the L.\n\n");

	free(AA);

	return 0;
}
