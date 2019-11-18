#include <stdlib.h>
#include <time.h>

void gen_mtxsym(int n, double* a, double l, double u)
{
	srand(time(0));
	double random_number;

	// Generate non-diagonal
	for (int i=1; i<n; i++)
	{
		for (int j=0; j<i; j++)
		{
			random_number = ((double) rand() / RAND_MAX) * (u - l) + l;
			*(a+(i*n)+j) = random_number;
			*(a+(j*n)+i) = random_number;
		}
	}

	// Now generate the diagonal
	for (int i=0; i<n; i++)
	{
		*(a+(i*n)+i) = ((double) rand() / RAND_MAX) * (u - l) + l;
	}
}
