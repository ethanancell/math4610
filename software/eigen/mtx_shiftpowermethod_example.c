#include <stdio.h>
#include <stdlib.h>

#include "../headers/gen_mtxsymdd.h"
#include "../headers/mtx_inversepowermethod.h"
#include "../headers/mtx_powermethod.h"
#include "../headers/mtx_shiftpowermethod.h"

#define SIZE 3
#define TOLERANCE 0.0001
#define MAX_ITERATIONS 20

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

	// Smallest / largest eigenvalues
	double smallest_eigenvalue = mtx_inversepowermethod(SIZE, a, initial_guess, TOLERANCE, MAX_ITERATIONS);
	double largest_eigenvalue = mtx_powermethod(SIZE, a, initial_guess, TOLERANCE, MAX_ITERATIONS);
	double middle_eigenvalue = mtx_shiftpowermethod(SIZE, a, initial_guess, (largest_eigenvalue + smallest_eigenvalue) / 2.0, TOLERANCE, MAX_ITERATIONS);

	printf("\nSmallest eigenvalue: %f\n", smallest_eigenvalue);
	printf("Middle eigenvalue: %f\n", middle_eigenvalue);
	printf("Largest eigenvalue: %f\n\n", largest_eigenvalue);

	// Cleanup
	free(a);

	return 0;
}
