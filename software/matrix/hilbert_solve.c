#include <stdio.h>
#include <stdlib.h>

#include "../headers/gen_mtxhilbert.h"
#include "../headers/mtx_steepestdescentsolve.h"
#include "../headers/mtx_vec_multiply.h"

#define TOLERANCE 0.00001

int main()
{
	int size = 4;
	int iterations = 1000;

	printf("\n");

	for (int i=0; i<iterations; i++)
	{
		double* a = malloc(size * size * sizeof(double));
		gen_mtxhilbert(size, a);
		double* ones = malloc(size * sizeof(double));
		for (int ii=0; ii<size; ii++)
		{
			*(ones+ii) = 1;
		}
		double* b = malloc(size * sizeof(double));
		double* x = malloc(size * sizeof(double));
		mtx_vec_multiply(size, size, a, ones, b);

		// Attempt the solving and print the solution
		mtx_steepestdescentsolve(size, a, b, x, TOLERANCE);
		printf("Solution to the size %d Hilbert system:\n", size);
		for (int ii=0; ii<size-1; ii++)
		{
			printf("%.3f, ", *(x+ii));
		}
		printf("%.3f", *(x+size-1));
		printf("\n\n");

		free(a);
		free(ones);
		free(b);
		free(x);
		size++;
	}
}
