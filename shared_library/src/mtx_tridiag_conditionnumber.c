#include "mtx_tridiag_powermethod.h"
#include "mtx_tridiag_inversepowermethod.h"

double mtx_tridiag_conditionnumber(int n, double* au, double* ad, double* al, double tolerance, int max_iterations)
{
	// Vector of ones for initial guess
	double ones[n];
	for (int i=0; i<n; i++)
	{
		ones[i] = 1;
	}

	// Get largest and smallest eigenvalues
	double largest_eigenvalue = mtx_tridiag_powermethod(n, au, ad, al, ones, tolerance, max_iterations);
	double smallest_eigenvalue = mtx_tridiag_inversepowermethod(n, au, ad, al, ones, tolerance, max_iterations);

	return largest_eigenvalue / smallest_eigenvalue;
}
