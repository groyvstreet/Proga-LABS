#include <stdio.h>
#include <assert.h>
#include "main.h"

void Test1CreateArr()
{
    int **arr;
    arr = CreateArr(arr, 3, 4);
    assert(arr != NULL);
}

void Test2CreateArr()
{
    int **arr;
    arr = CreateArr(arr, 10, 20);
    assert(arr != NULL);
}

void Test3CreateArr()
{
    int **arr;
    arr = CreateArr(arr, 10000, 10000);
    assert(arr == NULL);
}

void Test4CreateArr()
{
    int **arr;
    arr = CreateArr(arr, 10000000, 10000);
    assert(arr == NULL);
}

int main()
{
    Test1CreateArr();
    Test2CreateArr();
    Test3CreateArr();
    Test4CreateArr();
    printf("Tests passed successfully!\n");

    return 0;
}
