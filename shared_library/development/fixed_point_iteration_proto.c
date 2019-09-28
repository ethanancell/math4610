#include <math.h>
#include <stdio.h>

double my_function(double x)
{
	return x * cosh(x) + pow(x, 3) - M_PI;
	//return pow(x, 4) - x - 10;
}

double gmy_function(double x)
{

	return x - (1.0/50.0) * my_function(x);
	//return pow(x+10.0, 0.25);
}

double fixed_point_iteration (double (*gfunction)(),
			      double x0,
			      double tolerance,
			      int max_iterations)
{
	double error;
	double x1;
	int iterations = 0;

	do {
		x1 = gfunction(x0);
		printf("x1 is %f\n", x1);
		error = fabs(x1 - x0);
		x0 = x1;
		iterations++;
	}
	while (error > tolerance && iterations < max_iterations);

	// At the end of it, our best guess is x1 so we will return that.
	printf("Iterations was %d\n", iterations);
	return x1;
}

int main()
{
	double root = fixed_point_iteration(gmy_function, 0.5, 0.00000001, 5000);
	printf("Root of function is %f\n", root);
	printf("F of function is %f\n", my_function(root));
	return 0;
}
