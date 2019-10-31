#include <stdio.h>
#include <stdlib.h>
#include "../headers/vec_product.h"

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
	double u[] = {1, 2, 3};
	double v[] = {4, 1, 7};

	printf("\nWith u = {1, 2, 3} and v = {4, 1, 7}\n");
	printf("The cross product is\n");

	double* cp = vec_crossproduct(u, v);
	print_vector(cp, 3);
	printf("\n");

	free(cp);

	return 0;
}
