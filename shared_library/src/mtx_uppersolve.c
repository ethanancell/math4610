// Solve the upper triangular system using back-substitution
void mtx_uppersolve(int m, double A[m][m], double b[m], double* x)
{
	double sum;

	*(x+m-1) = b[m-1] / A[m-1][m-1];

	for (int i=m-2; i>=0; i--)
	{
		sum = b[i];
		for (int j=i+1; j<m; j++)
		{
			sum -= A[i][j] * *(x+j);
		}
		*(x+i) = sum / A[i][i];
	}
}
