// 树.cpp : 定义控制台应用程序的入口点。
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

