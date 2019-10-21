#include <stdio.h>
#include <math.h>

#include "../src/newton.h"

// Function we wish to find the root of
double function(double x)
{
	return x * cosh(x) + pow(x,3) - M_PI;
}

// Derivative of the above function
double function_prime(double x)
{
	return cosh(x) - x*sinh(x) + 3*pow(x,2);
}

int main()
{
	printf("\nNEWTON's METHOD\n");
	double root = newton(function, function_prime, 1, 0.00001, 1000);
	printf("The root of the function with tolerance 0.00001 is:\n");
	printf("%f\n", root);
	printf("The function evaluated at the root is f(root) = %f\n\n", function(root));

	return 0;
}
