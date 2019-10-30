#include <stdio.h>

#include "../headers/vec_norm.h"

int main()
{
	double u[] = {1,2,3,4};
	printf("\nThe 2-norm of the vector <1,2,3,4> is %f\n\n", vec_norm_2(u, 4));
	return 0;
}
