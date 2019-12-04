#include <stdio.h>
#include <stdlib.h>

#include "../headers/gen_mtxhilbert.h"
#include "../headers/mtx_conditionnumber.h"

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

	// Now what is the condition number?
	double cn = mtx_conditionnumber(SIZE, a, 0.0001, 1000);

	printf("\nCondition number of size %d Hilbert matrix:\n", SIZE);
	printf("%f\n\n", cn);

	free(a);
}
