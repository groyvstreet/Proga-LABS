#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

void OptimalTariff(bool dataFilled, int minutesInNet, int minutesInOtherNet, int smsAmount, int megabytes)
{
    float costTariff[6];
    int min;
    int index;
    int i;
    float noLimits[8] = {0.052, 500.0, 0.104, 500.0, 0.078, 0.0, 0.0, 25.89};
    float comfortM[8] = {0.0, 0.0, 0.104, 120.0, 0.078, 0.0208, 10.0, 21.73};
    float comfortL[8] = {0.0, 0.0, 0.0, 0.0, 0.078, 0.0208, 25.0, 31.09};
    float comfortXL[8] = {0.0, 0.0, 0.0, 0.0, 0.078, 0.0208, 50.0, 41.49};
    float comfortS[8] = {0.0, 0.0, 0.104, 60.0, 0.078, 0.0208, 1.0, 13.83};
    float start[8] = {0.0, 0.0, 0.104, 10.0, 0.078, 0.0208, 0.5, 8.93};

    system("clear");

    if (dataFilled)
    {
        costTariff[0] = CostTariff(minutesInNet, minutesInOtherNet, smsAmount, megabytes, noLimits);
        costTariff[1] = CostTariff(minutesInNet, minutesInOtherNet, smsAmount, megabytes, comfortM);
        costTariff[2] = CostTariff(minutesInNet, minutesInOtherNet, smsAmount, megabytes, comfortL);
        costTariff[3] = CostTariff(minutesInNet, minutesInOtherNet, smsAmount, megabytes, comfortXL);
        costTariff[4] = CostTariff(minutesInNet, minutesInOtherNet, smsAmount, megabytes, comfortS);
        costTariff[5] = CostTariff(minutesInNet, minutesInOtherNet, smsAmount, megabytes, start);

        printf("Cost No Limits - %.4f\nCost Comfort M - %.4f\nCost Comfort L - %.4f\nCost Comfort XL - %.4f\nCost Comfort S - %.4f\nCost Start - %.4f\n\n",
               costTariff[0], costTariff[1], costTariff[2], costTariff[3], costTariff[4], costTariff[5]);

        min = costTariff[0];
        index = 0;

        for (i = 1; i < 6; i++)
        {
            if (costTariff[i] < min)
            {
                min = costTariff[i];
                index = i;
            }
        }

        if (index == 0)
        {
            printf("Optimal tariff - No Limits\n\n");
        }
        else if (index == 1)
        {
            printf("Optimal tariff - Comfort M\n\n");
        }
        else if (index == 2)
        {
            printf("Optimal tariff - Comfort L\n\n");
        }
        else if (index == 3)
        {
            printf("Optimal tariff - Comfort XL\n\n");
        }
        else if (index == 4)
        {
            printf("Optimal tariff - Comfort S\n\n");
        }
        else if (index == 5)
        {
            printf("Optimal tariff - Start\n\n");
        }
    }
    else
    {
        printf("The data is incomplete!\n\n");
    }

    printf("Press any key to continue...");
    getch();
    system("clear");
}

void TariffInfo(float *tariff, char *text)
{
    printf("%s\n", text);
    printf("Outgoing within the network - %.4f rub.\n", tariff[0]);
    printf("Free minutes within the network - %.4f\n", tariff[1]);
    printf("Calls to other networks - %.4f rub.\n", tariff[2]);
    printf("Free minutes to other networks - %.4f\n", tariff[3]);
    printf("SMS - %.4f rub.\n", tariff[4]);
    printf("Internet traffic - %.4f rub.\n", tariff[5]);
    printf("Free gigabytes - %.4f\n", tariff[6]);
    printf("Subscription fee - %.4f rub.\n\n", tariff[7]);
}

void List(float *noLimits, float *comfortM, float *comfortL, float *comfortXL, float *comfortS, float *start)
{
    system("clear");
    TariffInfo(noLimits, "No Limits");
    TariffInfo(comfortM, "Comfort M");
    TariffInfo(comfortL, "Comfort L");
    TariffInfo(comfortXL, "Comfort XL");
    TariffInfo(comfortS, "Comfort S");
    TariffInfo(start, "Start");
    printf("Press any key to continue...");
    getch();
    system("clear");
}

void ContactInfo()
{
    system("clear");
    printf("For A1 communication services, please call:\n");
    printf("\t150 - single contact center number (the call is free from all networks of Belarusian operators)\n");
    printf("\t7100 - (from an A1 mobile number – 0.03 rub.)\n");
    printf("\twhen roaming by phone +375 29 6 000 150 (payment according to roaming tariffs)\n\n");
    printf("Email address for services to individuals: 150@A1.by\n");
    printf("Email address for processing applications of legal entities: legal@A1.by\n");
    printf("Email address for advice on services to legal entities: corp@A1.by\n\n");
    printf("Media representatives can address any questions about A1 work to the head of the corporate communications department Nikolay Bredelev by phone +375 29 604 06 94, as well as atn.bredelev@A1.by\n\n");
    printf("For participation in the procurement of goods and services by Unitary Enterprise A1, provision of commercial offers, contact us at:\n");
    printf("\tprocurement@A1.by\n");
    printf("\tzakupki@A1.by\n\n");
    printf("Press any key to continue...");
    getch();
    system("clear");
}

