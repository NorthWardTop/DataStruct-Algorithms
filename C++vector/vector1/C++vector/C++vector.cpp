
#include "stdafx.h"
#include <vector>
using std::vector;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int _tmain(int argc, _TCHAR* argv[])
{
	MyVector<int> a;
//	vector<int> c(6,10);
	MyVector<int> b(3, 7);
	
	for (int i = 0; i < 10; ++i)
	{
		a.push_back(i + 1);
	}
	a.print();
	a.clear();
	a.print();

	system("pause");
	return 0;
}