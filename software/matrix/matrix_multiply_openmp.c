#include "../headers/mtx_operations.h"
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void openmp_mtx_vec_multiply (int m, int n, double A[m][n], double x[], double* destination)
{
	double sum;
	double aa, xx;

	// loop through rows of matrix
	#pragma omp parallel for
	for(int i=0; i<m; i++)
	{
		sum = 0.0;
		// loop through columns of matrix
		for(int j=0; j<n; j++)
		{
			aa = A[i][j];
			xx = x[j];
			sum += aa * xx;
		}
		*(destination+i) = sum;
	}
}

int main()
{
	printf("\nTime to compute Ax one thousand times, where A is 1000x1000 and x is 1000x1:\n");
	int i, j;

	int am = 1000;
	int an = 1000;
	double A[am][an];

	// Fill out the matrix
	for(i=0; i<am; i++)
	{
		for(j=0; j<an; j++)
		{
			//A[i][j] = rand() % 10 - 4;
			A[i][j] = 2;
		}
	}

	// Fill out the vector
	double x[an];
	for(j=0; j<an; j++)
	{
		x[j] = rand() % 10 - 4;
	}

	double* destination = malloc(sizeof(double) * am);

	// Timing with serial code
	double start = omp_get_wtime();
	for(i=0; i<1000; i++)
	{
		mtx_vec_multiply(am, an, A, x, destination);
	}
	printf("Time in serial code: %f seconds\n", omp_get_wtime() - start);

	// Timing utilizing OpenMP
	start = omp_get_wtime();
	#pragma omp parallel for
	for(i=0; i<1000; i++)
	{
		openmp_mtx_vec_multiply(am, an, A, x, destination);
	}
	printf("Time using OpenMP: %f seconds\n\n", omp_get_wtime() - start);


	free(destination);

	return 0;
}
