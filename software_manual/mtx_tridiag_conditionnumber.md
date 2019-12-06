# Condition Number of Matrix (Tridiagonal)
**Function Prototype**: ```double mtx_tridiag_conditionnumber(int n, double* au, double* ad, double* al, double tolerance, int max_iterations);```

**Header File**: mtx_tridiag_conditionnumber.h

**Author**: Ethan Ancell

**Language**: C. This code can be compiled with the GNU C compiler (gcc).

**Description/Purpose**: This function will return the condition number of a tridiagonal matrix. It is often used as a measure of closeness to a singular matrix.

**Input**:
* ```int n``` - The size of the square matrix.
* ```double* au``` - A pointer to the upper diagonal of the matrix.
* ```double* ad``` - A pointer to the main diagonal of the matrix.
* ```double* al``` - A pointer to the lower diagonal of the matrix.
* ```double tolerance``` - How close the successive guesses to the eigenvalues will be when the termination condition for the iterative method is reached. The approximations of eigenvalues is an internal computation involved when finding the condition number.
* ```int max_iterations``` - A maximum number of times that the iterative method should loop through.

**Output**: Returns a double value that contains the approximation to the condition number of the tridiagonal matrix.

**Usage Example**: [This code](../software/eigen/mtx_tridiag_conditionnumber_example.c) is an example of code that will run the condition number of a randomly generated matrix that is symmetric and diagonally dominant.

The output from when I ran the code is the following:

![Console output](images/mtx_tridiag_conditionnumber.png)

**Code**: Link to the source code of the tridiagonal condition number can be found [here.](../shared_library/src/mtx_tridiag_conditionnumber.c)
