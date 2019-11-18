#include "../headers/mtx_choleskyfact.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	double aa[3][3] = {{3, 4, 3},
					   {4, 8, 6},
					   {3, 6, 9}};

	// Put into a pointer
	double* a = malloc(9 * sizeof(double));
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			*(a+(i*3)+j) = aa[i][j];
		}
	}

	// Do the factorization
	mtx_choleskyfact(3, a);

	// Print out the result
	printf("\n");
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			printf("%.3f ", *(a+(i*3)+j));
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}
