GCC_FLAGS = -Wall -g

all: Principal

%.o: %.c %.h
	gcc $(GCC_FLAGS) -c $<

Principal:  Pile.o Pile.h Postfixe.o Postfixe.h Tests.o Tests.h Principal.c Principal.h
	gcc $(GCC_FLAGS) Pile.o Postfixe.o Tests.o Principal.c -o Principal

clean: 
	rm *.o
