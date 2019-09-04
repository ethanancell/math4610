#include <stdio.h>

int main()
{
	// Single Precision
	float one = 1.0;
	float eps = 1.0;

	float diff;

	int i;
	for(i=0; i<1001; i++)
	{
		diff = one - (one + eps);
		printf("diff: %f, eps: %f\n", diff, eps);
		if(diff == 0.0)
		{
			printf("Iterations: %d\n", i);
			break;
		}
		eps = 0.5 * eps;
	}
	printf("Size of float is %d\n", sizeof(float));

	// Double
	double one_d = 1.0;
	double eps_d = 1.0;

	double diff_d;

	for(i=0; i<1001; i++)
	{
		diff_d = one_d - (one_d + eps_d);
		printf("diff_d: %f, eps_d: %f\n", diff_d, eps_d);
		if(diff_d == 0.0)
		{
			printf("Iterations: %d\n", i);
			break;
		}
		eps_d = 0.5 * eps_d;
	}
	printf("Size of double is %d\n", sizeof(double));

	return 0;
}
