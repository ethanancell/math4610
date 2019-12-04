#include <stdio.h>
#include <stdlib.h>

#include "../headers/gen_mtxsymdd.h"
#include "../headers/mtx_conditionnumber.h"

#define SIZE 3
#define TOLERANCE 0.0001
#define MAX_ITERATIONS 1000

int main()
{
	// Get the matrix
	double* a = malloc(SIZE * SIZE * sizeof(double));
	gen_mtxsymdd(SIZE, a, 0, 100);

	// Calculate condition number
	double cn = mtx_conditionnumber(SIZE, a, TOLERANCE, MAX_ITERATIONS);

	// Output
	printf("\nMatrix:\n");
	for (int i=0; i<SIZE; i++)
	{
		for (int j=0; j<SIZE; j++)
		{
			printf("%.3f ", *(a+(i*SIZE)+j));
		}
		printf("\n");
	}
	printf("\nCondition Number: %f\n\n", cn);

	// Cleanup
	free(a);
	return 0;
}
