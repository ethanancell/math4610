// Reduce the linear system into an upper triagular system using
// Gaussian elimination.
void mtx_echelon(int n, double* a, double* b)
{
	double factor;

	// Loop over "diagonal" in the form of columns
	for (int k=0; k < n-1; k++)
	{
		// Loop over rows downward
		for (int i=k+1; i<n; i++)
		{
			// At each row, we have a factor that reduces the row.
			// This row is applied to all the columns out.
			factor = *(a+(i*n)+k) / *(a+(k*n)+k);
			for (int j=k+1; j<n; j++)
			{
				*(a+(i*n)+j) = *(a+(i*n)+j) - factor * *(a+(k*n)+j);
			}
			*(b+i) = *(b+i) - factor * *(b+k);
		}
	}
}
