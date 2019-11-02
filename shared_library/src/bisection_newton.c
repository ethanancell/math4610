#include "absolute_error.h"

double bisection_newton (double (*function)(),
			 double (*function_prime)(),
			 double a,
			 double b,
			 double x0,
			 double tolerance,
			 int max_iterations)
{
	// Variables necessary for the root finding algorithms
	double error;
	double iterations = 0;

	// Next guess in Newton's method
	double x1;

	// Midpoint in bisection
	double c;

	do
	{
		iterations++;

		/* First we try Newton's method. We say that Newton's method fails
		 * if we see the new guess x1 to be outside the range of
		 * [a, b]
		 */
		x1 = x0 - function(x0) / function_prime(x0);

		if (x1 < a || x1 > b)
		{
			// We failed, so apply bisection four times
			for (int i=0; i<4; i++)
			{
				c = (b+a) / 2.0;

				if (function(a)*function(c) < 0.0)
					b = c;
				else if (function(b)*function(c) < 0.0)
					a = c;
				else if (function(c) == 0.0)
					return c;
			}

			// At the end, our best guess is c so we put that in x0
			x0 = c;
			error = b-a;
		}
		else
		{
			// We are in the range, so now just use Newton's method.
			do
			{
				iterations++;
				x1 = x0 - function(x0) / function_prime(x0);
				error = absolute_error(x1, x0);

				x0 = x1;
			}
			while (error > tolerance && iterations < max_iterations);
			break;
		}
	}
	while (error > tolerance && iterations < max_iterations);

	// Our best guess is x1 at the end of everything
	return x1;
}
