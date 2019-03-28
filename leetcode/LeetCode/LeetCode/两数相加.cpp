/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		int x=0, y=0;
		ListNode* curNode = l1;
		int level = 1;
		for (; curNode != NULL; curNode = curNode->next)
		{
			x += curNode->val*level;
			level *= 10;
		}
		level = 1;
		for (curNode = l2; curNode != NULL; curNode = curNode->next)
		{
			y += curNode->val*level;
			level *= 10;
		}

		int ret = x + y;
		int n = 0;
		int tmp = ret;
		while (tmp)
		{
			tmp /= 10;
			n++;
		}

		ListNode* retList;
		level = 10;
		for (; ret;)
		{
			retList->next = new ListNode(ret%level);
			ret /= 10;
			level *= 10;
		}
		return retList;
	}

	void print(ListNode* list)
	{

	}
};


int main()
{
	Solution sln;
	ListNode* l1;
	ListNode* l2;
	ListNode* ans;
	int arr1[] = { 2,4,3 };
	int arr2[] = { 5,6,4 };
	for (int i = 0; i < 3; ++i)
	{
		l1->next = new ListNode(arr1[i]);
		l2->next = new ListNode(arr2[i]);
	}
	ans=sln.addTwoNumbers(l1, l2);



	return 0;
}