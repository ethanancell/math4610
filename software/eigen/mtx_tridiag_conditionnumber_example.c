#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#include "../headers/gen_mtxsymdd.h"
#include "../headers/mtx_tridiag_powermethod.h"
#include "../headers/mtx_tridiag_inversepowermethod.h"
#include "../headers/mtx_tridiag_conditionnumber.h"

#define TOLERANCE 0.00001
#define MAX_ITERATIONS 500

int main()
{
	int size = 5;

	// Get the space for the symmetric / diagonally dominant matrix
	double* a = malloc(size * size * sizeof(double));

	// Get the space for upper, diagonal, and lower of the matrix
	double* au = malloc(size * sizeof(double));
	double* ad = malloc(size * sizeof(double));
	double* al = malloc(size * sizeof(double));

	// Assert stuff
	if (a == NULL) {
		printf("Allocation of matrix A failed.\n");
		return 0;
	}
	if (au == NULL) {
		printf("Allocation of upper diagonal of A failed.\n");
		return 0;
	}
	if (ad == NULL) {
		printf("Allocation of diagonal of A failed.\n");
		return 0;
	}
	if (al == NULL) {
		printf("Allocation of lower diagonal of A failed.\n");
		return 0;
	}

	// Fill in the matrix with symmetric and diagonally dominant
	gen_mtxsymdd(size, a, 0, 100);

	// Fill out the diagonals from this generated matrix
	for (int i=0; i<size; i++)
	{
		*(ad+i) = *(a+(i*size)+i);
	}

	*(au+size-1) = 0;
	for (int i=0; i<size-1; i++)
	{
		*(au+i) = *(a+(i*size)+i+1);
	}

	*al = 0;
	for (int i=0; i<size-1; i++)
	{
		*(al+i+1) = *(a+((i+1) * size) + i);
	}

	// Fill the matrix with zeroes
	for (int i=0; i<size*size; i++)
	{
		*(a+i) = 0;
	}
	// Refill with tridiagonal
	for (int i=0; i<size; i++)
	{
		*(a+(i*size)+i) = *(ad+i);
	}
	for (int i=0; i<size-1; i++)
	{
		*(a+(i*size)+i+1) = *(au+i);
	}
	for (int i=0; i<size-1; i++)
	{
		*(a+((i+1) * size) + i) = *(al+i+1) ;
	}

	// Vector of ones
	double ones[size];
	for (int i=0; i<size; i++)
	{
		ones[i] = 1;
	}

	// Print matrix
	printf("\nMatrix:\n");
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
		{
			printf("%.3f ", *(a+(i*size)+j));
		}
		printf("\n");
	}

	// Get eigenvalue
	double cn = mtx_tridiag_conditionnumber(size, au, ad, al, TOLERANCE, MAX_ITERATIONS);

	printf("Condition Number: %f\n\n", cn);

	free(a);
	free(au);
	free(ad);
	free(al);

	return 0;
}
