#include <stdio.h>
#include "main.h"
#include <assert.h>

void Test1StrLen()
{
    int len;

    len = StrLen(" 1234 5 6789");
    assert(len == 12);
}

void Test2StrLen()
{
    int len;

    len = StrLen("hello, Alex");
    assert(len == 11);
}

void Test3StrLen()
{
    int len;

    len = StrLen("");
    assert(len == 0);
}

void Test1DelSym()
{
    char *str;

    str = DelSym(" 1234 5 6789", 0, 12);
    assert(Compare(str, "1234 5 6789"));
}

void Test2DelSym()
{
    char *str;

    str = DelSym("hello, Alex", 7, 11);
    assert(Compare(str, "hello, lex"));
}

void Test3DelSym()
{
    char *str;

    str = DelSym("", 0, 0);
    assert(Compare(str, ""));
}

int main()
{
    Test1StrLen();
    Test2StrLen();
    Test3StrLen();
    Test1DelSym();
    Test2DelSym();
    Test3DelSym();
    printf("Tests passed!");
    return 0;
}
