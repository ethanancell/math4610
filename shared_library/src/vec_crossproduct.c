#include <stdlib.h>

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
