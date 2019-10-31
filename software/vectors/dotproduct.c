#include <stdio.h>
#include "../headers/vec_product.h"

int main()
{
	double u[] = {1, 2, 3, 4, 5};
	double v[] = {1.4, 1.9, 3.4, 4.0, 5.3};
	int length = 5;

	printf("\nWith u = {1, 2, 3, 4, 5} and v = {1.4, 1.9, 3.4, 4.0, 5.3}\n");
	printf("The dot product is %f\n\n", vec_dotproduct(u, v, length));

	return 0;
}
