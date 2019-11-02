#include <stdio.h>
#include <math.h>

#include "../src/bisection_secant.h"

// Example function
double function(double x)
{
	return sin((1.0/4.0)*x+10)+(1.0/6.0)*x;
}

// Example function's derivative
double function_prime(double x)
{
	return (1.0/4.0)*cos((1.0/4.0)*x+10)+(1.0/6.0);
}

int main()
{
	double root;
	printf("\nHYBRID (SECANT)\n");
	root = bisection_secant(function, -500, 500, -200, -190, 0.00001, 1000);
	printf("The root of the function with tolerance 0.00001 is:\n");
	printf("%f\n", root);
	printf("The function evaluated at root is f(root) = %f\n\n", function(root));

	return 0;
}
