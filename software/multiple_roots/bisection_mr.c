#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../headers/bisection.h"

// Variables we will need to access everywhere
int total_roots = 0;

// Function we are finding the roots of
double function(double x)
{
	return sin(M_PI*pow(x,2) + 3.7);
}

double* find_roots(double (*function)(), double a, double b, double step_size)
{
	int i;
	int iterations = (int) (b-a) / step_size;

	double fa, fb;

	// Start evaluating at left window point
	double xval = a;
	fa = function(xval);

	// All roots will be set to default value of 0 for no root
	int is_root[iterations];
	for(i=0; i<iterations; i++)
	{
		is_root[i] = 0;
	}

	// Search over iterations number of possible roots using step size.
	for(i=0; i<iterations; i++)
	{
		// If the function evalulates to less than zero for the small
		// window, then we set is_root at that step point to be true.
		xval += step_size;
		fb = function(xval);
		if(fa*fb < 0)
		{
			is_root[i] = 1;
		}

		fa = fb;
	}

	// What we will return
	double* root_locations = malloc(sizeof(double));

	for(i=0; i<sizeof(is_root) / sizeof(int); i++)
	{
		if(is_root[i])
		{
			total_roots++;
			root_locations = realloc(root_locations, total_roots * sizeof(double));
			*(root_locations+total_roots-1) = bisection(function, a+i*step_size, a+i*step_size + step_size, 0.0000001);
		}
	}

	return root_locations;
}

int main()
{
	double* roots = find_roots(function, 1.1, 68.3, 0.0001);
	printf("root size is %d\n", total_roots);

	// Optional Printing
	int i;
	for(i=0; i<total_roots; i++)
	{
		printf("Root of %f\n", roots[i]);
	}

	free(roots);

	return 0;
}
