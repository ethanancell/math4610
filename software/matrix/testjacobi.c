#include <stdio.h>
#include <stdlib.h>

#include "../headers/gen_mtxsquare.h"
#include "../headers/gen_mtxsym.h"
#include "../headers/gen_mtxdd.h"
#include "../headers/gen_mtxsymdd.h"
#include "../headers/mtx_lufactsolve.h"
#include "../headers/mtx_jacobisolve.h"
#include "../headers/mtx_vec_multiply.h"

#define SIZE 3
#define LB 0
#define UB 100

#define TOLERANCE 0.001
#define MAX_ITERATIONS 500

int main()
{
	// Generate the test matrices
	double* a1 = malloc(SIZE*SIZE * sizeof(double));
	double* a2 = malloc(SIZE*SIZE * sizeof(double));
	double* a3 = malloc(SIZE*SIZE * sizeof(double));
	double* a4 = malloc(SIZE*SIZE * sizeof(double));

	gen_mtxsquare(SIZE, a1, LB, UB);
	gen_mtxsym   (SIZE, a2, LB, UB);
	gen_mtxdd    (SIZE, a3, LB, UB);
	gen_mtxsymdd (SIZE, a4, LB, UB);

	// Generate the b vectors
	double* b1 = malloc(SIZE * sizeof(double));
	double* b2 = malloc(SIZE * sizeof(double));
	double* b3 = malloc(SIZE * sizeof(double));
	double* b4 = malloc(SIZE * sizeof(double));

	// Get a vector of ones to multiply with
	double* ones = malloc(SIZE * sizeof(double));
	for (int i=0; i<SIZE; i++)
	{
		*(ones+i) = 1;
	}

	mtx_vec_multiply(SIZE, SIZE, a1, ones, b1);
	mtx_vec_multiply(SIZE, SIZE, a2, ones, b2);
	mtx_vec_multiply(SIZE, SIZE, a3, ones, b3);
	mtx_vec_multiply(SIZE, SIZE, a4, ones, b4);

	// Get the solution vectors
	double* x1 = malloc(SIZE * sizeof(double));
	double* x2 = malloc(SIZE * sizeof(double));
	double* x3 = malloc(SIZE * sizeof(double));
	double* x4 = malloc(SIZE * sizeof(double));

	// Now do the Jacobi iteration
	mtx_jacobisolve(SIZE, a1, b1, x1, TOLERANCE, MAX_ITERATIONS);
	mtx_jacobisolve(SIZE, a2, b2, x2, TOLERANCE, MAX_ITERATIONS);
	mtx_jacobisolve(SIZE, a3, b3, x3, TOLERANCE, MAX_ITERATIONS);
	mtx_jacobisolve(SIZE, a4, b4, x4, TOLERANCE, MAX_ITERATIONS);

	// Print out solutions
	printf("\nSquare Matrix Solution\n");
	for (int i=0; i<SIZE; i++)
	{
		printf("%.3f ", *(x1 + i));
	}
	printf("\n");

	printf("\nSymmetric Matrix Solution\n");
	for (int i=0; i<SIZE; i++)
	{
		printf("%.3f ", *(x2 + i));
	}
	printf("\n");

	printf("\nDiagonally Dominant Matrix Solution\n");
	for (int i=0; i<SIZE; i++)
	{
		printf("%.3f ", *(x3 + i));
	}
	printf("\n");

	printf("\nSymmetric and Diagonally Dominant Matrix Solution\n");
	for (int i=0; i<SIZE; i++)
	{
		printf("%.3f ", *(x4 + i));
	}
	printf("\n\n");

	// Clean up
	free(a1);
	free(a2);
	free(a3);
	free(a4);

	free(b1);
	free(b2);
	free(b3);
	free(b4);

	free(x1);
	free(x2);
	free(x3);
	free(x4);

	free(ones);

	return 0;
}
