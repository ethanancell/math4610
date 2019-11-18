#include <stdio.h>

void mtx_jacobisolve(int n,
					 double* a,
					 double* b,
					 double* x,
					 double tolerance,
					 int max_iterations)
{
	double error;
	double xnew[n];

	// Assume that *x is the initial guess
	double xold[n];
	for (int i=0; i<n; i++)
	{
		xold[i] = *(x+i);
	}

	// Iterate

	for (int iterations = 0; iterations < max_iterations; iterations++)
	{
		double sum;
		for (int i=0; i<n; i++)
		{
			xnew[i] = *(b+i);

			for (int j=0; j<i; j++)
			{
				xnew[i] -= *(a+(i*n)+j) * xold[j];
			}
			for (int j=i+1; j<n; j++)
			{
				xnew[i] -= *(a+(i*n)+j) * xold[j];
			}
			xnew[i] /= *(a+(i*n+i));
		}

		// Compute the error
		double diff;
		error = 0.0;
		for (int i=0; i<n; i++)
		{
			diff = xnew[i] - xold[i];
			error += diff * diff;
		}

		// Check our exit condition
		if (error < tolerance)
		{
			// Put in result
			for (int i=0; i<n; i++)
			{
				*(x+i) = xnew[i];
			}
			return;
		}

		for (int i=0; i<n; i++)
		{
			xold[i] = xnew[i];
		}
	}

	// Put in result
	for (int i=0; i<n; i++)
	{
		*(x+i) = xnew[i];
	}
}
