


#ifndef _TEST_H_
#define _TEST_H_

#include <vector>

class Test
{
private:
	/* data */
	int val;
public:
	explicit Test(int val = 0);
	int getVal() const;
	void setVal(int newVal);
	~Test();
};






#endif