#include <math.h>
#include <stdlib.h>

// Compute the 1-norm of the vector
double vec_norm_1(double u[], size_t length)
{
	double sum = 0.0;
	for(int i=0; i<length; i++)
	{
		sum += u[i];
	}

	return sum;
}
