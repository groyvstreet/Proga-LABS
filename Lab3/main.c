#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

void PrintArr(int **arr, int size1, int size2)
{
    int i, j;

    for (i = 0; i < size1; i++)
    {
        for (j = 0; j < size2; j++)
        {
            printf("%d", arr[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

void ClearArr2D(int **arr, int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        free(arr[i]);
    }

    free(arr);
}

void ClearArr3D(int ***arr, int size1, int size2)
{
    int i, j;

    for (i = 0; i < size1; i++)
    {
        for (j = 0; j < size2; j++)
        {
            free(arr[j]);
        }

        free(arr[i]);
    }

    free(arr);
}

#ifndef TESTING

int main()
{
    bool validInput;
    int l, m, n;
    char input1[10], input2[10], input3[10];
    int i, j, y;
    int ***array;
    int **projection1, **projection2, **projection3;

    do
    {
        validInput = true;
        printf("Enter array size: ");
        scanf("%s%s%s", input1, input2, input3);

        for (i = 0; i < strlen(input1); i++)
        {
            if (!isdigit(input1[i]) || input1[0] < '1')
            {
                validInput = false;
            }
        }

        for (i = 0; i < strlen(input2); i++)
        {
            if (!isdigit(input2[i]) || input2[0] < '1')
            {
                validInput = false;
            }
        }

        for (i = 0; i < strlen(input3); i++)
        {
            if (!isdigit(input3[i]) || input3[0] < '1')
            {
                validInput = false;
            }
        }

        if (!validInput)
        {
            system("cls");
            printf("Invalid input!\n\n");
        }
    } while (!validInput);

    l = atoi(input1);
    m = atoi(input2);
    n = atoi(input3);
    array = (int ***)calloc(l, l * sizeof(int **));
    srand(time(NULL));

    for (i = 0; i < l; i++)
    {
        array[i] = (int **)calloc(m, m * sizeof(int *));

        for (j = 0; j < m; j++)
        {
            array[i][j] = (int *)calloc(n, n * sizeof(int));

            for (y = 0; y < n; y++)
            {
                array[i][j][y] = rand() % 2;
                printf("%d", array[i][j][y]);
            }

            printf("\n");
        }

        printf("\n");
    }

    if (array == NULL)
    {
        printf("Not enough memory!");
    }
    else
    {

        projection1 = CreateArr(projection1, l, m);
        projection2 = CreateArr(projection2, l, n);
        projection3 = CreateArr(projection3, n, m);

        if (projection1 == NULL || projection2 == NULL || projection3 == NULL)
        {
            printf("Not enough memory!");
        }
        else
        {

            for (i = 0; i < l; i++)
            {
                for (j = 0; j < m; j++)
                {
                    for (y = 0; y < n; y++)
                    {
                        if (array[i][j][y] == 1)
                        {
                            projection1[i][j] = 1;
                            projection2[i][y] = 1;
                            projection3[y][j] = 1;
                        }
                    }
                }
            }

            ClearArr3D(array, l, m);
            printf("Projections: \n\n");
            PrintArr(projection1, l, m);
            PrintArr(projection2, l, n);
            PrintArr(projection3, n, m);
            ClearArr2D(projection1, l);
            ClearArr2D(projection2, l);
            ClearArr2D(projection3, n);
        }
    }

    return 0;
}

#endif

int **CreateArr(int **arr, int size1, int size2)
{
    int i, j;

    arr = (int **)calloc(size1, size1 * sizeof(int *));

    for (i = 0; i < size1; i++)
    {
        arr[i] = (int *)calloc(size2, size2 * sizeof(int));
    }

    return arr;
}
