#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "main.h"

#ifndef TESTING

int main()
{
    char input[100];
    int correct, i;
    BigNumber num;

    do
    {
        correct = 1;
        printf("Enter: ");
        scanf("%s", input);

        if(input[0] == '0')
        {
            correct = 0;
        }

        for(i = 0; i < strlen(input); i++)
        {
            if(!isdigit(input[i]))
            {
                correct = 0;
            }
        }
    } while (!correct);
    num = FactBigNumber(CreateBigNumber(input));
    PrintBigNumber(num);
    return 0;
}

#endif

BigNumber CreateBigNumber(char initStr[])
{
    BigNumber number = {NULL, NULL, 0};
    int i;

    for (i = strlen(initStr) - 1; i >= 0; i--)
    {
        AddDigit(&number, initStr[i] - '0');
    }

    return number;
}

void PrintBigNumber(BigNumber number)
{
    Node *p;

    p = number.tail;

    printf("\nNumber: ");

    while (p)
    {
        printf("%d", p->digit);
        p = p->prev;
    }
}

void AddDigit(BigNumber *number, int digit)
{
    Node *p;

    p = (Node *)malloc(sizeof(Node));

    p->digit = digit;
    p->next = p->prev = NULL;

    if (number->head == NULL)
    {
        number->head = number->tail = p;
    }
    else
    {
        number->tail->next = p;
        p->prev = number->tail;
        number->tail = p;
    }

    number->size++;
}

BigNumber SumBigNumber(BigNumber n1, BigNumber n2)
{
    BigNumber sum;
    Node *p1, *p2;
    int digit, pos, s1, s2;

    sum = CreateBigNumber("");
    p1 = n1.head;
    p2 = n2.head;
    pos = 0;

    while (p1 || p2)
    {
        if (p1)
        {
            s1 = p1->digit;
            p1 = p1->next;
        }
        else
        {
            s1 = 0;
        }

        if (p2)
        {
            s2 = p2->digit;
            p2 = p2->next;
        }
        else
        {
            s2 = 0;
        }

        digit = (s1 + s2 + pos) % 10;
        pos = (s1 + s2 + pos) / 10;
        AddDigit(&sum, digit);
    }

    if (pos)
    {
        AddDigit(&sum, pos);
    }

    return sum;
}

BigNumber MultiBigNumber(BigNumber n1, BigNumber n2)
{
    BigNumber multi, temp;
    Node *p1, *p2;
    int digit, pos, count, i;

    multi = CreateBigNumber("");
    temp = CreateBigNumber("");
    p1 = n1.head;
    p2 = n2.head;
    pos = 0;
    count = 0;

    while (p2)
    {
        while (p1)
        {
            digit = (p1->digit * p2->digit + pos) % 10;
            pos = (p1->digit * p2->digit + pos) / 10;
            AddDigit(&temp, digit);
            p1 = p1->next;
        }

        if (pos)
        {
            AddDigit(&temp, pos);
            pos = 0;
        }

        count++;
        multi = SumBigNumber(multi, temp);
        temp = CreateBigNumber("");

        for (i = 0; i < count; i++)
        {
            AddDigit(&temp, 0);
        }

        p2 = p2->next;
        p1 = n1.head;
    }

    return multi;
}

BigNumber MinusOne(BigNumber number)
{
    BigNumber minus;
    Node *p;
    int digit, pos;

    minus = CreateBigNumber("");
    p = number.head;
    pos = 0;

    digit = p->digit - 1 - pos;
    p = p->next;

    if (digit != -1)
    {
        pos = 0;
    }
    else
    {
        digit = 9;
        pos = 1;
    }

    AddDigit(&minus, digit);

    while (p)
    {
        digit = p->digit - pos;

        if (digit != -1)
        {
            pos = 0;
        }
        else
        {
            digit = 9;
            pos = 1;
        }

        if (p && digit != 0)
        {
            AddDigit(&minus, digit);
        }

        p = p->next;
    }

    return minus;
}

BigNumber FactBigNumber(BigNumber number)
{
    if (number.head->next == NULL && number.head->digit == 1)
    {
        return CreateBigNumber("1");
    }
    else
    {
        return MultiBigNumber(number, FactBigNumber(MinusOne(number)));
    }
}

bool CompareBigNumber(BigNumber n1, BigNumber n2)
{
    if(n1.size == n2.size)
    {
        Node *p1, *p2;

        p1 = n1.head;
        p2 = n2.head;

        while(p1)
        {
            if(p1->digit != p2->digit)
            {
                return false;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }
    else
    {
        return false;
    }
}
