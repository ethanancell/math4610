#ifndef HYBRID_ROOTS_
#define HYBRID_ROOTS_

double bisection_newton (double (*function)(), double (*function_prime)(), double a, double b, double x0, double tolerance, int max_iterations);

double bisection_secant (double (*function)(), double a, double b, double x0, double x1, double tolerance, int max_iterations);

#endif
