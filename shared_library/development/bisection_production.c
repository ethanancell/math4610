#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Bisection Method takes an input of a function that returns a double,
 * a lower bound "a", an upper bound "b", and the tolerance for how close
 * to the true value we should be.
 */
double bisection (double (*function)(),
		  double aa,
		  double bb,
		  double tolerance)
{
	double *a = malloc(sizeof(double));
	double *b = malloc(sizeof(double));
	double *c = malloc(sizeof(double));

	*a = aa;
	*b = bb;

	double error;
	int iterations;

	if (function(*a) == 0.0) 
	{
		double return_value = *a;
		free(a);
		free(b);
		free(c);
		return return_value;
	}
	if (function(*b) == 0.0)
	{
		double return_value = *b;
		free(a);
		free(b);
		free(c);
		return return_value;
	}

	int k = (int) ((log((*b-*a)/tolerance) / log(2)) +1 );

	for (int i=0; i<k; i++)
	{
		*c = (*b+*a) / 2.0;
		if (function(*a)*function(*c) < 0.0)
		{
			*b = *c;
		}
		else if (function(*c) == 0.0)
		{
			double return_value = *c;
			free(a);
			free(b);
			free(c);
			return return_value;
		}
		else if (function(*b)*function(*c) < 0.0)
		{
			*a = *c;
		}
	}

	double return_value = *c;
	free(a);
	free(b);
	free(c);
	return return_value;
}
		  


int main()
{
	double root = bisection(my_function, 1, 3, 0.00001, 1000);
	printf("Root of cosine is %f\n", root);
	printf("F(root) = %f\n", my_function(root));
	return 0;
}

