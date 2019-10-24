#ifndef NEWTON_
#define NEWTON_

double newton (double (*function)(), double (*function_prime)(), double x0, double tolerance, int max_iterations);

#endif
