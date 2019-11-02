#include <math.h>
#include <stddef.h>
#include "vec_norm.h"

// Absolute error with 2-norm
double vec_absolute_error_2(double x_approx[], double x[], size_t length)
{
	int i;
	double xdiff[length];

	// Difference vector in numerator
	for(i=0; i<length; i++)
	{
		xdiff[i] = fabs(x_approx[i] - x[i]);
	}

	return vec_norm_2(xdiff, length);
}
