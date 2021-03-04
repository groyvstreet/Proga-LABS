main: main.c
	gcc -pedantic -ansi main.c -o main -lm
	
test: main.c main_test.c
	gcc -pedantic -ansi -o test main_test.c main.c -D TESTING -lm
