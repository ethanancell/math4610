#include <stdio.h>
#include <math.h>

#include "../src/relative_error.h"
#include "../src/double_machine_precision.h"
#include "../src/single_machine_precision.h"
#include "../src/bisection.h"

// Example function to test the bisection method.
double ethan_function(double n)
{
	return tan(n) * log(n) + 1;
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


	return 0;
}
