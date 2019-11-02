// OpenMP program to print Hello World
// using C language

#include <omp.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	// beginning of parallel region
	#pragma omp parallel
	{
		printf("Hello World from core = %d\n",
				omp_get_thread_num());
	}
	// end of parallel program
}
