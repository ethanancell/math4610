# Linear System Solving (Method of Steepest Descent)
**Function Prototype**: ```void mtx_steepestdescentsolve(int n, double* a, double* b, double* x, double tolerance);```

**Header File**: mtx_steepestdescentsolve.h

**Author**: Ethan Ancell

**Language**: C. This code can be compiled with the GNU C compiler (gcc).

**Description/Purpose**: This function will take a square matrix, perform a method of steepest descent utilizing the system of equations and the b matrix, and will store a solution to the system in the location pointed to by x, within a sensitivity of "tolerance".

**Input**:
* ```int n``` - The rows and columns of the matrix and solution vectors.
* ```double* a``` - A pointer to the array that contains the matrix.
* ```double* b``` - A pointer to the b vector.
* ```double* x``` - A pointer to where the solution will be stored.
* ```double tolerance``` - A measure of sensitivity used in the steepest descent calculations.

**Output**: The result from performing the steepest descent solving will be stored in the memory location pointed to by x.

**Usage Example**: [This code](../software/matrix/mtx_steepestdescentsolve_example.c) will
create a diagonally dominant matrix, and will multiply that matrix into a
vector of ones for the b vector, and then after solving the system of equations
we hope to see a vector of ones as the solution vector.

The resulting output is the following:

![Console Output](images/mtx_steepestdescentsolve.png)

**Code**: Link to the source code for the library code is
stored [here.](../shared_library/src/mtx_steepestdescentsolve.c)
