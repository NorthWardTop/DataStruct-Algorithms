#include <iostream>
#include "test.h"

using namespace std;

int main(int argc, char *argv[])
{
	unsigned int val = 1024;
	bool cond = *((bool*)(&val));

	cout << cond << " " << val << endl;
	if (cond) 
		val += 1;
	cond = *((bool*)(&val));
	cout << cond << " " << val << endl;

	if (cond) 
		val += 1;
	cond = *((bool*)(&val));
	cout << cond << " " << val << endl;

	return 0;
}