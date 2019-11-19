#include <stdio.h>
#include <stdlib.h>

#include "../headers/gen_mtxsquare.h"
#include "../headers/gen_mtxsym.h"
#include "../headers/gen_mtxdd.h"
#include "../headers/gen_mtxsymdd.h"
#include "../headers/mtx_gssolve.h"
#include "../headers/mtx_lufactsolve.h"
#include "../headers/mtx_jacobisolve.h"
#include "../headers/mtx_vec_multiply.h"

#define SIZE 3
#define LB 0
#define UB 100

#define TOLERANCE 0.0001
#define MAX_ITERATIONS 5000

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
	double* x1j = malloc(SIZE * sizeof(double));
	double* x2j = malloc(SIZE * sizeof(double));
	double* x3j = malloc(SIZE * sizeof(double));
	double* x4j = malloc(SIZE * sizeof(double));
	double* x1g = malloc(SIZE * sizeof(double));
	double* x2g = malloc(SIZE * sizeof(double));
	double* x3g = malloc(SIZE * sizeof(double));
	double* x4g = malloc(SIZE * sizeof(double));

	// Gauss-Seidel
	int iter1g = mtx_gssolve(SIZE, a1, b1, x1g, TOLERANCE, MAX_ITERATIONS);
	int iter2g = mtx_gssolve(SIZE, a2, b2, x2g, TOLERANCE, MAX_ITERATIONS);
	int iter3g = mtx_gssolve(SIZE, a3, b3, x3g, TOLERANCE, MAX_ITERATIONS);
	int iter4g = mtx_gssolve(SIZE, a4, b4, x4g, TOLERANCE, MAX_ITERATIONS);

	// Jacobi iteration
	int iter1j = mtx_jacobisolve(SIZE, a1, b1, x1j, TOLERANCE, MAX_ITERATIONS);
	int iter2j = mtx_jacobisolve(SIZE, a2, b2, x2j, TOLERANCE, MAX_ITERATIONS);
	int iter3j = mtx_jacobisolve(SIZE, a3, b3, x3j, TOLERANCE, MAX_ITERATIONS);
	int iter4j = mtx_jacobisolve(SIZE, a4, b4, x4j, TOLERANCE, MAX_ITERATIONS);

	// Print out solutions
	printf("\nSquare Matrix\n");
	printf("Jacobi Solution: (%d iterations)\n", iter1j);
	for (int i=0; i<SIZE; i++)
	{
		printf("%.3f ", *(x1j + i));
	}
	printf("\nGauss-Seidel Solution: (%d iterations)\n", iter1g);
	for (int i=0; i<SIZE; i++)
	{
		printf("%.3f ", *(x1g + i));
	}
	printf("\n");


	printf("\nSymmetric Matrix\n");
	printf("Jacobi Solution: (%d iterations)\n", iter2j);
	for (int i=0; i<SIZE; i++)
	{
		printf("%.3f ", *(x2j + i));
	}
	printf("\nGauss-Seidel Solution: (%d iterations)\n", iter2g);
	for (int i=0; i<SIZE; i++)
	{
		printf("%.3f ", *(x2g + i));
	}
	printf("\n");


	printf("\nDiagonally Dominant Matrix\n");
	printf("Jacobi Solution: (%d iterations)\n", iter3j);
	for (int i=0; i<SIZE; i++)
	{
		printf("%.3f ", *(x3j + i));
	}
	printf("\nGauss-Seidel Solution: (%d iterations)\n", iter3g);
	for (int i=0; i<SIZE; i++)
	{
		printf("%.3f ", *(x3g + i));
	}
	printf("\n");


	printf("\nSymmetric and Diagonally Dominant Matrix\n");
	printf("Jacobi Solution: (%d iterations)\n", iter4j);
	for (int i=0; i<SIZE; i++)
	{
		printf("%.3f ", *(x4j + i));
	}
	printf("\nGauss-Seidel Solution: (%d iterations)\n", iter4g);
	for (int i=0; i<SIZE; i++)
	{
		printf("%.3f ", *(x4g + i));
	}
	printf("\n\n\n");

	// Clean up
	free(a1);
	free(a2);
	free(a3);
	free(a4);

	free(b1);
	free(b2);
	free(b3);
	free(b4);

	free(x1j);
	free(x2j);
	free(x3j);
	free(x4j);
	free(x1g);
	free(x2g);
	free(x3g);
	free(x4g);


	free(ones);

	return 0;
}
