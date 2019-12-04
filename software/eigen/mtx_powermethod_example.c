#include <stdio.h>
#include <stdlib.h>

#include "../headers/gen_mtxsymdd.h"
#include "../headers/mtx_powermethod.h"

#define SIZE 3
#define TOLERANCE 0.0001
#define MAX_ITERATIONS 1000

int main()
{
	// Get the matrix
	double* a = malloc(SIZE * SIZE * sizeof(double));
	gen_mtxsymdd(SIZE, a, 0, 100);

	// Vector of ones for initial guess
	double initial_guess[SIZE];
	for (int i=0; i<SIZE; i++)
	{
		initial_guess[i] = 1;
	}

	// Calculate eigenvalue
	double largest_eigenvalue = mtx_powermethod(SIZE, a, initial_guess, TOLERANCE, MAX_ITERATIONS);

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
	printf("\nLargest eigenvalue: %f\n\n", largest_eigenvalue);

	// Cleanup
	free(a);
	return 0;
}
