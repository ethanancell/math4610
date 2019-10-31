#include <stdio.h>
#include "../headers/saxpy.h"

void print_vector(float* vector, int length)
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
	float u[] = {1, 2, 3, 4, 5};
	float v[] = {1.4, 1.9, 3.4, 4.0, 5.3};
	float scalar = 3.5;
	size_t length = 5;

	printf("\nPertaining to the vector u = {1, 2, 3, 4, 5}, a scalar of 3.5\n");
	printf("for the vector u and v = {1.4, 1.9, 3.4, 4.0, 5.3}, the SAXPY results in:\n");
	saxpy(scalar, u, v, length);
	print_vector(v, 5);
	printf("\n");

	return 0;
}
