#include "test.h"


Test::Test(int initVal):val(initVal)
{
}

Test::~Test()
{
}

int Test::getVal() const
{
	return val;
}

void Test::setVal(int newVal)
{
	val = newVal;
}


