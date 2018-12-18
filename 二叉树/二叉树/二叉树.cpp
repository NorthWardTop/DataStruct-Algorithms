// 二叉树.cpp : 定义控制台应用程序的入口点。
//

/*
	第i层上节点最多为2^(i-1)
	深度为k的二叉树节点数目最多为2^k - 1
	二叉树中终端节点数为w,度为2的节点数为m ,w=m+1
	
	1.已知父节点下标为i ,左子下标为2*i+1,右子为2*i+2
	2.已知子节点下标i ,父为i-1 >> 1
	3.左子下标%2 = 0, 右子下标%2 = 1
*/

#include "stdafx.h"
#include "TreeArr.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[10] = { 1,2,3,4,5,55,7,8,9,10 };
	TreeArr<int> mt;
	for (int i = 0; i < 10; ++i)
		mt.insertHeap(arr[i]);
	mt.printTree();
	/*cout << mt.getParentVal(5);
	cout << mt.getLeftVal(4);
	cout << mt.getRightVal(4);
	mt.appNode(22);*/
	/*TreeArr<int> mt;
	mt.printTree();
	mt.appNode(2);*/
	system("pause");
	return 0;
}

