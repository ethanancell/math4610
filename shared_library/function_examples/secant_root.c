#include <stdio.h>
#include <math.h>

#include "../src/secant.h"

// Function we wish to find the root of
double function(double x)
{
	return x * cosh(x) + pow(x,3) - M_PI;
}

int main()
{
	printf("\nSECANT METHOD\n");
	double root = secant(function, 1, 1.05, 0.00001, 1000);
	printf("The root of the function with tolerance 0.00001 is:\n");
	printf("%f\n", root);
	printf("The function evaluated at the root is f(root) = %f\n\n", function(root));

	return 0;
}
