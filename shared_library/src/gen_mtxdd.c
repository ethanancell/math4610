#include <stdlib.h>
#include <time.h>

void gen_mtxdd(int n, double* a, double l, double u)
{
	srand(time(0));

	for (int i=1; i<n; i++)
	{
		// Generate non-diagonal
		for (int j=0; j<i; j++)
		{
			*(a+(i*n)+j) = ((double) rand() / RAND_MAX) * (u - l) + l;
			*(a+(j*n)+i) = ((double) rand() / RAND_MAX) * (u - l) + l;
		}
	}

	// Now generate the diagonal
	for (int i=0; i<n; i++)
	{
		double sum = 0.0;
		for (int j=0; j<n; j++)
		{
			if (j != i)
			{
				sum += *(a+(i*n)+j);
			}
		}
		*(a+(i*n)+i) = sum + ((double) rand() / RAND_MAX) * (u - l) + l;
	}
}
