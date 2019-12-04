#include <stdio.h>
#include <stdlib.h>

#include "../headers/gen_mtxsymdd.h"
#include "../headers/mtx_inversepowermethod.h"

#define SIZE 3
#define TOLERANCE 0.0001
#define MAX_ITERATIONS 1000

int main()
{
	// Get the matrix
	double* a = malloc(SIZE * SIZE * sizeof(double));
	gen_mtxsymdd(SIZE, a, 0, 100);

	printf("\nMatrix:\n");
	for (int i=0; i<SIZE; i++)
	{
		for (int j=0; j<SIZE; j++)
		{
			printf("%.3f ", *(a+(i*SIZE)+j));
		}
		printf("\n");
	}

	// Vector of ones for initial guess
	double initial_guess[SIZE];
	for (int i=0; i<SIZE; i++)
	{
		initial_guess[i] = 1;
	}

	// Calculate eigenvalue
	double smallest_eigenvalue = mtx_inversepowermethod(SIZE, a, initial_guess, TOLERANCE, MAX_ITERATIONS);

	// Output
	printf("\nSmallest eigenvalue: %f\n\n", smallest_eigenvalue);

	// Cleanup
	free(a);
	return 0;
}
