// ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
	��i���Ͻڵ����Ϊ2^(i-1)
	���Ϊk�Ķ������ڵ���Ŀ���Ϊ2^k - 1
	���������ն˽ڵ���Ϊw,��Ϊ2�Ľڵ���Ϊm ,w=m+1
	
	1.��֪���ڵ��±�Ϊi ,�����±�Ϊ2*i+1,����Ϊ2*i+2
	2.��֪�ӽڵ��±�i ,��Ϊi-1 >> 1
	3.�����±�%2 = 0, �����±�%2 = 1
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

