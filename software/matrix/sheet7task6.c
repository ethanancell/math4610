#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#include "../headers/gen_mtxsymdd.h"
#include "../headers/mtx_vec_multiply.h"
#include "../headers/mtx_jacobisolve.h"
#include "../headers/mtx_steepestdescentsolve.h"
#include "../headers/mtx_echelonsolve.h"
#include "../headers/mtx_cgsolve.h"

#define SIZE 1000
#define LB 0
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
	double* x_ji = malloc(SIZE * sizeof(double));
	for (int i=0; i<SIZE; i++)
	{
		*(x_cg+i) = 0;
		*(x_sd+i) = 0;
		*(x_ji+i) = 0;
	}

	// Solve

	double start;

	printf("\n");

	start = omp_get_wtime();
	mtx_cgsolve(SIZE, a, b, x_cg, TOLERANCE);
	printf("Conjugate gradient time: %f seconds.\n", omp_get_wtime() - start);

	start = omp_get_wtime();
	mtx_steepestdescentsolve(SIZE, a, b, x_sd, TOLERANCE);
	printf("Steepest descent time: %f seconds.\n", omp_get_wtime() - start);

	start = omp_get_wtime();
	mtx_jacobisolve(SIZE, a, b, x_ji, TOLERANCE, 10000);
	printf("Jacobi iteration time: %f seconds.\n", omp_get_wtime() - start);

	printf("\n");

	free(a);
	free(b);
	free(ones);
	free(x_cg);
	free(x_sd);
	free(x_ji);

	return 0;
}
