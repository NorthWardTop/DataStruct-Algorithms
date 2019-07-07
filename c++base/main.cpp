#include <iostream>
#include "test.h"

int main(int argc, char *argv[])
{
	Test a(10);
	Test b(30);
	std::cout << a.getVal() << std::endl;
	a.setVal(20);
	std::cout << a.getVal() << std::endl;
	std::swap(a, b);
	std::cout << a.getVal() << std::endl;
	return 0;
}