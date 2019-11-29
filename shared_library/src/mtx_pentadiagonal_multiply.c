void mtx_pentadiagonal_multiply(int n, double* auu, double* au, double* ad, double* al, double* all, double* x, double* y)
{
	// Diagonal
	for (int i=0; i<n; i++)
	{
		*(y+i) = *(ad+i) * *(x+i);
	}

	// Upper
	for (int i=0; i<n-1; i++)
	{
		*(y+i) += *(au+i) * *(x+i+1);
	}

	// Upper upper
	for (int i=0; i<n-2; i++)
	{
		*(y+i) += *(auu+i) * *(x+i+2);
	}

	// Lower
	for (int i=0; i<n-1; i++)
	{
		*(y+i+1) += *(al+i+1) * *(x+i);
	}

	// Lower lower
	for (int i=0; i<n-2; i++)
	{
		*(y+i+2) += *(al+i+2) * *(x+i);
	}
}
