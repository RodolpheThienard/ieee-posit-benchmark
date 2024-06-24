CC=/home/rodolphe/posit-gcc/bin/gcc
FLAGS=-lm -msoft-float 
OBJECTS= vector_reduction example main


.phony: ieee posit
all: $(OBJECTS)

%:%.c libposit.a
	$(CC) -o $@_posit  $(FLAGS) -fposit -m32 -DPOSIT $@.c libposit.a
	$(CC) -o $@_ieee $(FLAGS) $@.c libposit.a

clean:
	$(RM) vector_reduction_*
	$(RM) example_*
