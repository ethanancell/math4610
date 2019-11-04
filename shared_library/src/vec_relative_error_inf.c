#include <math.h>
#include <stddef.h>
#include "vec_norm_inf.h"

// Relative error with infinity-norm
double vec_relative_error_inf(double x_approx[], double x[], size_t length)
{
	int i;
	double xdiff[length];

	// Difference vector in numerator
	for(i=0; i<length; i++)
	{
		xdiff[i] = fabs(x_approx[i] - x[i]);
	}

	return vec_norm_inf(xdiff, length) / vec_norm_inf(x, length);
}
