#include <stdio.h>
#include <stdlib.h>

#include "mtx_vec_multiply.h"
#include "vec_dotproduct.h"

int mtx_steepestdescentsolve(int n, double* a, double* b, double* x, double tolerance)
{
	// Set up
	double old_x[n];
	for (int i=0; i<n; i++)
	{
		old_x[i] = *(x+i);
	}
	double new_x[n];

	// Set initial  residual vector
	double residual_vector[n];
	mtx_vec_multiply(n, n, a, old_x, residual_vector);
	for (int i=0; i<n; i++)
	{
		residual_vector[i] = *(b+i) - residual_vector[i];
	}

	// Set "b sub delta"
	double b_sub_delta = vec_dotproduct(b, b, n);

	// Delta
	double delta = vec_dotproduct(residual_vector, residual_vector, n);

	int k = 0;

	while (delta > (tolerance * tolerance * b_sub_delta))
	{
		double* temp_denominator = malloc(n * sizeof(double));
		mtx_vec_multiply(n, n, a, residual_vector, temp_denominator);
		double alpha = delta / vec_dotproduct(residual_vector, temp_denominator, n);

		// Set x+1
		for (int i=0; i<n; i++)
		{
			new_x[i] = old_x[i] + alpha * residual_vector[i];
		}

		// Create new residual vector
		mtx_vec_multiply(n, n, a, new_x, temp_denominator);
		for (int i=0; i<n; i++)
		{
			residual_vector[i] = *(b+i) - *(temp_denominator+i);
		}
		free(temp_denominator);

		// New delta
		delta = vec_dotproduct(residual_vector, residual_vector, n);

		// Update x
		for (int i=0; i<n; i++)
		{
			old_x[i] = new_x[i];
		}

		k++;
	}

	// Store solution in the x pointer
	for (int i=0; i<n; i++)
	{
		*(x+i) = new_x[i];
	}

	return k;
}
