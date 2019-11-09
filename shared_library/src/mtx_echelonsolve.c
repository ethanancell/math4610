// Reduce the linear system into an upper triagular system using
// Gaussian elimination, and then solve the system
void mtx_echelonsolve(int n, double* a, double* b, double* x)
{
	/*
	 * Step 1: Reduce the matrix to row echelon form.
	 */
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


	/*
	 * Step 2: Solve the upper triangular system using back-substitution
	 */
	double sum;

 	*(x+n-1) = *(b+n-1) / *(a+((n-1)*n)+n-1);

	for (int i=n-2; i>=0; i--)
	{
		sum = *(b+i);
		for (int j=i+1; j<n; j++)
		{
			sum -= *(a+(i*n)+j) * *(x+j);
		}
		*(x+i) = sum / *(a+(i*n)+i);
	}
}
