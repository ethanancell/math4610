#include <stdio.h>
#include <stdlib.h>

#include "mtx_vec_multiply.h"
#include "vec_dotproduct.h"

int mtx_cgsolve(int n, double* a, double* b, double* x, double tolerance)
{
	// Set up
	double x0[n];
	double x1[n];
	double r0[n];
	double r1[n];

	double p0[n];
	double p1[n];

	int k = 0;

	// Set initial guess x0
	for (int i=0; i<n; i++)
	{
		x0[i] = *(x+i);
	}

	// Set r0
	mtx_vec_multiply(n, n, a, x0, r0);
	for (int i=0; i<n; i++)
	{
		r0[i] = *(b+i) - r0[i];
	}

	// Set p0 to be r0
	for (int i=0; i<n; i++)
	{
		p0[i] = r0[i];
	}

	// Delta (Error)
	double b_delta = vec_dotproduct(b, b, n);
	double delta = vec_dotproduct(r0, r0, n);

	while (delta > (tolerance * tolerance * b_delta))
	{
		double* s0 = malloc(n * sizeof(double));
		mtx_vec_multiply(n, n, a, p0, s0);

		double alpha = (vec_dotproduct(r0, r0, n)) / (vec_dotproduct(p0, s0, n));

		// Set x1
		for (int i=0; i<n; i++)
		{
			x1[i] = x0[i] + alpha*p0[i];
		}

		// Set new residual r1
		for (int i=0; i<n; i++)
		{
			r1[i] = r0[i] - alpha*s0[i];
		}

		// Beta
		double beta0 = (vec_dotproduct(r1, r1, n)) / (vec_dotproduct(r0, r0, n));

		// New p1
		for (int i=0; i<n; i++)
		{
			p1[i] = r1[i] + beta0*p0[i];
		}

		// Update delta
		delta = vec_dotproduct(r1, r1, n);

		// Now put all the news in the olds
		for (int i=0; i<n; i++)
		{
			x0[i] = x1[i];
		}
		for (int i=0; i<n; i++)
		{
			r0[i] = r1[i];
		}
		for (int i=0; i<n; i++)
		{
			p0[i] = p1[i];
		}
		k++;

		free(s0);
	}

	// After all is said and done, store the solution
	for (int i=0; i<n; i++)
	{
		*(x+i) = x0[i];
	}

	return k;
}
