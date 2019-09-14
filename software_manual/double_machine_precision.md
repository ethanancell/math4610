# Double Machine Precision
**Function Name**: int double\_machine\_precision(int print\_results)

**Header File**: double\_machine\_precision.h

**Author**: Ethan Ancell

**Language**: C. This code can be compiled with the GNU C compiler (gcc).

**Description/Purpose**: This code will return the number of iterations that it takes in order to eradicate the most precision that a double data type can hold. The process to doing this entails setting an "epsilon", and through each loop of the main program divide that epsilon by two. Eventually, the difference between a number one and the number one plus the epsilon will have no difference, and that's how we know that we have reached our machine precision.

**Input**: Takes one value of 0 or 1 in "print\_results" as to whether we should be printing out the results as we go. 
**Output**: Return type is integer with number of iterations. If the process specifies the print\_results then in the console we will be printing out all of the iterations and the final step as we go. Whether or not print\_results is specified, the function will return an integer with the number of iterations it took to eradicate the machine precision.

**Usage Example** If we call:
```
printf("The double precision took %d iterations.\n", double_machine_precision(0));
```
We will see an output in the console of:
```
The double precision took 54 iterations.\n"
```

**Code**: Link to this code can be found [here.](https://github.com/ethanancell/math4610/blob/master/shared_library/src/double_machine_precision.c)
