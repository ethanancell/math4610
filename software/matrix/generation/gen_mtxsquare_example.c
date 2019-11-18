#include <stdio.h>
#include <stdlib.h>
#include "../../headers/gen_mtxsquare.h"

int main()
{
	int n = 4;
	double* a = malloc(n*n * sizeof(double));

	gen_mtxsquare(n, a, -5.5, 35);

	// Print the matrix
	printf("\n");
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			printf("%.3f ", *(a+(i*n)+j));
		}
		printf("\n");
	}
	printf("\n");

	free(a);

	return 0;
}
