#include <math.h>
#include <stddef.h>
#include "vec_norm.h"

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

// Absolute error with infinity-norm
double vec_absolute_error_inf(double x_approx[], double x[], size_t length)
{
	int i;
	double xdiff[length];

	// Difference vector in numerator
	for(i=0; i<length; i++)
	{
		xdiff[i] = fabs(x_approx[i] - x[i]);
	}

	return vec_norm_inf(xdiff, length);
}

// Relative error with 1-norm
double vec_relative_error_1(double x_approx[], double x[], size_t length)
{
	int i;
	double xdiff[length];

	// Difference vector in numerator
	for(i=0; i<length; i++)
	{
		xdiff[i] = fabs(x_approx[i] - x[i]);
	}

	return vec_norm_1(xdiff, length) / vec_norm_1(x, length);
}

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
