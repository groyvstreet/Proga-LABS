#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>

typedef struct node
{
    int digit;
    struct node *next;
    struct node *prev;
} Node;

typedef struct bigNumber
{
    Node *head;
    Node *tail;
    int size;
} BigNumber;

BigNumber CreateBigNumber(char *initStr);
void PrintBigNumber(BigNumber number);
void AddDigit(BigNumber *number, int digit);
BigNumber SumBigNumber(BigNumber n1, BigNumber n2);
BigNumber MultiBigNumber(BigNumber n1, BigNumber n2);
BigNumber MinusOne(BigNumber number);
BigNumber FactBigNumber(BigNumber number);
bool CompareBigNumber(BigNumber n1, BigNumber n2);

#endif
