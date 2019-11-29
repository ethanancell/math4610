void gen_mtxhilbert(int n, double* a)
{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			*(a+(i*n)+j) = 1.0 / (i+j+1);
		}
	}
}
