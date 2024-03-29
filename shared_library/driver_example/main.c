#include <stdio.h>
#include <math.h>

#include "../src/relative_error.h"
#include "../src/double_machine_precision.h"
#include "../src/single_machine_precision.h"
#include "../src/bisection.h"
#include "../src/fixed_point_iteration.h"
#include "../src/newton.h"
#include "../src/secant.h"
#include "../src/hybrid_roots.h"
#include "../src/vec_norm.h"

// Example function to test the bisection method.
double ethan_function(double n)
{
	return tan(n) * log(n) + 1;
}





// Example function to test the fixed point iteration
double weird_function(double x)
{
	return x * cosh(x) + pow(x, 3) - M_PI;
}

// Example companion g function to go along with fixed point iteration
double g_weird_function(double x)
{
	return x - (1.0 / 50.0) * weird_function(x);
}

// Derivative of weird function to test newton's method
double weird_function_prime(double x)
{
	return cosh(x) - x*sinh(x) + 3*pow(x,2);
}

// Newtons function
double nf(double x)
{
	return 3*pow(x,3);
}

// Newtons function derivative
double nfp(double x)
{
	return 9*pow(x,2);
}

// Hybrid function test
double f2(double x)
{
	return sin((1.0/4.0)*x+10)+(1.0/6.0)*x;
}

// Hybrid function derivative
double f2p(double x)
{
	return (1.0/4.0)*cos((1.0/4.0)*x+10)+(1.0/6.0);
}




int main()
{
	printf("absolute error of 4.5 and 4.643 is %f\n", relative_error(4.5, 4.643));

	printf("The double machine precision iterations is %d\n", double_machine_precision(0));

	printf("The single machine precision iterations is %d\n", single_machine_precision(0));

	printf("\nBISECTION TEST\n");
	double root = bisection(ethan_function, 2, 4, 0.00001);
	printf("The root of the ethan function between 1.5 and 4 with tolerance of 0.00001 is:\n");
	printf("%f\n", root);
	printf("The function evaluated at root is f(root) = %f\n\n", ethan_function(root));

	// Fixed point
	printf("\nFIXED POINT\n");
	root = fixed_point_iteration(g_weird_function, 0, 0.00001, 10000);
	printf("The root of the weird function with tolerance of 0.00001 is:\n");
	printf("%f\n", root);
	printf("The function evaluated at root is f(root) = %f\n\n", weird_function(root));

	// Newton's method
	printf("\nNEWTON'S METHOD\n");
	root = newton(weird_function, weird_function_prime, 1, 0.0000001, 10000);
	printf("The root of the weird function with tolerance of 0.00001 is:\n");
	printf("%f\n", root);
	printf("The function evaluated at root is f(root) = %f\n\n", nf(root));

	// Secant method
	printf("\nSECANT METHOD\n");
	root = secant(weird_function, 1, 1.01, 0.00001, 10000);
	printf("The root of the weird function with tolerance of 0.00001 is:\n");
	printf("%f\n", root);
	printf("The function evaluated at root is f(root) = %f\n\n", weird_function(root));

	// Hybrid (newton)
	printf("\nHYBRID (NEWTON)\n");
	root = bisection_newton(f2, f2p, -500.0, 500.0, -50, 0.00001, 10000);
	printf("The root of the function with tolerance of 0.00001 is:\n");
	printf("%f\n", root);
	printf("The function evaluated at root is f(root) = %f\n\n", f2(root));

	// Vector stuff
	double u[] = {1.0, 2.0, 3.0};
	printf("2norm of <1,2,3> = %f\n", vec_norm_2(u, 3));
	printf("1norm of <1,2,3> = %f\n", vec_norm_1(u, 3));
	printf("inf norm of <1,2,3> = %f\n", vec_norm_inf(u, 3));


	return 0;

}
