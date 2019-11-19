# Tasksheet 6 - Task 10

I discovered that even though diagonally dominant matrices
will always converge, the true condition that needs to be
met for the matrix to converge is that the magnitude of the
largest eigenvalue of "M" must be less than one, where ```M=D^-1(A-D)```, and it just so happens that all diagonally dominant matrices fulfill this condition. I also learned in this article that iterative methods for solutions to linear systems are typically reserved to large matrices, especially sparse matrices. I also learned that there are some systems of equations where Jacobi iteration will converge, but Gauss-Seidel will not.

My source is found [here.](http://mathfaculty.fullerton.edu/mathews/n2003/GaussSeidelMod.html)
