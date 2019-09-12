#include <stdio.h>

int double_machine_precision(int print_results)
{
	// Double
	double one_d = 1.0;
	double eps_d = 1.0;

	double diff_d;

	int i;
	for(i=1; i<1001; i++)
	{
		diff_d = one_d - (one_d + eps_d);
		if(print_results)
			printf("diff_d: %f, eps_d: %f\n", diff_d, eps_d);
		if(diff_d == 0.0)
		{
			if(print_results)
				printf("Iterations: %d\n", i);
			break;
		}
		eps_d = 0.5 * eps_d;
	}
	if(print_results)
		printf("Size of double in bytes is %d\n", sizeof(double));

	return i;
}
