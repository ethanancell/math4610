# Tasksheet 2 - Task 1
In this task we must set up a root finding problem for the equation:
```
x * cosh(x) + x^3 = pi
```
If we wish to create a function that we can find the root of in order to solve for "x" in the above equation, a good choice would be to choose the associated function:
```
f(x) = x * cosh(x) + x^3 - pi = 0
```
This function would be a good way to set up the root finding problem, because finding what "x" that lets "f(x)" evaluate to 0 would be the same x that you plug in the very top equation to get an equality.

We will solve this function using the bisection method. All that is required to set up the root finding problem that involves the bisection method is to choose a window \[a, b\] for where the root is.

We will set the window to be \[0, 2\].

Another requirement of the bisection method is that the function that we are finding the root of must be continuous on the interval. The function f(x) outlined above is continuous and well-defined in the interval and there are no places where the function can not be evaluated. This fulfills all requirements of the bisection method.

In the next task, Task 2, we will set up two fixed point iteration root finding problems for the above equation.
