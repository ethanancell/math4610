#include <stdio.h>
#include <math.h>

#include "../../../shared_library/src/fixed_point_iteration.h"

// Original function we are trying to find the root of
double f(double x)
{
	return x*cosh(x) + pow(x, 3) - M_PI;
}

/*
 * First g(x)
 * g(x) = x + f(x)
 * g(x) = x + xcosh(x) + x^3 - pi
 */
double g1(double x)
{
	return x + f(x);
}

/*
 * Second g(x)
 * g(x) = x - (1/8)f(x)
 * g(x) = x - (1/8)(xcosh(x) + x^3 - pi)
 */
double g2(double x)
{
	return x - (1.0/8.0) * f(x);
}


// Test the fixed point iteration for the above two
int main(int argc, char* argv[]) 
{
	double root;
	
	root = fixed_point_iteration(g1, 0, 0.00001, 1000);
	printf("\nFirst g(x) from Task 2\n");
	printf("Root is calculated to be %f\n", root); 
	
	root = fixed_point_iteration(g2, 0, 0.00001, 1000);
	printf("\nSecond g(x) from Task 2\n");
	printf("Root is calculated to be %f\n\n", root);
	return 0;
}
