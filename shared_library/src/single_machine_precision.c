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
	
	return 0;
}
