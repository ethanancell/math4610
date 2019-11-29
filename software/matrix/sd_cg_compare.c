#include <stdio.h>
#include <stdlib.h>

#include "../headers/gen_mtxsymdd.h"
#include "../headers/mtx_vec_multiply.h"
#include "../headers/mtx_cgsolve.h"
#include "../headers/mtx_steepestdescentsolve.h"

#define SIZE 10
#define LB -20
#define UB 100

#define TOLERANCE 0.000001

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
	mtx_vec_multiply(SIZE, SIZE, a, ones, b);

	// x w/ initial guess
	double* x_cg = malloc(SIZE * sizeof(double));
	double* x_sd = malloc(SIZE * sizeof(double));
	for (int i=0; i<SIZE; i++)
	{
		*(x_cg+i) = 0;
		*(x_sd+i) = 0;
	}

	// Solve
	int cg_iterations = mtx_cgsolve(SIZE, a, b, x_cg, TOLERANCE);
	int sd_iterations = mtx_steepestdescentsolve(SIZE, a, b, x_sd, TOLERANCE);

	// Print solutions
	printf("\nConjugate Gradient Solution (%d iterations)\n", cg_iterations);
	for (int i=0; i<SIZE; i++)
	{
		printf("%.3f ", *(x_cg + i));
	}
	printf("\n\n");

	printf("\nSteepest Descent Solution (%d iterations)\n", sd_iterations);
	for (int i=0; i<SIZE; i++)
	{
		printf("%.3f ", *(x_sd + i));
	}
	printf("\n\n");

	free(a);
	free(b);
	free(ones);
	free(x_cg);
	free(x_sd);

	return 0;
}
