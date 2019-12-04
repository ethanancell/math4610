#include "mtx_inversepowermethod.h"
#include "mtx_powermethod.h"

double mtx_conditionnumber(int n, double* a, double tolerance, int max_iterations)
{
	// Vector of ones for initial guess
	double ones[n];
	for (int i=0; i<n; i++)
	{
		ones[i] = 1;
	}

	// Get largest and smallest eigenvalues
	double largest_eigenvalue = mtx_powermethod(n, a, ones, tolerance, max_iterations);
	double smallest_eigenvalue = mtx_inversepowermethod(n, a, ones, tolerance, max_iterations);

	return largest_eigenvalue / smallest_eigenvalue;
}
