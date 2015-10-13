all: cxx ansic struct

struct:
	@echo ---- Making ANSI C (struct version) ----
	gcc -o struct.exe num_basis_struct.c
	./ansic.exe


ansic:
	@echo ---- Making ANSI C ----
	gcc -o ansic.exe num_basis.c
	./ansic.exe

cxx:
	@echo ---- Making C++ ----
	g++ -std=c++11 -o cxx.exe num_basis.cpp
	./cxx.exe