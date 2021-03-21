#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "main.h"

#ifndef TESTING

int main()
{
    char *text;

    text = (char *)malloc(50 * sizeof(char));

    if (text == NULL)
    {
        printf("Not enough memory!");
        return 0;
    }

    printf("Enter a string: ");
    gets(text);
    text = MoveSym(text);
    printf(text);
    text = DifSym(text);
    printf("\n%s", text);
    return 0;
}

#endif

int StrLen(char *str)
{
    int res;

    res = 0;

    while (str[res] != '\0')
    {
        res++;
    }

    return res;
}

char *MoveSym(char *str)
{
    char *res;
    int i, j;

    res = (char *)malloc(50 * sizeof(char));

    if (res == NULL)
    {
        printf("Not enough memory!");
        exit(0);
    }

    res[0] = str[StrLen(str) - 1];

    for (i = 1, j = 0; j < StrLen(str) - 1; i++, j++)
    {
        res[i] = str[j];
    }

    res[i] = '\0';
    return res;
}

char *DelSym(char *str, int index)
{
    char *res;
    int i, j;

    res = (char *)malloc(50 * sizeof(char));

    if (res == NULL)
    {
        printf("Not enough memory!");
        exit(0);
    }

    for (i = 0, j = 0; i < StrLen(str); i++)
    {
        if (i != index)
        {
            res[j] = str[i];
            j++;
        }
    }

    res[j] = '\0';
    return res;
}

char *DifSym(char *str)
{
    int i, j;

    for (i = 0; i < StrLen(str); i++)
    {
        if (str[i] != ' ')
        {
            for (j = 0; j < StrLen(str); j++)
            {
                if (str[i] == str[j] && j > i)
                {
                    str = DelSym(str, j);
                }
            }
        }
    }

    return str;
}

bool Compare(char *str1, char *str2)
{
    int i;

    if (StrLen(str1) == StrLen(str2))
    {
        for (i = 0; i < StrLen(str1); i++)
        {
            if (str1[i] != str2[i])
            {
                return false;
            }
        }

        return true;
    }
    else
    {
        return false;
    }
}
