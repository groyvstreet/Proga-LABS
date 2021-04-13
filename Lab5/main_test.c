#include <stdio.h>
#include "main.h"
#include <assert.h>

void Test1SumBigNumber()
{
    BigNumber a;

    a = SumBigNumber(CreateBigNumber("123456789"), CreateBigNumber("987654321"));
    assert(CompareBigNumber(a, CreateBigNumber("1111111110")));
}

void Test2SumBigNumber()
{
    BigNumber a;

    a = SumBigNumber(CreateBigNumber("123456789"), CreateBigNumber("0"));
    assert(CompareBigNumber(a, CreateBigNumber("123456789")));
}

void Test3SumBigNumber()
{
    BigNumber a;

    a = SumBigNumber(CreateBigNumber("463728195"), CreateBigNumber("192837465"));
    assert(CompareBigNumber(a, CreateBigNumber("656565660")));
}

void  Test1MultiBigNumber()
{
    BigNumber a;

    a = MultiBigNumber(CreateBigNumber("12345"), CreateBigNumber("56789"));
    assert(CompareBigNumber(a, CreateBigNumber("701060205")));
}

void  Test2MultiBigNumber()
{
    BigNumber a;

    a = MultiBigNumber(CreateBigNumber("36457"), CreateBigNumber("9468"));
    assert(CompareBigNumber(a, CreateBigNumber("345174876")));
}

void  Test3MultiBigNumber()
{
    BigNumber a;

    a = MultiBigNumber(CreateBigNumber("8747647"), CreateBigNumber("34"));
    assert(CompareBigNumber(a, CreateBigNumber("297419998")));
}

void Test1MinusOne()
{
    BigNumber a;

    a = MinusOne(CreateBigNumber("998877665544332211"));
    assert(CompareBigNumber(a, CreateBigNumber("998877665544332210")));
}

void Test2MinusOne()
{
    BigNumber a;

    a = MinusOne(CreateBigNumber("1"));
    assert(CompareBigNumber(a, CreateBigNumber("0")));
}

void Test3MinusOne()
{
    BigNumber a;

    a = MinusOne(CreateBigNumber("100000000000000000000"));
    assert(CompareBigNumber(a, CreateBigNumber("99999999999999999999")));
}

void Test1FactBigNumber()
{
    BigNumber a;

    a = FactBigNumber(CreateBigNumber("100"));
    assert(CompareBigNumber(a, CreateBigNumber("93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000")));
}

void Test2FactBigNumber()
{
    BigNumber a;

    a = FactBigNumber(CreateBigNumber("50"));
    assert(CompareBigNumber(a, CreateBigNumber("30414093201713378043612608166064768844377641568960512000000000000")));
}
void Test3FactBigNumber()
{
    BigNumber a;

    a = FactBigNumber(CreateBigNumber("23"));
    assert(CompareBigNumber(a, CreateBigNumber("25852016738884976640000")));
}

int main()
{
    Test1SumBigNumber();
    Test2SumBigNumber();
    Test3SumBigNumber();
    Test1MultiBigNumber();
    Test2MultiBigNumber();
    Test3MultiBigNumber();
    Test1MinusOne();
    Test2MinusOne();
    Test3MinusOne();
    Test1FactBigNumber();
    Test2FactBigNumber();
    Test3FactBigNumber();
    printf("Tests passed!");
    return 0;
}
