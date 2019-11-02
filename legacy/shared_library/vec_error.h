#ifndef VEC_ERROR_
#define VEC_ERROR_

double vec_absolute_error_1(double x_approx[], double x[], size_t length);
double vec_absolute_error_2(double x_approx[], double x[], size_t length);
double vec_absolute_error_inf(double x_approx[], double x[], size_t length);

double vec_relative_error_1(double x_approx[], double x[], size_t length);
double vec_relative_error_2(double x_approx[], double x[], size_t length);
double vec_relative_error_inf(double x_approx[], double x[], size_t length);

#endif
