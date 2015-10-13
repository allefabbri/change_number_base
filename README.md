# change_number_base
This repo contains 3 examples of a number converter, namely a tool for converting an input number (base-10) to any integer base representation.

#### Purpose
These examples illustrates how to obtain the same result using different approaches:
* ANSI-C with pointers
* ANSI-C with structures
* C++ with std containers

#### Installation/Run
Simple as ``make all``

#### Usage
The file ``const.h`` contains, through preprocessor definitions, the number to be converted and the new base.

#### Sample output
```
---- Making C++ ----
g++ -std=c++11 -o cxx.exe num_basis.cpp
./cxx.exe
Base 10 -> 3876344
Base 256 -> 59 37 248
Base 10 -> 3876344
---- Making ANSI C ----
gcc -o ansic.exe num_basis.c
./ansic.exe
Base 10 -> 3876344
Base 256 -> 59 37 248  
Base 10 -> 3876344
---- Making ANSI C (struct version) ----
gcc -o struct.exe num_basis_struct.c
./ansic.exe
Base 10 -> 3876344
Base 256 -> 59 37 248  
Base 10 -> 3876344
```
