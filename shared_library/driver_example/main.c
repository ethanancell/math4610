#include <stdio.h>

#include "src/absolute_error.h"
#include "src/double_machine_precision.h"

int main()
{
	printf("absolute error of 3 and 3.3 is %f\n", absolute_error(3.0, 3.3));

	printf("The double machine precision iterations is %d\n", double_machine_precision(0));

	return 0;
}
