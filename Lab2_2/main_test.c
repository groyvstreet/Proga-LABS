#include "main.h"
#include <stdio.h>
#include <assert.h>

void Test1Calcu1()
{
    int n;

    n = Calcu1(5, 1);
    assert(n == 6);
}

void Test2Calcu1()
{
    int n;

    n = Calcu1(1, 1);
    assert(n == 1);
}

void Test3Calcu1()
{
    int n;

    n = Calcu1(0, 0.0001);
    assert(n == 1);
}

void Test4Calcu1()
{
    int n;

    n = Calcu1(5, 0.0000001);
    assert(n == 12);
}

void Test1Calcu2()
{
    int n;

    n = Calcu1(0, 1);
    assert(n == 1);
}

void Test2Calcu2()
{
    int n;

    n = Calcu1(4.5, 1.2);
    assert(n == 5);
}

void Test3Calcu2()
{
    int n;

    n = Calcu1(-12, 0.09);
    assert(n == 16);
}

void Test4Calcu2()
{
    int n;

    n = Calcu1(-0.003, 0.089);
    assert(n == 1);
}

int main()
{   
    Test1Calcu1();
    Test2Calcu1();
    Test3Calcu1();
    Test4Calcu1();
    Test1Calcu2();
    Test2Calcu2();
    Test3Calcu2();
    Test4Calcu2();
    
    printf("Tests passed successfully!\n");

    return 0;
}