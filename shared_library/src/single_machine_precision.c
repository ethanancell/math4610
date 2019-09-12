#include <stdio.h>

int single_machine_precision(int print_results)
{
	// Single Precision
	float one = 1.0;
	float eps = 1.0;

	float diff;

	int i;
	for(i=1; i<1001; i++)
	{
		diff = one - (one + eps);
		if(print_results)
			printf("diff: %f, eps: %f\n", diff, eps);
		if(diff == 0.0)
		{
			if(print_results)
				printf("Iterations: %d\n", i);
			break;
		}
		eps = 0.5 * eps;
	}
	if(print_results)
		printf("Size of float is %d\n", sizeof(float));
	
	return i;
}
