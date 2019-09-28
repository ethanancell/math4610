#include <math.h>

/*
 * This code will compute the root of a function by attempting to iterate the the modified form of the
 * function g(x) until the error between successive iterations is less than the tolerance. The requirements
 * of this code is that the derivative of the modified g(x) function must be less than one in order for this
 * to converge. Additionally, an initial guess, tolerance, and maximum iterations must be supplied.
 */
double fixed_point_iteration (double (*gfunction)(),
			      double x0,
			      double tolerance,
			      int max_iterations)
{
	double error;
	double x1;
	int iterations = 0;

	do {
		x1 = gfunction(x0);
		error = fabs(x1 - x0);
		x0 = x1;
		iterations++;
	}
	while (error > tolerance && iterations < max_iterations);

	// At the end of it, our best guess is x1 so we will return that.
	return x1;
}
