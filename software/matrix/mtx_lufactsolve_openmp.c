#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#include "../headers/mtx_lufactsolve.h"

// ALTERNATE FUNCTION THAT USES OPENMP
void openmp_mtx_lufactsolve(int n, double* a, double* b, double* x)
{
	/*
	 * Step 1 - Get the LU-factorization
	 */
	double factor;

	// Loop over "diagonal" in the form of columns
	#pragma omp parallel for
	for (int k=0; k < n-1; k++)
	{
		// Loop over rows downward
		for (int i=k+1; i<n; i++)
		{
			// At each row, we have a factor that reduces the row.
			// This row is applied to all the columns out.
			factor = *(a+(i*n)+k) / *(a+(k*n)+k);
			for (int j=k+1; j<n; j++)
			{
				*(a+(i*n)+j) = *(a+(i*n)+j) - factor * *(a+(k*n)+j);
			}
			*(a+(i*n)+k) = factor;
		}
	}

	/*
	 * Step 2 - Find z in Lz=x with forward substitution
	 */
	double sum;
	double z[n];

	// Replace the diagonals with 1
	double u_diagonal[n];

	#pragma omp parallel for
	for (int i=0; i<n; i++)
	{
		u_diagonal[i] = *(a+(i*n)+i);
		*(a+(i*n)+i) = 1;
	}

	// Now do forward sub.
	z[0] = *b / *a;

	#pragma omp parallel for
	for (int i=1; i<n; i++)
	{
		sum = *(b+i);
		for (int j=0; j<i; j++)
		{
			sum -= *(a+(i*n)+j) * z[j];
		}
		z[i] = sum / *(a+(i*n)+i);
	}

	/*
	 * Step 3 - Find x in Ux=z with back substitution
	 */

	// Put the original diagonals back.
	#pragma omp parallel for
	for (int i=0; i<n; i++)
	{
		 *(a+(i*n)+i) = u_diagonal[i];
	}

	// Now do back sub.
	*(x+n-1) = z[n-1] / *(a+((n-1)*n)+n-1);

	#pragma omp parallel for
	for (int i=n-2; i>=0; i--)
	{
		sum = z[i];
		for (int j=i+1; j<n; j++)
		{
			sum -= *(a+(i*n)+j) * *(x+j);
		}
		*(x+i) = sum / *(a+(i*n)+i);
	}
}

int main()
{
	printf("\nTime to solve 2000x2000 linear system:\n");

	// Create and fill out matrices and b.
	int n = 2000;
	double* a = malloc(n * n * sizeof(double));
	for (int i=0; i<n*n; i++)
	{
		*(a+i) = rand() % 20 - 4;
	}

	double* b = malloc(n * sizeof(double));
	for (int i=0; i<n; i++)
	{
		*(b+i) = rand() % 10 - 6;
	}

	double* x = malloc(n * sizeof(double));

	// Make a copy for the serial code
	double* a2 = malloc(n * n * sizeof(double));
	for (int i=0; i<n*n; i++)
	{
		*(a2+i) = *(a+i);
	}
	double* b2 = malloc(n * sizeof(double));
	for (int i=0; i<n; i++)
	{
		*(b2+i) = *(b+i);
	}

	// Time with serial code
	double start = omp_get_wtime();
	mtx_lufactsolve(n, a2, b2, x);
	printf("Time in serial code: %f seconds\n", omp_get_wtime() - start);

	free(a2);
	free(b2);

	// Time using OpenMP
	start = omp_get_wtime();
	openmp_mtx_lufactsolve(n, a, b, x);
	printf("Time using OpenMP: %f seconds\n\n", omp_get_wtime() - start);

	free(a);
	free(b);
	free(x);

	return 0;
}
