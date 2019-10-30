# Tasksheet 4 - Task 1
To find if there is an advantage to using any of the hybrid
methods, the only difference will be if there is a faster computation
time involved with one over the other.

To test this out, I wrote a code that times the computation time for solving the
multiple root problem given in Task Sheet 2 Task 7 for each of the three methods.
The code that I used to time them can be found [here.](https://github.com/ethanancell/math4610/blob/master/software/multiple_roots/hybrid_comparison.c)

Here is the console output that timed the average time it took to solve the
multiple root problem over 100 times for each of the methods:

![Console Output](https://github.com/ethanancell/math4610/blob/master/images/s4_t1_cmdoutput.png)

For this case, Newton's method was the quickest. Looking through the roots that
were solved, they are the same in almost every case. Here are the root outputs
from tasks 7-9 on task sheet 2:

* [Bisection Roots](https://github.com/ethanancell/math4610/blob/master/software/multiple_roots/bisection_roots.txt)
* [Newton Roots](https://github.com/ethanancell/math4610/blob/master/software/multiple_roots/newton_roots.txt)
* [Secant Roots](https://github.com/ethanancell/math4610/blob/master/software/multiple_roots/secant_roots.txt)

Thus, we determine
that Newton's method is the best method to use in the hybrid situation for that
specific multiple root problem because it is computationally faster.
