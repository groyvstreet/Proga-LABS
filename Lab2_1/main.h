#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>

void OptimalTariff(bool dataFilled, int minutesInNet, int minutesInOtherNet, int smsAmount, int megabytes);
void TariffInfo(float *tariff, char *text);
void List(float *noLimits, float *comfortM, float *comfortL, float *comfortXL, float *comfortS, float *start);
void ContactInfo();
int Amount(char *text);
float CostTariff(int minutesInNet, int minutesInOtherNet, int smsAmount, int megabytes, float *tariff);
bool FillData(int *minutesInNet, int *minutesInOtherNet, int *smsAmount, int *megabytes);

#endif
