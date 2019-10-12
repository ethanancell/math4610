# Tasksheet 2 - Task 2

We know that an associated function to the equation that will help us understand the equation ```xcosh(x)+x^3=pi``` will be the following:
```
f(x) = xcosh(x) + x^3 - pi = 0
```
If we wish to set up two associated fixed point iterations for this function, then we will create two associated g(x) functions, that evaluate to x when we plug in the root x*.
```
g(x*) = x*
```
Possible converted function:
```
g(x) = x + f(x)
g(x) = x + xcosh(x) + x^3 - pi
```
Another possible converted function:
```
g(x) = x - (1/8)f(x)
g(x) = x - (1/8)(xcosh(x) + x^3 - pi)
```
