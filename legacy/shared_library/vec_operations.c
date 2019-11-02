#include <stddef.h>
#include <stdlib.h>

double* vec_add(double u[], double v[], size_t length)
{
	int i;
	double* result = malloc(sizeof(double) * length);

	for(i=0; i<length; i++)
	{
		result[i] = u[i] + v[i];
	}

	return result;
}

double* vec_subtract(double u[], double v[], size_t length)
{
	int i;
	double* result = malloc(sizeof(double) * length);

	for(i=0; i<length; i++)
	{
		result[i] = u[i] - v[i];
	}

	return result;
}

double* vec_scale(double scalar, double u[], size_t length)
{
	int i;
	double* result = malloc(sizeof(double) * length);

	for(i=0; i<length; i++)
	{
		result[i] = u[i] * scalar;
	}

	return result;
}
