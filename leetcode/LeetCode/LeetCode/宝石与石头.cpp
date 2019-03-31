

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int numJewelsInStones(string J, string S) {
		int cnt = 0;
		for (int i = 0; i < S.length(); ++i)
		{
			for (int j = 0; j < J.length(); ++j)
			{
				if (S.at(i) == J.at(j))
				{
					++cnt;
					break;
				}
			}
		}
		return cnt;
	}
};


int main()
{
	string gemstone="aA";
	string myStone="aAAbbbb";
	Solution sln;
	cout << sln.numJewelsInStones(gemstone, myStone);

	system("pause");
	return 0;
}
