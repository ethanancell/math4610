#include <stdlib.h>

void mtx_vec_multiply (int m, int n, double A[m][n], double x[], double* destination)
{
	double sum;

	// loop through rows of matrix
	for(int i=0; i<m; i++)
	{
		sum = 0.0;
		// loop through columns of matrix
		for(int j=0; j<n; j++)
		{
			sum += A[i][j] * x[j];
		}
		*(destination+i) = sum;
	}
}
