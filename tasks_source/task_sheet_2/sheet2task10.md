# Tasksheet 2 - Task 10

I found a great resource from Anne E. Farwick at Xavier University on fixed point iteration.

Apparently, fixed point iteration has huge application when solving large sparse systems of equations, because 
it is computationally very difficult to find the inverse of a large sparse matrix (largely filled with zeros) 
in finding the solution to the system of equations.
However, it is not very computationally difficult to multiply by zero, so a fixed point iterative scheme can be set up
to solve this problem by finding the root to b-Ax, and iterating through a sequence of solutions until it approaches the root
and solves the system of sparse equations. Restrictions still are placed on the g(x) function, which has to have a "spectral radius"
convergence condition.

[Link to Page, slides 14-15](http://www.cs.xu.edu/~david.gerberry/Student/AnnieFarwick_SeniorProject.pdf)
