#include <math.h>

double relative_error(double true_value, double approximation)
{
	return fabs(true_value - approximation) / true_value;
}
