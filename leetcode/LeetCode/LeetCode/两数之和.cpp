// leetcode2.cpp: 定义应用程序的入口点。
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector<int> ret;
		for (vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
		{
			for (vector<int>::iterator j = i+1; j != nums.end(); ++j)
			{
				if (*i + *j == target)
				{
					ret.push_back(i-nums.begin());
					ret.push_back(j - nums.begin());
					break;
					break;
				}
			}
		}
		return ret;
	}
};


vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> ret;
	for (vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
	{
		for (vector<int>::iterator j = i + 1; j != nums.end(); ++j)
		{
			if (*i + *j == target)
			{
				ret.push_back(i - nums.begin());
				ret.push_back(j - nums.begin());
				break;
				break;
			}
		}
	}
	return ret;
}

int main()
{
	//cout << "Hello CMake。" << endl;
	int arr[] = { 2, 7, 11, 15 };
	vector<int> nums;
	vector<int> ans;
	for (int i = 0; i < 4; ++i)
		nums.push_back(arr[i]);
	
	Solution sln;
	ans=twoSum(nums, 26);
	cout << ans.front() << ' ' << ans.back();


	system("pause");
	return 0;
}
