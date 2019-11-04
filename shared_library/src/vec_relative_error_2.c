#include <math.h>
#include <stddef.h>
#include "vec_norm_2.h"

// Relative error with 2-norm
double vec_relative_error_2(double x_approx[], double x[], size_t length)
{
	int i;
	double xdiff[length];

	// Difference vector in numerator
	for(i=0; i<length; i++)
	{
		xdiff[i] = fabs(x_approx[i] - x[i]);
	}

	return vec_norm_2(xdiff, length) / vec_norm_2(x, length);
}
