#include <math.h>

int mtx_choleskyfact(int n, double* a)
{
	// First check to make sure that the matrix is symmetric
	for (int i=1; i<n; i++)
	{
		for (int j=0; j<i; j++)
		{
			if (*(a+(i*n)+j) != *(a+(j*n+i)))
			{
				// Matrix is not symmetric.
				return -1;
			}
		}
	}

	// Perform the factorization
	for (int k=0; k<n; k++)
	{
		*(a+(k*n)+k) = sqrt(*(a+(k*n)+k));

		for (int i=k+1; i<n; i++)
		{
			*(a+(i*n)+k) = *(a+(i*n)+k) / *(a+(k*n)+k);
		}
		for (int j=k+1; j<n; j++)
		{
			for (int i=j; i<n; i++)
			{
				*(a+(i*n)+j) -= *(a+(j*n)+k) * *(a+(i*n)+k);
			}
		}
	}

	return 0;
}
