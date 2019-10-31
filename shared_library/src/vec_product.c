#include <stdlib.h>

double vec_dotproduct(double u[], double v[], int length)
{
	double sum = 0.0;
	for(int i=0; i<length; i++)
	{
		sum += u[i] * v[i];
	}

	return sum;
}

// In the vector cross product, we assume that the length
// is 3.
double* vec_crossproduct(double u[], double v[])
{
	double* crossproduct = malloc(sizeof(double) * 3);

	*crossproduct = u[1]*v[2] - u[2]*v[1];
	*(crossproduct+1) = u[2]*v[0] - u[0]*v[2];
	*(crossproduct+2) = u[0]*v[1] - u[1]*v[0];

	return crossproduct;
}
