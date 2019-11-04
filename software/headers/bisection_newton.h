#ifndef BISECTION_NEWTON_
#define BISECTION_NEWTON_

double bisection_newton (double (*function)(), double (*function_prime)(), double a, double b, double x0, double tolerance, int max_iterations);

#endif
