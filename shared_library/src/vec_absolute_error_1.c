#include <math.h>
#include <stddef.h>
#include "vec_norm_1.h"

// Absolute error with 1-norm
double vec_absolute_error_1(double x_approx[], double x[], size_t length)
{
	int i;
	double xdiff[length];

	// Difference vector in numerator
	for(i=0; i<length; i++)
	{
		xdiff[i] = fabs(x_approx[i] - x[i]);
	}

	return vec_norm_1(xdiff, length);
}
