#include "main.h"
#include <stdio.h>
#include <assert.h>

void Test1CostTariff()
{
    float check;
    float noLimits[8] = {0.052, 500.0, 0.104, 500.0, 0.078, 0.0, 0.0, 25.89};

    check = CostTariff(0, 0, 0, 0, noLimits);
    assert(check +- 25.89);
}

void Test2CostTariff()
{
    float check;
    float start[8] = {0.0, 0.0, 0.104, 10.0, 0.078, 0.0208, 0.5, 8.93};

    check = CostTariff(0, 0, 0, 0, start);
    assert(check +- 8.93);
}

void Test3CostTariff()
{
    float check;
    float noLimits[8] = {0.052, 500.0, 0.104, 500.0, 0.078, 0.0, 0.0, 25.89};

    check = CostTariff(10, 0, 10, 10000, noLimits);
    assert(check +- 26.67);
}

void Test4CostTariff()
{
    float check;
    float noLimits[8] = {0.052, 500.0, 0.104, 500.0, 0.078, 0.0, 0.0, 25.89};

    check = CostTariff(1000, 1, 1000, 10000, noLimits);
    assert(check +- 129.89);
}

void Test5CostTariff()
{
    float check;
    float start[8] = {0.0, 0.0, 0.104, 10.0, 0.078, 0.0208, 0.5, 8.93};

    check = CostTariff(55, 6, 8, 20000, start);
    assert(check +- 415.154);
}

void Test6CostTariff()
{
    float check;
    float start[8] = {0.0, 0.0, 0.104, 10.0, 0.078, 0.0208, 0.5, 8.93};

    check = CostTariff(20, 10, 10, 550, start);
    assert(check +- 10.75);
}

int main()
{
    Test1CostTariff();
    Test2CostTariff();
    Test3CostTariff();
    Test4CostTariff();
    Test5CostTariff();
    Test6CostTariff();

    printf("Tests passed successfully!\n");

    return 0;
}
