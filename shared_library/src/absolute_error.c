#include <math.h>

double absolute_error(double true_value, double approximation)
{
	// "fabs" function required in C because abs returns an integer.
	return fabs(true_value - approximation);
}
