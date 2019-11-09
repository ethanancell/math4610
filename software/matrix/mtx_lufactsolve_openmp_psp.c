#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

// ALTERNATE FUNCTION THAT USES OPENMP AND PARTIAL SCALE PIVOTING
void openmp_mtx_lufactsolve(int n, double* a, double* b, double* x)
{
	/*
	 * Step 1 - Get the LU-factorization
	 */

	// Create an index map called "p" that we use so we can handle
	// partial scale pivoting
	int p[n];
	for (int i=0; i<n; i++)
	{
		p[i] = i;
	}

	// Get the scale vector
	double scale[n];
	for (int i=0; i<n; i++)
	{
		double val = fabs(*(a+(i*n)));
		for (int j=1; j<n; j++)
		{
			double valcheck = fabs(*(a+(i*n)+j));
			if (valcheck > val) val = valcheck;
		}
		scale[i] = val;
	}

	// Loop over "diagonal" in the form of columns
	double factor;
	#pragma omp parallel for
	for (int k=0; k < n-1; k++)
	{
		// Get the row with the largest pivot relative to
		// scale factor in the row
		int p_index_temp = p[k];
		double max_val = fabs(*(a+(p[k]*n)+k)) / scale[p[k]];
		for (int i=k+1; i<n; i++)
		{
			double check_val = fabs(*(a+(p[i]*n)+k)) / scale[p[k]];
			if (check_val > max_val)
			{
				max_val = check_val;
				p_index_temp = p[i];
			}
		}
		// Now swap the indices
		int temp = p[k];
		p[k] = p[p_index_temp];
		p[p_index_temp] = temp;

		// Loop over rows downward
		for (int i=k+1; i<n; i++)
		{
			// At each row, we have a factor that reduces the row.
			// This row is applied to all the columns out.
			factor = *(a+(p[i]*n)+k) / *(a+(p[k]*n)+k);
			for (int j=k+1; j<n; j++)
			{
				*(a+(p[i]*n)+j) -= factor * *(a+(p[k]*n)+j);
			}
			*(a+(p[i]*n)+k) = factor;
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
		u_diagonal[i] = *(a+(p[i]*n)+i);
		*(a+(p[i]*n)+i) = 1;
	}

	// Now do forward sub.
	z[0] = *b / *(a+p[0]);

	#pragma omp parallel for
	for (int i=1; i<n; i++)
	{
		sum = *(b+i);
		for (int j=0; j<i; j++)
		{
			sum -= *(a+(p[i]*n)+j) * z[j];
		}
		z[i] = sum / *(a+(p[i]*n)+i);
	}

	/*
	 * Step 3 - Find x in Ux=z with back substitution
	 */

	// Put the original diagonals back.
	#pragma omp parallel for
	for (int i=0; i<n; i++)
	{
		 *(a+(p[i]*n)+i) = u_diagonal[i];
	}

	// Now do back sub.
	*(x+n-1) = z[n-1] / *(a+(p[n-1]*n)+n-1);

	#pragma omp parallel for
	for (int i=n-2; i>=0; i--)
	{
		sum = z[i];
		for (int j=i+1; j<n; j++)
		{
			sum -= *(a+(p[i]*n)+j) * *(x+j);
		}
		*(x+i) = sum / *(a+(p[i]*n)+i);
	}
}

int main()
{
	printf("\nOpenMP optimized LU-factorization with partial scale pivoting solution to the\n following randomly generated matrix:\n\n");

	// Create and fill out matrices and b.
	int n = 5;
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

	// Print the matrix and vectors
	for (int i=0; i<n; i++)
	{
		printf("[");
		for (int j=0; j<n; j++)
		{
			printf("%.3f ", *(a+(i*n)+j));
		}
		printf("] [x%d]", i);
		if (i == n / 2)
			printf(" = ");
		else
			printf("   ");

		printf("[%.3f]\n", *(b+i));
	}

	openmp_mtx_lufactsolve(n, a, b, x);

	// Print the solution
	printf("\nThe solution is:\n<");
	for (int i=0; i<n-1; i++)
	{
		printf("%.3f, ", *(x+i));
	}
	printf("%.3f>\n\n", *(x+n-1));

	free(a);
	free(b);
	free(x);

	return 0;
}
