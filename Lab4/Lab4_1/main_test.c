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

void Test1MoveSym()
{
    char *str;

    str = MoveSym(" 1234 5 6789");
    assert(Compare(str, "9 1234 5 678"));
}

void Test2MoveSym()
{
    char *str;

    str = MoveSym("hello, Alex");
    assert(Compare(str, "xhello, Ale"));
}

void Test3MoveSym()
{
    char *str;

    str = MoveSym("");
    assert(Compare(str, ""));
}

void Test1DelSym()
{
    char *str;

    str = DelSym(" 1234 5 6789", 0);
    assert(Compare(str, "1234 5 6789"));
}

void Test2DelSym()
{
    char *str;

    str = DelSym("hello, Alex", 7);
    assert(Compare(str, "hello, lex"));
}

void Test3DelSym()
{
    char *str;

    str = DelSym("", 0);
    assert(Compare(str, ""));
}

void Test1DifSym()
{
    char *str;

    str = DifSym(" 1234 5 6789");
    assert(Compare(str, " 1234 5 6789"));
}

void Test2DifSym()
{
    char *str;

    str = DifSym("hello, Alex");
    assert(Compare(str, "helo, Ax"));
}

void Test3DifSym()
{
    char *str;

    str = DifSym("");
    assert(Compare(str, ""));
}

int main()
{
    Test1StrLen();
    Test2StrLen();
    Test3StrLen();
    Test1MoveSym();
    Test2MoveSym();
    Test3MoveSym();
    Test1DelSym();
    Test2DelSym();
    Test3DelSym();
    Test1DifSym();
    Test2DifSym();
    Test3DifSym();
    printf("Tests passed!");
    return 0;
}
