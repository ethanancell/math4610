void mtx_diagsolve(int m, double A[m][m], double b[m], double* x)
{
	int i;
	for (i=0; i<m; i++)
	{
		*(x+i) = b[i] / A[i][i];
	}
}
