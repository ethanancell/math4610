cd src
gcc -c *.c
mv *.o ../object
cd ..
ar rcv lib_math4610.a object/*.o
ranlib lib_math4610.a
cp lib_math4610.a ../software/
cd src
cp *.h ../../software/headers
