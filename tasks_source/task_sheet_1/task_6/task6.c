/* Task 6 - show the approximation of a derivative using the one-sided difference quotient
 * until the machine precision creeps in and starts to cause problems. */

#include <stdio.h>
#include <math.h>

// This will be the actual function "object" that we use, that we will be calculating the derivative of.
double example_function(double x)
{
	// In this case for an example, I will use the sine function from the math library.
	return sin(x);
}

double calculate_derivative(double x, double h)
{
	double numerator = example_function(x+h) - example_function(x-h);
	double denominator = (x+h) - (x-h);

	return numerator / denominator;
}

int main()
{
	double h = 1;
	for(int i=0; i<100; i++)
	{
		printf("Approximation to derivative: %.14f\n", calculate_derivative(2, h));
		printf("H: %.14f Iteration: %d\n\n", h, i);
		h = h / 2;
	}

	return 0;
}
