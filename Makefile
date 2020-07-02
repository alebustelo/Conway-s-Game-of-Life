ccflags-y := -std=c99
gol: main.c
	 gcc -o gol.o main.c -I.
