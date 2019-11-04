// Solve the lower triangular system using forward substitution
void mtx_lowersolve(int m, double A[m][m], double b[m], double* x)
{
	double sum;

	*x = b[0] / A[0][0];

	for (int i=1; i<m; i++)
	{
		sum = b[i];
		for (int j=0; j<i; j++)
		{
			sum -= A[i][j] * *(x+j);
		}
		*(x+i) = sum / A[i][i];
	}
}
