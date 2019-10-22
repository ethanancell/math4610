# Hybrid Root Finding - Bisection and Newton's Method
**Function Name**: ```bisection_newton(double (*function)(), double (*function_prime)(), double a, double b, double x0, double tolerance, int max_iterations)```

**Header File**: hybrid_roots.h

**Author**: Ethan Ancell

**Language**: C. This code can be compiled with the GNU C compiler (gcc).

**Description/Purpose**: This function will calculate the root for a function using bisection and Newton's method. We require a function, the function's derivative, a window, and an initial guess. The hybrid method utilizes the bisection method to narrow down the interval to a range where Newton's method will converge. In this manner, we can utilize the benefits of both the stability of the bisection method and also the quickness of convergence in Newton's method.

**Input**:
* double (\*function)() - A function pointer to the function that we wish to find the root of.
* double (\*function_prime)() - The derivative of the funcion that we wish to find the root of.
* double a - The left side of the window that we are finding the root over.
* double b - The right side of the window that we are finding the root over.
* double x0 - An initial guess for where the root might be.
* double tolerance - How close within the real root we should be.
* int max_iterations - The maximum amount of times we should loop through Newton's method before we exit. This is placed so that our code does not accidentally create some infinite loop.

**Output**: Returns a double with the guess of the root of the function.

**Usage Example**: Here we demonstrate the hybrid method on the following function:
```
f(x) = sin((1/4)x + 10) + (1/6)x
```
We also need the derivative to find the root with the Newton's part of the hybrid method:
```
f'(x) = (1/4)cosh((1/4)x + 10) + (1/6)
```
The example code to utilize the bisection and Newton hybrid method on this function with a tolerance of 0.00001 and maximum iterations of 1000 can be found [here.](https://github.com/ethanancell/math4610/blob/master/shared_library/function_examples/bisection_newton.c)

The output from the code that uses the hybrid method is:

![Console Output Picture](https://github.com/ethanancell/math4610/blob/master/shared_library/function_examples/images/bisection_newton.png)

**Code**: Link to the hybrid method code can be found [here.](https://github.com/ethanancell/math4610/blob/master/shared_library/src/hybrid_roots.c) in the first function.
