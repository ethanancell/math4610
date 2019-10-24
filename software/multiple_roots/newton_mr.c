#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../headers/newton.h"

// Variables we will need to access everywhere
int total_roots = 0;

// Function we are finding the roots of
double function(double x)
{
	return sin(M_PI*pow(x,2) + 3.7);
}

// Function derivative
double function_prime(double x)
{
	return 2*M_PI*x*cos(M_PI*pow(x,2) + 3.7);
}

double* find_roots(double (*function)(), double (*function_prime)(), double a, double b, double step_size)
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
			double newton_guess = (2*a+2*i*step_size+step_size) / 2.0;
			*(root_locations+total_roots-1) = newton(function, function_prime, newton_guess, 0.00001, 1000);
		}
	}

	return root_locations;
}

int main()
{
	double* roots = find_roots(function, function_prime, 1.1, 68.3, 0.0001);
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
