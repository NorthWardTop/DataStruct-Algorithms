// ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "tree.h"
#include <stdlib.h>
int _tmain(int argc, _TCHAR* argv[])
{
	Tree<int> tr;
	tr.insertNode(0, 20);

	tr.printTree();

	system("pause");
	return 0;
}