#ifndef TESTING

int main()
{
    int minutesInNet, minutesInOtherNet;
    int smsAmount;
    int megabytes;
    char select;
    bool dataFilled;
    float noLimits[8] = {0.052, 500.0, 0.104, 500.0, 0.078, 0.0, 0.0, 25.89};
    float comfortM[8] = {0.0, 0.0, 0.104, 120.0, 0.078, 0.0208, 10.0, 21.73};
    float comfortL[8] = {0.0, 0.0, 0.0, 0.0, 0.078, 0.0208, 25.0, 31.09};
    float comfortXL[8] = {0.0, 0.0, 0.0, 0.0, 0.078, 0.0208, 50.0, 41.49};
    float comfortS[8] = {0.0, 0.0, 0.104, 60.0, 0.078, 0.0208, 1.0, 13.83};
    float start[8] = {0.0, 0.0, 0.104, 10.0, 0.078, 0.0208, 0.5, 8.93};

    dataFilled = false;
    system("clear");

    while (true)
    {
        printf("1 - Enter the data\n");
        printf("2 - Calculate the optimal tariff\n");
        printf("3 - List of tariffs\n");
        printf("4 - Contact info\n");
        printf("0 - Exit\n");
        scanf("%s", &select);

        if (select == '1')
        {
            dataFilled = FillData(&minutesInNet, &minutesInOtherNet, &smsAmount, &megabytes);
        }
        else if (select == '2')
        {
            OptimalTariff(dataFilled, minutesInNet, minutesInOtherNet, smsAmount, megabytes);
        }
        else if (select == '3')
        {
            List(noLimits, comfortM, comfortL, comfortXL, comfortS, start);
        }
        else if (select == '4')
        {
            ContactInfo();
        }
        else if (select == '0')
        {
            system("clear");
            break;
        }
        else
        {
            system("clear");
        }
    }

    return 0;
}

#endif

int Amount(char *text)
{
    bool inputCorrect;
    char input[10];
    int i;

    do
    {
        inputCorrect = true;
        printf(text);
        scanf("%s", input);

        for (i = 0; i < strlen(input); i++)
        {
            if (!isdigit(input[i]))
            {
                inputCorrect = false;
            }
        }

        if (!inputCorrect)
        {
            printf("Invalid input!\n\n");
        }
    } while (!inputCorrect);

    return atoi(input);
}

float CostTariff(int minutesInNet, int minutesInOtherNet, int smsAmount, int megabytes, float *tariff)
{
    float part1, part2, part3;

    if (minutesInNet - tariff[1] > 0)
    {
        part1 = minutesInNet - tariff[1];
    }
    else
    {
        part1 = 0;
    }

    if (minutesInOtherNet - tariff[3] > 0)
    {
        part2 = minutesInOtherNet - tariff[3];
    }
    else
    {
        part2 = 0;
    }

    if (megabytes - tariff[6] * 1024 > 0)
    {
        part3 = megabytes - tariff[6] * 1024;
    }
    else
    {
        part3 = 0;
    }

    return part1 * tariff[0] + part2 * tariff[2] + smsAmount * tariff[4] + part3 * tariff[5] + tariff[7];
}

bool FillData(int *minutesInNet, int *minutesInOtherNet, int *smsAmount, int *megabytes)
{
    system("clear");
    *minutesInNet = Amount("Enter the number of minutes of conversations within the network per month: ");
    system("clear");
    printf("The number of minutes of conversations within the network - %d\n", *minutesInNet);
    *minutesInOtherNet = Amount("Enter the number of minutes of conversations in other networks per month: ");
    system("clear");
    printf("The number of minutes of conversations within the network - %d\n", *minutesInNet);
    printf("The number of minutes of conversations in other networks - %d\n", *minutesInOtherNet);
    *smsAmount = Amount("Enter the number of SMS per month: ");
    system("clear");
    printf("The number of minutes of conversations within the network - %d\n", *minutesInNet);
    printf("The number of minutes of conversations in other networks - %d\n", *minutesInOtherNet);
    printf("The number of SMS - %d\n", *smsAmount);
    *megabytes = Amount("Enter the number of megabytes per month: ");
    system("clear");
    printf("The number of minutes of conversations within the network - %d\n", *minutesInNet);
    printf("The number of minutes of conversations in other networks - %d\n", *minutesInOtherNet);
    printf("The number of SMS - %d\n", *smsAmount);
    printf("The number  of megabytes per month - %d\n\n", *megabytes);
    printf("Press any key to continue...");
    getch();
    system("clear");

    return true;
}
