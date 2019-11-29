#include <stdio.h>
#include <stdlib.h>

#include "../headers/gen_mtxsymdd.h"
#include "../headers/mtx_vec_multiply.h"
#include "../headers/mtx_cgsolve.h"

#define SIZE 4
#define LB 0
#define UB 100

#define TOLERANCE 0.0001

int main()
{
	// A
	double* a = malloc(SIZE*SIZE * sizeof(double));
	gen_mtxsymdd(SIZE, a, LB, UB);

	// Ones vector
	double* ones = malloc(SIZE * sizeof(double));
	for (int i=0; i<SIZE; i++)
	{
		*(ones+i) = 1;
	}

	// b
	double* b = malloc(SIZE * sizeof(double));
	/*for (int i=0; i<SIZE; i++)
	{
		*(b+i) = -5;
	*/
	mtx_vec_multiply(SIZE, SIZE, a, ones, b);

	// x w/ initial guess
	double* x = malloc(SIZE * sizeof(double));
	for (int i=0; i<SIZE; i++)
	{
		*(x+i) = 0;
	}

	// Solve
	mtx_cgsolve(SIZE, a, b, x, TOLERANCE);

	// Print solutions
	printf("\nConjugate Gradient Solution\n");
	for (int i=0; i<SIZE; i++)
	{
		printf("%.3f ", *(x + i));
	}
	printf("\n\n");

	free(a);
	free(b);
	free(ones);
	free(x);

	return 0;
}
