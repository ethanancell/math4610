# Tasksheet 5 - Task 10

I found a site [here](http://mathfaculty.fullerton.edu/mathews/n2003/PivotingMod.html) that discusses different pivoting strategies as part of a write up on numerical linear algebra.

I learned that there are other pivoting strategies than we mentioned in class, such as "trivial" pivoting, where we only do a row swap if the proposed pivot is zero. This could reduce a lot of computational effort since we no longer have to loop through all the columns every single row we move through, but the downfall is that this only addresses the problems of zero and not any problems of numbers that might be close to machine precision but don't resolve to zero exactly. I also learned that "complete pivoting" can also be called "total pivoting", or "maximal pivoting".
