#include <stdio.h>
#include <stdlib.h>
#include "../headers/vec_add.h"
#include "../headers/vec_subract.h"
#include "../headers/vec_scale.h"

void print_vector(double* vector, int length)
{
	printf("{");
	for(int i=0; i<length-1; i++)
	{
		printf("%f, ", *(vector+i));
	}
	printf("%f}\n", *(vector+length-1));
}

int main()
{
	double u[] = {1, 2, 3, 4, 5};
	double v[] = {1.4, 1.9, 3.4, 4.0, 5.3};
	size_t length = 5;

	double* addition = vec_add(u, v, length);
	double* subtraction = vec_subtract(u, v, length);
	double* scalar = vec_scale(3, u, length);

	printf("\nPertaining to the vector u = {1, 2, 3, 4, 5} and\n");
	printf("v = {1.4, 1.9, 3.4, 4.0, 5.3}, here are some vector operations:\n");
	printf("u + v = ");
	print_vector(addition, length);
	printf("u - v = ", vec_subtract(u, v, length));
	print_vector(subtraction, length);
	printf("3 * u = ", vec_scale(3 ,u, length));
	print_vector(scalar, length);
	printf("\n");

	free(addition);
	free(subtraction);
	free(scalar);

	return 0;
}
