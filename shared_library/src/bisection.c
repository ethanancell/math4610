#include <math.h>

/* Bisection Method takes an input of a function that returns a double,
 * a lower bound "a", an upper bound "b", and the tolerance for how close
 * to the true value we should be.
 */
double bisection (double (*function)(),
		  double a,
		  double b,
		  double tolerance)
{
	// c will represent the midway point between a and b.
	double c;

	// First make sure our root isn't at our endpoints.
	if (function(a) == 0.0) return a;
	if (function(b) == 0.0) return b;
	
	// This value of k iterations was analytically derived in order to reach the
	// specified tolerance that we passed in our function.
	int k = (int) ((log((b-a)/tolerance) / log(2)) + 1);

	// We only need to loop k times in order to reach our tolerance because of the
	// analytically derived linear convergence of the bisection method.
	for (int i=0; i<k; i++)
	{
		c = (b+a) / 2.0;

		if (function(a)*function(c) < 0.0) 
			b = c;
		else if (function(b)*function(c) < 0.0) 
			a = c;
		else if (function(c) == 0.0) 
			return c;
	}

	// At the end of the day if we never exactly found the root, we return our
	// best guess here, but should be within the tolerance that we specified.
}
