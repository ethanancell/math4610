#include <stdio.h>
#include <math.h>

#include "../../../shared_library/src/fixed_point_iteration.h"

// Original function we are trying to find the root of
double f(double x)
{
	return x*cosh(x) + pow(x, 3) - M_PI;
}

double g(double x)
{
	return x - (1.0/8.0) * f(x);
}


// Test the fixed point iteration
int main(int argc, char* argv[]) 
{
	double root;
		
	root = fixed_point_iteration(g, 0, 0.00001, 1000);
	printf("\nFIXED POINT ITERATION\n");
	printf("Root is calculated to be %f\n", root);
	printf("f(root) = %f\n\n", f(root));
	return 0;
}
