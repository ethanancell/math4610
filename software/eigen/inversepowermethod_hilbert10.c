#include <stdio.h>
#include <stdlib.h>

#include "../headers/gen_mtxhilbert.h"
#include "../headers/mtx_inversepowermethod.h"

#define SIZE 10

int main()
{
	double* a = malloc(SIZE * SIZE * sizeof(double));
	gen_mtxhilbert(SIZE, a);

	double ones[SIZE];
	for (int i=0; i<SIZE; i++)
	{
		ones[i] = 1;
	}

	// Now what is the smallest eigenvalue?
	double smallest_eigenvalue = mtx_inversepowermethod(SIZE, a, ones, 0.0001, 1000);

	printf("\nSmallest eigenvalue of size %d Hilbert matrix:\n", SIZE);
	printf("%f\n\n", smallest_eigenvalue);

	free(a);
}
