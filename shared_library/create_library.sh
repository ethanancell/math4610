cd src
gcc -c *.c
mv *.o ../object
cd ..
ar rcv lib_math4610.a object/*.o
ranlib lib_math4610.a
