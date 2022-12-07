CFLAGS = "-std=c99"
gol.o: main.c
	gcc -o gol.o main.c -I. $(CFLAGS)
clean:
	rm -f gol.o
