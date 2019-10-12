# Function Title
**Function Name**: ```bisection(double (*function)(), double a, double b, double tolerance)```

**Header File**: bisection.h

**Author**: Ethan Ancell

**Language**: C. This code can be compiled with the GNU C compiler (gcc).

**Description/Purpose**: This function will calculate the root for a function using the bisection method. We require a function pointer to the function we wish to take the root of, a window to search over, and a tolerance to the root. The bisection method will return the guess of the root over that window.

**Input**: 
* double (\*function)() - A function pointer to the function that we wish to find the root of.
* double a - The left bound of x for the window that we will search over for the root.
* double b - The right bound of x for the window that we will search over for the root.
* double tolerance - How close within the real root we should be after we finished iterating through the bisection method.

**Output**: Returns a double with the guess of the root of the function.

**Usage Example**: Here will we will demonstrate the bisection method on the following function:
```
f(x) = xcosh(x) + x^3 - pi
```
We will use a left bound of -1, a right bound of 4, and a tolerance of 0.00001. The complete code that will perform this example can be found [here.](https://github.com/ethanancell/math4610/blob/master/tasks_source/task_sheet_2/sheet2task8/bisection_example.c)

The output from the code that uses the bisection method is:

![Console Output Picture](../images/s2_t8_cmdoutput.png)

**Code**: Link to the bisection method code can be found [here](https://github.com/ethanancell/math4610/blob/master/shared_library/src/bisection.c)
