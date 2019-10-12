#include <stdio.h>
#include <math.h>

#include "../../../shared_library/src/bisection.h"

// Function to test the bisection method.
double f(double x)
{
	return x*cosh(x) + pow(x, 3) - M_PI;
}

int main()
{
	double a = -1;
	double b = 4;
	double tolerance = 0.00001;

	double root = bisection(f, a, b, tolerance);
	printf("\nBisection method:\n");
	printf("Left window bound: %f\n", a);
	printf("Right window bound: %f\n", b);
	printf("Tolerance: %f\n\n", tolerance);

	printf("Bisection calculated root: %f\n", root);
	printf("f(root) = %f\n\n", f(root));

	return 0;
}
