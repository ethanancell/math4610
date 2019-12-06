void mtx_tridiagonal_multiply(int n, double* au, double* ad, double* al, double* x, double* y)
{
	// Initialize y to zero
	for (int i=0; i<n; i++)
	{
		*(y+i) = 0;
	}
	// Diagonal
	for (int i=0; i<n; i++)
	{
		*(y+i) += *(ad+i) * *(x+i);
	}
	// Upper
	for (int i=0; i<n-1; i++)
	{
		*(y+i) += *(au+i) * *(x+i+1);
	}
	// Lower
	for (int i=0; i<n-1; i++)
	{
		*(y+i+1) += *(al+i+i) * *(x+i);
	}
}
