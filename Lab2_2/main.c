#include "main.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#ifndef TESTING

int main()
{
    bool inputCorrect;
    char input[15];
    int i;
    double x;
    double e;
    int n;

    do
    {
        inputCorrect = true;
        printf("Enter x: ");
        scanf("%s", input);

        for (i = 0; i < strlen(input); i++)
        {
            if (!isdigit(input[i]) && input[i] != '-' && input[i] != '.')
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
            x = atof(input);
        }

    } while (!inputCorrect);

    do
    {
        inputCorrect = true;
        printf("Enter e: ");
        scanf("%s", input);

        for (i = 0; i < strlen(input); i++)
        {
            if (!isdigit(input[i]) && input[i] != '.')
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
            e = atof(input);

            if (e <= 0)
            {
                inputCorrect = false;
                printf("Invalid input!\n\n");
            }
        }

    } while (!inputCorrect);

    n = Calcu1(x, e);

    printf("n = %d", n);

    return 0;
}

#endif

int Calcu1(double x, double e)
{
    double sinX;
    double polynom;
    double add;
    int deno;
    int n;

    sinX = sin(x);
    polynom = x;
    add = x;
    deno = 1;
    n = 1;

    if (n == 1)
    {
        printf("%.14f   ---   %.14f\n", sinX, polynom);

        if (fabs(sinX - polynom) < e)
        {
            return 1;
        }
    }

    do
    {
        n++;
        add *= -1;
        add *= x;
        add *= x;
        add /= ++deno;
        add /= ++deno;
        polynom += add;
        printf("%.14f   ---   %.14f\n", sinX, polynom);
    } while (fabs(sinX - polynom) >= e);

    return n;
}

int Calcu2(double x, double e, double polynom, double add)
{
    static int deno = 1;
    static int n = 1;
    double sinX;

    sinX = sin(x);

    if (n == 1)
    {
        printf("%.14f   ---   %.14f\n", sinX, polynom);

        if (fabs(sinX - polynom) < e)
        {
            return 1;
        }
    }

    n++;
    add *= -1;
    add *= x;
    add *= x;
    add /= ++deno;
    add /= ++deno;
    polynom += add;
    printf("%.14f   ---   %.14f\n", sinX, polynom);

    if (fabs(sinX - polynom) >= e)
    {
        n = Calcu2(x, e, polynom, add);
    }
    else
    {
        return n;
    }
}
