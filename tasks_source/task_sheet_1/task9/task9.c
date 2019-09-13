/* Function to compute the derivative of the exponential function at pi. */

#include <math.h>
#include <stdio.h>
#include "absolute_error.h"
#include "relative_error.h"

double calculate_exponential_derivative(double x, double h)
{
	double numerator = exp(x+h) - exp(x-h);
	double denominator = (x+h) - (x-h);

	return numerator / denominator;
}

int main()
{
	// Use this to store the true value of the derivative
	double exact_derivative = exp(M_PI);
	double approximate_derivative;
	
	// We will incrementally calculate the derivative of the exponential
	// function at PI and then record the error with both the absolute and relative error functions.
	double h = 1.0;
	double tolerance = 0.00001;
	double error = 10 * tolerance;
	double current_relative_error;

	int max_iterations = 100;
	int iterations = 0;

	while(iterations < max_iterations && error >= tolerance)
	{
		approximate_derivative = calculate_exponential_derivative(M_PI, h);
		
		// Here we use the absolute error function in the shared library
		error = absolute_error(exact_derivative, approximate_derivative);

		// Here we use the relative error function in the shared library
		// We don't use this for part of the functionality of the problem but we will still
		// print it for the interesting factor.
		current_relative_error = relative_error(exact_derivative, approximate_derivative);	

		h /= 2;

		printf("Approximate derivative is %f \t\tAbsolute error: %f \t\tRelative error: %f\n",
				approximate_derivative, error, current_relative_error);
		iterations++;
	}
	printf("\nTolerance has been reached. The derivative is %f\n", approximate_derivative);

	return 0;
}
