#include "../headers/mtx_vec_multiply.h"
#include <stdio.h>
#include <stdlib.h>

void print_matrix(int m, int n, double A[m][n])
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%.2f ", A[i][j]);
		}
		printf("\n");
	}
}

void print_matrix_vector(int m, int n, double A[m][n], double* x, double* result)
{
	printf("\n");
	for(int i=0; i<m; i++)
	{
		printf("[");
		for(int j=0; j<n; j++)
		{
			printf("%.2f ", A[i][j]);
		}
		if(i != 1) {
			printf("] [%.2f]   [%.2f]\n", *(x+i), *(result+i));
		}
		else
		{
			printf("]X[%.2f] = [%.2f]\n", *(x+i), *(result+i));
		}
	}
	printf("\n");
}

void print_vector(int m, double* x)
{
	for(int i=0; i<m; i++)
	{
		printf("%.2f\n", *(x+i));
	}
}

int main()
{
	double A[3][3] = {{1, 2, 3},
					 {4, 5, 6},
					 {7, 8, 9}};

	double x[] = {1,3,5};
	double* destination = malloc(sizeof(double) * 3);

	mtx_vec_multiply(3, 3, A, x, destination);
	print_matrix_vector(3, 3, A, x, destination);

	free(destination);

	return 0;
}
