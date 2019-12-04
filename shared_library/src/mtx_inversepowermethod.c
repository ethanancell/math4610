#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "mtx_cgsolve.h"
#include "mtx_echelonsolve.h"
#include "mtx_lufact.h"
#include "mtx_lufact_justsolve.h"
#include "mtx_vec_multiply.h"
#include "vec_dotproduct.h"
#include "vec_norm_2.h"

// Returns largest eigenvalue of the matrix
double mtx_inversepowermethod(int n, double* aa, double* v, double tolerance, int max_iterations)
{
	int k=0;
	double error = 10.0 * tolerance;
	double lambda0 = 0.0;
	double lambda1;

	double v0[n];
	for (int i=0; i<n; i++)
	{
		v0[i] = *(v+i);
	}

	double vtilde[n];
	double v1[n];
	double vtemp[n];

	// Get an LU version of A to use
	double* a = malloc(n*n*sizeof(double));
	for (int i=0; i<n*n; i++)
	{
		*(a+i) = *(aa+i);
	}
	mtx_lufact(n, a);

	while (error > tolerance && k < max_iterations)
	{
		mtx_lufact_justsolve(n, a, v0, vtilde);

		// All other code should be the same as the regular power method.
		double normal_scalar = 1.0 / vec_norm_2(vtilde, n);
		for (int i=0; i<n; i++)
		{
			v1[i] = normal_scalar * vtilde[i];
		}

		mtx_vec_multiply(n, n, aa, v1, vtemp);

		lambda1 = vec_dotproduct(v1, vtemp, n);
		error = fabs(lambda1 - lambda0);

		lambda0 = lambda1;

		for (int i=0; i<n; i++)
		{
			v0[i] = v1[i];
		}
	}

	//
	free(a);

	// Best guess that we have is lambda for eigenvalue
	return lambda0;
}
