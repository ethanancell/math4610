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
