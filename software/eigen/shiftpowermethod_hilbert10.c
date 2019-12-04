#include <stdio.h>
#include <stdlib.h>

#include "../headers/gen_mtxhilbert.h"
#include "../headers/mtx_inversepowermethod.h"
#include "../headers/mtx_powermethod.h"
#include "../headers/mtx_shiftpowermethod.h"

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

	// What are the small and big eigenvalues?
	double smallest_eigenvalue = mtx_inversepowermethod(SIZE, a, ones, 0.0001, 1000);
	double largest_eigenvalue = mtx_powermethod(SIZE, a, ones, 0.0001, 1000);

	// What is the middle?
	double middle_eigenvalue = mtx_shiftpowermethod(SIZE, a, ones, (smallest_eigenvalue+largest_eigenvalue) / 2.0, 0.0001, 1000);

	printf("\nSmallest eigenvalue of size %d Hilbert matrix: %f\n", SIZE, smallest_eigenvalue);
	printf("Largest eigenvalue of size %d Hilbert matrix: %f\n", SIZE, largest_eigenvalue);
	printf("A middle eigenvalue of size %d Hilbert matrix: %f\n\n", SIZE, middle_eigenvalue);

	// Try another guess
	double middle_eigenvalue2 = mtx_shiftpowermethod(SIZE, a, ones, 2.50, 0.0001, 1000);
	printf("Another guess at the eigenvalue 2.53089 is the following: %f\n\n", middle_eigenvalue2);

	free(a);
}
