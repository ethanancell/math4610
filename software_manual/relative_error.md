## Relative Error
**Function Name**: double relative\_error(double true\_value, double approximation)

**Header File**: relative\_error.h

**Author**: Ethan Ancell

**Language**: C. This code can be compiled with the GNU C compiler (gcc).

**Description/Purpose**: This function will calculate the relative error between the precise number and the approximation to that number.

**Input**: Two double numbers are inputted, one called "true\_value" and one called "approximation". We must be careful to not use a value of zero for the true\_value, since the relative error is undefined for that value.

**Output**: Return type is double for the relative error. This function will return the relative difference between the true value of the number and the approximation to that number in the form of a proportion in terms to the true value.

**Usage Example**: An example below is given with the absolute error of the true value of 4.5 and its approximation of 4.643.
```
printf("The relative error of 4.5 and 4.643 is %f\n", relative_error(4.5, 4.643));
```
After including this line somewhere in a program, the output from that line will be the following:
```
The relative error of 4.5 and 4.643 is 0.031778
```

**Code**: A link to the code can be found [Here](../shared_library/src/relative_error.c)
