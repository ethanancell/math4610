This is an example of how you will want to set up a file that will use the shared library functions.

In order to compile it, you will just add the shared library to the end of the gcc step, like:
gcc -o main main.c lib_math4610.a
