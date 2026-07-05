gol: main.o main_utils.o
	gcc -g -Wall -o gol main.o main_utils.o 

main.o: main.c main.h 
	gcc -c main.c 

main_utils.o: main_utils.c main.h 
	gcc -c main_utils.c

clean:
	rm -f gol main.o main_utils.o 