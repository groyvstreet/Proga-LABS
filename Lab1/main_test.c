#include "main.h"

#include <stdio.h>
#include <assert.h>
#include <conio.h>

void Test1StrMax(){
    int max;
    max = StrMax("qwe", "qw");

    assert(max == 3);
}

void Test2StrMax(){
    int max;
    max = StrMax("qw", "qwe");

    assert(max == 3);
}

void Test3StrMax(){
    int max;
    max = StrMax("qwe", "qwe");

    assert(max == 3);
}

int main() {
	Test1StrMax();
    Test2StrMax();
    Test3StrMax();
	
	printf("Tests passed successfully!\n");
    getch();

	return 0;
}
