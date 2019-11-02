#include <stdio.h>

#include "../headers/vec_norm_inf.h"

int main()
{
	double u[] = {1,2,3,4};
	printf("\nThe infinity norm of the vector <1,2,3,4> is %f\n\n", vec_norm_inf(u, 4));
	return 0;
}
