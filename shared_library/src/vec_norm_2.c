#include <math.h>
#include <stdlib.h>

// Compute the 2-norm of the vector
double vec_norm_2(double u[], size_t length)
{
	double sum = 0.0;
	for (int i=0; i<length; i++)
	{
		sum += u[i] * u[i];
	}

	return sqrt(sum);
}
