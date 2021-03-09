#include "main.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>

void Test1CostTariff()
{
    float check;
    float e = 0.005;
    float noLimits[8] = {0.052, 500.0, 0.104, 500.0, 0.078, 0.0, 0.0, 25.89};

    check = CostTariff(0, 0, 0, 0, noLimits);
    assert(fabs(check - 25.89) < e);
}

void Test2CostTariff()
{
    float check;
    float e = 0.005;
    float start[8] = {0.0, 0.0, 0.104, 10.0, 0.078, 0.0208, 0.5, 8.93};

    check = CostTariff(0, 0, 0, 0, start);
    assert(fabs(check - 8.93) < e);
}

void Test3CostTariff()
{
    float check;
    float e = 0.005;
    float noLimits[8] = {0.052, 500.0, 0.104, 500.0, 0.078, 0.0, 0.0, 25.89};

    check = CostTariff(10, 0, 10, 10000, noLimits);
    assert(fabs(check - 26.67) < e);
}

void Test4CostTariff()
{
    float check;
    float e = 0.005;
    float noLimits[8] = {0.052, 500.0, 0.104, 500.0, 0.078, 0.0, 0.0, 25.89};

    check = CostTariff(1000, 1, 1000, 10000, noLimits);
    assert(fabs(check - 129.89) < e);
}

int main()
{
    Test1CostTariff();
    Test2CostTariff();
    Test3CostTariff();
    Test4CostTariff();

    printf("Tests passed successfully!\n");

    return 0;
}