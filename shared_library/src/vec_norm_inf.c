#include <math.h>
#include <stdlib.h>

// Compute the infinity norm of the vector
double vec_norm_inf(double u[], size_t length)
{
	double max_magnitude = 0.0;
	for(int i=0; i<length; i++)
	{
		if (u[i] > max_magnitude)
		{
			max_magnitude = u[i];
		}
	}

	return max_magnitude;
}
