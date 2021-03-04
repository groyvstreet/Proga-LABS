#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

#include "main.h"

void PrintSpace(int amount)
{
    int i;

    for (i = 0; i < amount; i++)
    {
        printf(" ");
    }
}

void PrintLine(int amount)
{
    int i;

    for (i = 0; i < amount; i++)
    {
        printf("-");
    }
}

#ifndef TESTING

int main()
{
    bool inputCorrect;
    char strK[50], strL[50];
    int k, l;
    int i, j;
    int *addend;
    int multi;
    char strMulti[10];
    int max;
    char temp[10];
    int indent1, indent2;

    do
    {
        inputCorrect = true;
        printf("Enter k and l: ");
        scanf("%s%s", strK, strL);

        for (i = 0; i < strlen(strK); i++)
        {
            if (!isdigit(strK[i]) || strK[0] < '1')
            {
                inputCorrect = false;
            }
        }

        for (i = 0; i < strlen(strL); i++)
        {
            if (!isdigit(strL[i]) || strL[0] < '1')
            {
                inputCorrect = false;
            }
        }

        if (!inputCorrect)
        {
            printf("Invalid input!\n\n");
        }
        else
        {
            if (strlen(strK) > 10 || strlen(strL) > 10)
            {
                inputCorrect = false;
                printf("Overflow!\n\n");
            }
            else
            {
                k = atoi(strK);
                l = atoi(strL);

                if (k * l < 0)
                {
                    inputCorrect = false;
                    printf("Overflow!\n\n");
                }
            }
        }

    } while (!inputCorrect);

    addend = (int *)malloc(strlen(strL) * sizeof(int));

    for (i = strlen(strL) - 1, j = 0; i >= 0; i--, j++)
    {
        addend[j] = ((int)strL[i] - 48) * k;
    }

    multi = k * l;
    itoa(multi, strMulti, 10);
    PrintSpace(strlen(strMulti) - strlen(strK));
    printf("%s\n", strK);
    PrintSpace(strlen(strMulti) - strlen(strL));
    printf("%s\n", strL);
    max = StrMax(strK, strL);
    PrintSpace(strlen(strMulti) - max);
    PrintLine(max);
    printf("\n");
    indent2 = 0;

    for (i = 0; i < strlen(strL); i++)
    {
        itoa(addend[i], temp, 10);
        indent1 = strlen(strMulti) - strlen(temp) - indent2;
        PrintSpace(indent1);
        printf("%d", addend[i]);
        printf("\n");
        indent2++;
    }

    free(addend);
    PrintLine(strlen(strMulti));
    printf("\n");
    printf(strMulti);
    printf("\n");

    return 0;
}

#endif

int StrMax(char *str1, char *str2)
{
    int max;

    if (strlen(str1) >= strlen(str2))
    {
        max = strlen(str1);
    }
    else
    {
        max = strlen(str2);
    }

    return max;
}
 
