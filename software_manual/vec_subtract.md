# Vector Subtraction
**Function Name**: ```double* vec_subtract(double u[], double v[], size_t length)```

**Header File**: vec_subract.h

**Author**: Ethan Ancell

**Language**: C. This code can be compiled with the GNU C compiler (gcc).

**Description/Purpose**: This function will subtract v from u and return a pointer to the result.

**Input**:
* double u[] - the first vector
* double v[] - the second vector

**Output**: Returns a pointer to the vector that is created from the subtraction of the two. Make sure to free the memory in the pointer at the end of your program.

**Usage Example**: Example code using the vector operations can be found [here.](https://github.com/ethanancell/math4610/blob/master/software/vectors/operations.c)

The output from the console is the following:

![Console Output](images/vec_operations.png)

**Code**: Link to the source code for vector operations is [here.](https://github.com/ethanancell/math4610/blob/master/shared_library/src/vec_subtract.c)
