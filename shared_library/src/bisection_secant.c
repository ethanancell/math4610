#include "absolute_error.h"

double bisection_secant (double (*function)(),
			 double a,
			 double b,
			 double x0,
			 double x1,
			 double tolerance,
			 int max_iterations)
{
	// Variables necessary for the root finding algorithms
	double error;
	double iterations = 0;

	// Next guess in Secant method
	double x2;

	// Midpoint in bisection
	double c;

	do
	{
		iterations++;

		/* First we try secant method. We say that secant method fails
		 * if we see the new guess x1 to be outside the range of
		 * [a, b]
		 */
		x2 = x1 - function(x1) * ((x1-x0)/(function(x1)-function(x0)));

		if (x2 < a || x2 > b)
		{
			// We failed, so apply bisection four times
			for (int i=0; i<4; i++)
			{
				c = (b+a) / 2.0;

				if (function(a)*function(c) < 0.0)
				{
					x0 = b;
					b = c;
				}
				else if (function(b)*function(c) < 0.0)
				{
					x0 = a;
					a = c;
				}
				else if (function(c) == 0.0)
					return c;
			}

			// At the end, our best guess is c so we put that in x1
			x1 = c;
			error = b-a;
		}
		else
		{
			// We are in the range, so now just use secant method.
			do
			{
				iterations++;
				x2 = x1 - function(x1) * ((x1-x0)/(function(x1)-function(x0)));
				error = absolute_error(x2, x1);

				x0 = x1;
				x1 = x2;
			}
			while (error > tolerance && iterations < max_iterations);
			break;
		}
	}
	while (error > tolerance && iterations < max_iterations);

	// Our best guess is x2 at the end of everything
	return x2;
}
