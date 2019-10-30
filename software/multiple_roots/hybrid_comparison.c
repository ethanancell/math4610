#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#include "../headers/bisection.h"
#include "../headers/newton.h"
#include "../headers/secant.h"

// Variables we will need to access everywhere
int total_roots = 0;

// Function we are finding the roots of
double function(double x)
{
	return sin(M_PI*pow(x,2) + 3.7);
}

// Function derivative
double function_prime(double x)
{
	return 2*M_PI*x*cos(M_PI*pow(x,2) + 3.7);
}

// BISECTION
double* find_roots_bisection(double (*function)(), double a, double b, double step_size)
{
	total_roots = 0;
	int i;
	int iterations = (int) (b-a) / step_size;

	double fa, fb;

	// Start evaluating at left window point
	double xval = a;
	fa = function(xval);

	// All roots will be set to default value of 0 for no root
	int is_root[iterations];
	for(i=0; i<iterations; i++)
	{
		is_root[i] = 0;
	}

	// Search over iterations number of possible roots using step size.
	for(i=0; i<iterations; i++)
	{
		// If the function evalulates to less than zero for the small
		// window, then we set is_root at that step point to be true.
		xval += step_size;
		fb = function(xval);
		if(fa*fb < 0)
		{
			is_root[i] = 1;
		}

		fa = fb;
	}

	// What we will return
	double* root_locations = malloc(sizeof(double));

	for(i=0; i<sizeof(is_root) / sizeof(int); i++)
	{
		if(is_root[i])
		{
			total_roots++;
			root_locations = realloc(root_locations, total_roots * sizeof(double));
			*(root_locations+total_roots-1) = bisection(function, a+i*step_size, a+i*step_size + step_size, 0.00001);
		}
	}

	return root_locations;
}

// NEWTON
double* find_roots_newton(double (*function)(), double (*function_prime)(), double a, double b, double step_size)
{
	total_roots = 0;
	int i;
	int iterations = (int) (b-a) / step_size;

	double fa, fb;

	// Start evaluating at left window point
	double xval = a;
	fa = function(xval);

	// All roots will be set to default value of 0 for no root
	int is_root[iterations];
	for(i=0; i<iterations; i++)
	{
		is_root[i] = 0;
	}

	// Search over iterations number of possible roots using step size.
	for(i=0; i<iterations; i++)
	{
		// If the function evalulates to less than zero for the small
		// window, then we set is_root at that step point to be true.
		xval += step_size;
		fb = function(xval);
		if(fa*fb < 0)
		{
			is_root[i] = 1;
		}

		fa = fb;
	}

	// What we will return
	double* root_locations = malloc(sizeof(double));

	for(i=0; i<sizeof(is_root) / sizeof(int); i++)
	{
		if(is_root[i])
		{
			total_roots++;
			root_locations = realloc(root_locations, total_roots * sizeof(double));
			double newton_guess = (2*a+2*i*step_size+step_size) / 2.0;
			*(root_locations+total_roots-1) = newton(function, function_prime, newton_guess, 0.00001, 1000);
		}
	}

	return root_locations;
}

// SECANT
double* find_roots_secant(double (*function)(), double a, double b, double step_size)
{
	total_roots = 0;
	int i;
	int iterations = (int) (b-a) / step_size;

	double fa, fb;

	// Start evaluating at left window point
	double xval = a;
	fa = function(xval);

	// All roots will be set to default value of 0 for no root
	int is_root[iterations];
	for(i=0; i<iterations; i++)
	{
		is_root[i] = 0;
	}

	// Search over iterations number of possible roots using step size.
	for(i=0; i<iterations; i++)
	{
		// If the function evalulates to less than zero for the small
		// window, then we set is_root at that step point to be true.
		xval += step_size;
		fb = function(xval);
		if(fa*fb < 0)
		{
			is_root[i] = 1;
		}

		fa = fb;
	}

	// What we will return
	double* root_locations = malloc(sizeof(double));

	for(i=0; i<sizeof(is_root) / sizeof(int); i++)
	{
		if(is_root[i])
		{
			total_roots++;
			root_locations = realloc(root_locations, total_roots * sizeof(double));
			double secant_guess1 = (a+i*step_size) + (step_size / 3.0);
			double secant_guess2 = (a+i*step_size) + (2.0 * step_size / 3.0);
			*(root_locations+total_roots-1) = secant(function, secant_guess1, secant_guess2, 0.00001, 1000);
		}
	}

	return root_locations;
}



// COMPARE THE METHODS
int main()
{
	// Take the average of 100 times solving.
	double start;

	printf("\n");

	// BISECTION
	start = omp_get_wtime();
	for(int i=0; i<100; i++) {
		find_roots_bisection(function, 1.1, 68.3, 0.0001);
	}
	printf("Bisection: avg %f sec / solve\n", (omp_get_wtime() - start) / 100.0);

	// NEWTON
	start = omp_get_wtime();
	for(int i=0; i<100; i++) {
		find_roots_newton(function, function_prime, 1.1, 68.3, 0.0001);
	}
	printf("Newton: avg %f sec / solve\n", (omp_get_wtime() - start) / 100.0);

	// SECANT
	start = omp_get_wtime();
	for(int i=0; i<100; i++) {
		find_roots_secant(function, 1.1, 68.3, 0.0001);
	}
	printf("Secant:avg %f sec / solve\n", (omp_get_wtime() - start) / 100.0);

	printf("\n");

	return 0;
}
