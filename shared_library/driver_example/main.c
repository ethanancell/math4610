#include <stdio.h>

#include "../src/absolute_error.h"
#include "../src/double_machine_precision.h"

int main()
{
	printf("absolute error of 4.5 and 4.643 is %f\n", absolute_error(4.5, 4.643));

	printf("The double machine precision iterations is %d\n", double_machine_precision(0));

	return 0;
}
