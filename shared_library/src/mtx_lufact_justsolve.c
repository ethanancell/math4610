#include <stdlib.h>

void mtx_lufact_justsolve(int n, double* a, double* b, double* x)
{
	/*
	 * Step 2 - Find z in Lz=x with forward substitution
	 */
	double sum;
	double z[n];

	// Replace the diagonals with 1
	double u_diagonal[n];
	for (int i=0; i<n; i++)
	{
		u_diagonal[i] = *(a+(i*n)+i);
		*(a+(i*n)+i) = 1;
	}

	// Now do forward sub.
	z[0] = *b / *a;

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
	for (int i=0; i<n; i++)
	{
		 *(a+(i*n)+i) = u_diagonal[i];
	}

	// Now do back sub.
	*(x+n-1) = z[n-1] / *(a+((n-1)*n)+n-1);

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
