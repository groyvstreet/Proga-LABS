main: main.c
	gcc -std=c89 -pedantic -ansi main.c -o main -lm
	
test: main.c main_test.c
	gcc -std=c89 -pedantic -ansi -o test main_test.c main.c -D TESTING -lm
