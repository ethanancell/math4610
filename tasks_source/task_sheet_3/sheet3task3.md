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
