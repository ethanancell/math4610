#include <stdio.h>
#include "../headers/vec_absolute_error_1.h"
#include "../headers/vec_absolute_error_2.h"
#include "../headers/vec_absolute_error_inf.h"

int main()
{
	double x[] = {1, 2, 3, 4, 5};
	double x_approx[] = {1.4, 1.9, 3.4, 4.0, 5.3};
	size_t length = 5;

	printf("\nPertaining to the vector {1, 2, 3, 4, 5} and its\n");
	printf("approximation {1.4, 1.9, 3.4, 4.0, 5.3}, here are the absolute errors:\n");
	printf("1-norm variant: %f\n", vec_absolute_error_1(x_approx, x, length));
	printf("2-norm variant: %f\n", vec_absolute_error_2(x_approx, x, length));
	printf("infinity norm variant: %f\n\n", vec_absolute_error_inf(x_approx, x, length));

	return 0;
}
