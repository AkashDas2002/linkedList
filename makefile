all: dwstring.o main.o
	gcc -o program dwstring.o main.o

dwstring.o: dwstring.c dwstring.h
	gcc -c dwstring.c

main.o: main.c headers.h
	gcc -c main.c

run:
	./program

clean:
	rm *.o
	rm *~
