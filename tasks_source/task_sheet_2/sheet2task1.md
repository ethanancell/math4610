# Tasksheet 2, Task 2
In this task we must set up a root finding problem for the equation:
```
x * cosh(x) + x^3 = pi
```
I chose to set up this problem by using fixed point iteration. If we consider our f(x) to be the following:
```
f(x) = x * cosh(x) + x^3 - pi
```
We must construct some g(x) such that the derivative of g(x) will be less than one. I decided to let my g(x) be the following:
```
g(x) = x - (1/50)*(x * cosh(x) + x^3 - pi)
```
The derivative of this equation will be less than one for much of the domain, which allows the functional iteration to converge to the true answer. The actual code that will implement this fixed point iteration will be done in task 3.
