
TYPE = 

test: test.cpp
	gcc -Wall -o vector_dotprod vector_dotprod.cpp -lstdc++ -lfastposit
inf: inf.cpp
	gcc -Wall -o inf inf.cpp -lstdc++ -lfastposit
enumP8: enumP8.cpp
	gcc -Wall -o enumP8 enumP8.cpp -lstdc++ -lfastposit -fopenmp -lm
inverse: inverse.cpp
	gcc -Wall -o inverse inverse.cpp -lstdc++ -lfastposit  -lm -D$(TYPE)
conversion: conversion.cpp
	gcc -Wall -o conversion conversion.cpp -lstdc++ -lfastposit  -lm

