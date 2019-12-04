#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "mtx_lufact.h"
#include "mtx_lufact_justsolve.h"
#include "mtx_vec_multiply.h"
#include "vec_dotproduct.h"
#include "vec_norm_inf.h"

// Returns largest eigenvalue of the matrix
double mtx_shiftpowermethod(int n, double* a, double* v, double alpha, double tolerance, int max_iterations)
{
	// Initial vector
	double v0[n];
	for (int i=0; i<n; i++)
	{
		v0[i] = *(v+i);
	}

	// Shifted matrix
	double* sa = malloc(n*n*sizeof(double));
	for (int i=0; i<n*n; i++)
	{
		*(sa+i) = *(a+i);
	}
	for (int i=0; i<n; i++)
	{
		*(sa+(i*n)+i) -= alpha;
	}

	// Get an LU version of sa
	double* sa_lu = malloc(n*n*sizeof(double));
	for (int i=0; i<n*n; i++)
	{
		*(sa_lu+i) = *(sa+i);
	}
	mtx_lufact(n, sa_lu);

	// New guess v (vtilde is unnormalized)
	double v1[n];
	double y0[n];
	double c0;
	double c00 = 0;

	// Error and iterations
	double error = 10.0 * tolerance;
	int k = 0;

	while (k < max_iterations)
	{
		// Get unnormalized value
		// v0 is x0
		// vtilde is y0
		mtx_lufact_justsolve(n, sa_lu, v0, y0);

		// Normalize
		// v1 is x1
		double normal_scalar = 1.0 / vec_norm_inf(y0, n);
		for (int i=0; i<n; i++)
		{
			v1[i] = normal_scalar * y0[i];
		}

		// Ck
		c0 = vec_dotproduct(y0, v0, n) / vec_dotproduct(v0, v0, n);

		// Get error and increase iterations
		error = c0 - c00;
		k++;

		// Shift of index
		for (int i=0; i<n; i++)
		{
			v0[i] = v1[i];
		}
		c00 = c0;
	}

	free(sa);
	free(sa_lu);

	// Return correct value that is stored in c0
	return (1.0 / c0) + alpha;
}
