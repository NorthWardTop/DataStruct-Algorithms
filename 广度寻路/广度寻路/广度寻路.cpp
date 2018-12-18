// 广度寻路.cpp : 定义控制台应用程序的入口点。
//

/************************************************************************/
/* 深度寻路和广度寻路特点:
	深度寻路只走一条路走到底,不一定是最短路径
	广度寻路将所有的路径走完,一定是最短路径
	
*/
/************************************************************************/


#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

#define MAP_ROW		6
#define MAP_COL		8

enum PathDir{ up, down, left, right };

struct MyPos 
{
	int row;
	int col;
};

struct PathData
{
	PathDir dir;//当前方向
	bool isFind;//是否查找过
	int val;//节点保存的数据
};

struct MyPathNode
{
	MyPos pos;//坐标
	MyPathNode* parentNode;//指向父节点
	vector<MyPathNode*> childNode;//子节点指针数组
};

//判断pos位置是否可行,通行检查
bool isCheckPoint(MyPos const& pos, PathData pathArr[MAP_ROW][MAP_COL])
{
	bool isCheck = false;
	if ((pos.row >= 0 && pos.row <= MAP_ROW - 1 && pos.col >= 0 && pos.col <= MAP_COL - 1)	/*坐标在地图内*/
		&&pathArr[pos.row][pos.col].isFind == 0		/*没有访问过*/
		&&pathArr[pos.row][pos.col].val == 0)	/*是道路*/
		isCheck = true;
	return isCheck;
}



int _tmain(int argc, _TCHAR* argv[])
{
	//描述地图的数组
	int arr[MAP_ROW][MAP_COL] = {
		{ 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 }
	};
	//描述路径的数组
	PathData pathArr[MAP_ROW][MAP_COL];

	//初始化描述路径的数组
	for (int i = 0; i < MAP_ROW; ++i)
	{
		for (int j = 0; j < MAP_COL; ++j)
		{
			pathArr[i][j].dir = up;
			pathArr[i][j].isFind = 0;
			pathArr[i][j].val = arr[i][j];//地图赋值
		}
	}
	
	//设置起始位置和终止位置
	MyPos beginPos = { 1, 1 };
	MyPos endPos = { 4, 6 };

	//标记开始节点已访问
	pathArr[beginPos.row][beginPos.col].isFind = true;

	//开始创建广度遍历树(初始化根节点)
	MyPathNode* root = new MyPathNode;
	root->parentNode = NULL;//root的父节点为空
	root->pos = beginPos;//根节点的坐标一定是起始节点
	//vector不用赋值,root构造的时候无参构造已经初始化过了

	vector<MyPathNode*> nodeList;//待搜索的节点序列,既当前节点的邻接节点列表(父节点序列)
	nodeList.push_back(root);//将根节点压入

	vector<MyPathNode*> tempNodeList;//临时指针数组(子节点序列)
	MyPos tempPos;//记录当前位置,以便尝试走下一步

	while (true)
	{
		bool isFind = false;
		for (size_t i = 0; i < nodeList.size(); ++i)//邻接节点表遍历
		{
			for (size_t j = 0; j < 4; ++j)//4个方向的遍历
			{
				tempPos = nodeList[i]->pos;
				switch (j)//进行上下左右尝试
				{
				case up:tempPos.row--; break;
				case down:tempPos.row++; break;
				case PathDir::left:tempPos.col--; break;
				case PathDir::right:tempPos.col++; break;
				}
				if (isCheckPoint(tempPos, pathArr))//pos尝试变化后
				{
					MyPathNode *pNode = new MyPathNode;//新建一个节点,保存pos变化后的节点
					pNode->pos = tempPos;//已经确定pos坐标,直接赋值给节点
					pNode->parentNode = nodeList[i];//父关系(父节点就是本轮找他的节点)
					nodeList[i]->childNode.push_back(pNode);//子关系:压入找到的这个节点(找到符合条件的方向全都压入
					//nodeList.push_back(pNode);
					//压入临时节点(由于直接压入nodeList时候size会变化,所以压入临时的,最后再赋值给nodeList
					tempNodeList.push_back(pNode);
					pathArr[tempPos.row][tempPos.col].isFind = true;
					if (pNode->pos.col == endPos.col&&pNode->pos.row == endPos.row)
					{
						isFind = true;//找到标志
						//临时节点指针遍历序列(失去了root指针,只能从最后开始找父亲
						for (MyPathNode *tempNode = pNode; tempNode != NULL; tempNode = tempNode->parentNode)
							cout << tempNode->pos.row << "\t" << tempNode->pos.col << endl;
						break;
					}
				}
			}
			if (isFind)
				break;
		}
		if (isFind)
			break;
		if (nodeList.size() == 0)
		{
			cout << "无路可走!" << endl;
			break;
		}
		//转为子节点继续
		nodeList = tempNodeList;
		tempNodeList.clear();//清空临时序列,下次继续
	}

	system("pause");
	return 0;
}

