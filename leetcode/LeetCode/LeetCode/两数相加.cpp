/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#ifdef OPEN
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

	void print()
	{
		for (ListNode* curNode = this; curNode != NULL; curNode = curNode->next)
		{
			cout << curNode->val << endl;
		}
	}
};


class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		__int64 x=0, y=0;
		ListNode* curNode = l1;
		if (!l1)
			cout << "传入参数1空!";
		if (!l2)
			cout << "传入参数2空!";
		int level = 1;
		for (; curNode != NULL; curNode = curNode->next)
		{
			//cout << 'x' << curNode->val*level << endl;
			x += curNode->val*level;
			level *= 10;
		}
		level = 1;
		for (curNode = l2; curNode != NULL; curNode = curNode->next)
		{
			//cout << 'y' << curNode->val*level << endl;
			y += curNode->val*level;
			level *= 10;
		}

		__int64 ret = x + y;
		//int n = 0;
		//int tmp = ret;
		//while (tmp)
		//{
		//	tmp /= 10;
		//	n++;
		//}
		//cout << 'x'<<x<<'y'<<y<<'z'<<ret;

		ListNode* retList=new ListNode(ret%10);
		//cout << "1:"<<ret % 10;
		ret /= 10;
		curNode=retList;
		for (; ret;)
		{
			curNode->next = new ListNode(ret%10);
			//cout << "2:" << ret % 10;
			curNode = curNode->next;
			ret /= 10;
		}


		return retList;
	}

	void print(ListNode* list)
	{
		if (!list)
			cout << "print参数空";
		for (ListNode* curNode = list; curNode != NULL; curNode = curNode->next)
		{
			cout << endl;
			cout << curNode->val << endl;
		}
	}
};


int main()
{
	Solution sln;
	ListNode l1[3] = { 2,4,3 };
	l1[0].next = &l1[1];
	l1[1].next = &l1[2];
	ListNode l2[3] = { 5,6,4 };
	l2[0].next = &l2[1];
	l2[1].next = &l2[2];

	ListNode* ans=NULL;
	//ListNode* curNode1 = &l1;
	//ListNode* curNode2 = &l2;
	//int arr1[] = { 2,4,3 };
	//int arr2[] = { 5,6,4 };
	//for (int i = 0; i < 3; ++i)
	//{
	//	curNode1 = new ListNode(arr1[i]);
	//	cout << curNode1->val;
	//	curNode1 = curNode1->next;
	//	curNode2 = new ListNode(arr2[i]);
	//	cout << curNode2->val;
	//	curNode2 = curNode2->next;
	//}
	/*sln.print(l1);
	sln.print(l2);*/
	
	ans=sln.addTwoNumbers(l1, l2);
	sln.print(ans);

	

	system("pause");
	return 0;
}
#endif
///////////////////////////////////////////上述解决方案链表过长会导致计算溢出

#include <iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

	void print()
	{
		for (ListNode* curNode = this; curNode != NULL; curNode = curNode->next)
		{
			cout << curNode->val << endl;
		}
	}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {



	}
};

int main()
{

}
