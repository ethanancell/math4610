# Tasksheet 3 - Task 3
The function that we are trying to find the root of using the four known functions is the following:
```
f(x) = x*cosh(x) + x^3 - pi = 0
```
We will find the root of the function using each of the four known methods, and compare and contrast each of them as needed.

For all of the root finding methods, we will be using a tolerance of 0.00001 as an input and a maximum iterations of 1000.

## Functional Iteration
As part of the requirements of functional iteration, we need to have a transformed g(x) for the function.
As an additional requirement, we need the absolute value of the derivative of the transformed function g(x) to be less than
1 at the root of the function.

As it turns out, the following function works well for functional iteration of this method:
```
g(x) = x - (1/8)(xcosh(x) + x^3 - pi)
```
Code that performs the functional iteration of this method is found [here.](https://github.com/ethanancell/math4610/blob/master/tasks_source/task_sheet_2/sheet2task3/task3.c)

We observe the following output:

![Console Output Picture](https://github.com/ethanancell/math4610/blob/master/images/s2_t7_cmdoutput.png)

This function was able to converge rapidly to the root and performs well, but for this function it was very difficult
to find that alternative function g(x) such that the absolute value of its derivative was less than one around the root.
To do that, I used some function visualization on Desmos and was able to tweak around a function g(x) so that I
could see its derivative was less than one at that value. If this were a case where I couldn't use that visualization,
functional iteration would have been very hard to implement for this problem because finding that g(x) would have
involved a lot of guesswork.

## Bisection Method
As part of the requirements of the bisection method, we need to have a window for the function. I elected
for a left bound of -1 and a right bound of 4. Aside from the left and right bound, I don't need much more to
implement the bisection method.

The code that performs bisection for this function can be found [here.](https://github.com/ethanancell/math4610/blob/master/tasks_source/task_sheet_2/sheet2task8/bisection_example.c)

The observe the following output:

![Console Output Picture](https://github.com/ethanancell/math4610/blob/master/images/s2_t8_cmdoutput.png)

The bisection was a very stable and performant option for root finding of this function. It only required a left
and right bound, which was not hard to choose because I knew my root was roughly around the number 1. So far, this
method seems to be a lot more stable than functional iteration was with less requirements.

## Newton's Method
For Newton's method, the requirement that we need to meet is we need to provide the function's derivative along with an initial guess. For the function that we were given, the derivative will be the following:
```
f'(x) = cosh(x) - xsinh(x) + 3x^2
```
We will use an initial guess of 1, because that is around the neighborhood of the root that we have been seeing in the previous methods.

The code that performs Newton's method for this function can be found [here.](https://github.com/ethanancell/math4610/blob/master/shared_library/function_examples/newton_root.c)

The output from Newton's method is the following:

![Console Output Picture](https://github.com/ethanancell/math4610/blob/master/images/s3_t1_cmdoutput.png)

For this function, a derivative was not very hard to find, because it simply involved a product rule along with a power rule. For a function that is a lot more complicated, it might be really difficult to find a derivative, which makes it hard to satisfy the requirements of Newton's method. Additionally, if we didn't know what the function looked like or in what general region the root lies, it would be hard to provide an initial guess.

For this function, the Newton's method worked out very well with very quick convergence because we were able to easily find a derivative and an initial guess.

## Secant Method
For the secant method, we need only the function and two initial guesses. I will provide an initial guess of 1, and also an initial guess of 1.05.

The code that performs the secant method for this function can be found [here.](https://github.com/ethanancell/math4610/blob/master/shared_library/function_examples/secant_root.c)

The output from the console from the code using the secant method is the following:

![Console Output Picture](https://github.com/ethanancell/math4610/blob/master/images/s3_t2_cmdoutput.png)

In my experience, the secant method provided the best result with a very minimal amount of setup, so I would elect to use this method for this specific case. I only needed to provide two numbers roughly around where the root is.

## Overview
After implementing each of the methods for that same function, I would choose the secant method for that problem. Although all of the methods worked quite nicely, all I had to do with the secant method was plug in two initial guesses for the function and I got a very good result. As seen in the output for the secant method, the function evaluated at that root was exactly 0 down to whatever machine precision is displayed, so it provided a very good result with low setup.
