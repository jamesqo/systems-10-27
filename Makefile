all: main.o
	gcc -o main main.o

main.o: main.c
	gcc -c main.c

clean:
	rm -f *.o
	rm -f *~

run: all
	./main
