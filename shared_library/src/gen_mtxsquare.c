#include <stdlib.h>
#include <time.h>

void gen_mtxsquare(int n, double* a, double lower_bound, double upper_bound)
{
	srand(time(0));

	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			*(a+(i*n)+j) = ((double) rand() / RAND_MAX) * (upper_bound - lower_bound) + lower_bound;
		}
	}
}
