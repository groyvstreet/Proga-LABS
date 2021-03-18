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

void Test1CreateArr3D()
{
    int ***arr;
    arr = CreateArr3D(arr, 100, 100, 20);
    assert(arr != NULL);
}

int main()
{
    Test1CreateArr();
    Test2CreateArr();
    Test1CreateArr3D();
    printf("Tests passed successfully!\n");

    return 0;
}
