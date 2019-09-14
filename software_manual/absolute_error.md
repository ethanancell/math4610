## Absolute Error
**Function Name**: double absolute\_error(double true\_value, double approximation)

**Header File**: absolute\_error.h

**Author**: Ethan Ancell

**Language**: C. This code can be compiled with the GNU C compiler (gcc).

**Description/Purpose**: This function will calculate the absolute error between the precise number and the approximation to that number.

**Input**: Two double numbers are inputted, one called "true\_value" and one called "approximation".

**Output**: Return type is double for the absolute error. This function will return the absolute difference between the true value of the number and the approximation to that number.

**Usage Example**: An example below is given with the absolute error of the true value of 4.5 and its approximation of 4.643.
```
printf("The absolute error of 4.5 and 4.643 is %f\n", absolute_error(4.5, 4.643));
```
After including this line somewhere in a program, the output from that line will be the following:
```
The absolute error of 4.5 and 4.643 is 0.143000
```

**Code**: The source for this code can be found [here.](../shared_library/src/absolute_error.c)
