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
#include "mtx_tridiagonal_multiply.h"

// Returns largest eigenvalue of the matrix
double mtx_tridiag_inversepowermethod(int n, double* au, double* ad, double* al, double* v, double tolerance, int max_iterations)
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

	// Copy the vectors
	double a[n];
	double b[n];
	double c[n];

	for (int i=0; i<n; i++)
	{
		a[i] = *(al+i);
		b[i] = *(ad+i);
		c[i] = *(au+i);
	}

	// Get an LU version of A to use in a, b, c
	for (int i=1; i<n; i++)
	{
		a[i] /= b[i-1];
		b[i] -= a[i]*c[i-1];
	}

	while (error > tolerance && k < max_iterations)
	{
		// Solve the LU system, of Avtilde = v0
		// Solve Ly = f
		double y[n];
		for (int i=0; i<n; i++)
		{
			y[i] = *(v0+i);
		}
		for (int i=1; i<n; i++)
		{
			y[i] -= a[i]*y[i-1];
		}

		// Solve Uu = y
		vtilde[n-1] = y[n-1] / b[n-1];
		for (int i=n-2; i>=0; i--)
		{
			vtilde[i] = (y[i] - c[i]*vtilde[i+1])/b[i];
		}

		// All other code should be the same as the regular power method.
		double normal_scalar = 1.0 / vec_norm_2(vtilde, n);
		for (int i=0; i<n; i++)
		{
			v1[i] = normal_scalar * vtilde[i];
		}

		mtx_tridiagonal_multiply(n, au, ad, al, v1, vtemp);

		lambda1 = vec_dotproduct(v1, vtemp, n);
		error = fabs(lambda1 - lambda0);

		lambda0 = lambda1;

		for (int i=0; i<n; i++)
		{
			v0[i] = v1[i];
		}
	}

	// Best guess that we have is lambda for eigenvalue
	return lambda0;
}
