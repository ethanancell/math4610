/* The secant method returns the root of a function as a double. It takes
 * an input of the function, an initial guess x0, another initial guess x1,
 * a tolerance, and a maximum number of iterations.
 */

#include "absolute_error.h"

double secant (double (*function)(),
	       double x0,
	       double x1,
	       double tolerance,
	       int max_iterations)
{
	double x2;
	double error;
	int iterations = 0;

	do
	{
		iterations++;
		x2 = x1 - function(x1) * ((x1-x0)/(function(x1)-function(x0)));
		error = absolute_error(x2, x1);

		// Put x1 as x0 and then x2 as x1
		x0 = x1;
		x1 = x2;
	} 
	while (error > tolerance && iterations < max_iterations);

	return x2;
}
