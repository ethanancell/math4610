/* Newton's method returns the root of a function as a double. It takes
 * an input of the function, the function's derivative, an initial guess x0,
 * a tolerance, and a maximum number of iterations.
 */

#include "absolute_error.h"

double newton (double (*function)(),
	       double (*function_prime)(),
	       double x0,
	       double tolerance,
	       int max_iterations)
{
	double x1;
	double error;
	int iterations = 0;

	do
	{
		iterations++;
		x1 = x0 - function(x0) / function_prime(x0);
		error = absolute_error(x1, x0);

		// Put new x1 as x0
		x0 = x1;
	} 
	while (error > tolerance && iterations < max_iterations);

	return x1;
}
