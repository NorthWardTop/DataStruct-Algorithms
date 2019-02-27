
// 寻路算法.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CMyStack.h"
#define MAP_LEN 12
/*
深度寻路:
	1.一次只能走一步
	2.走过的不在走
	3.遇到的障碍无法前进需要回退
*/
/************************************************************************/
/* 特点:
		1.有可能找不到路
		2.不一定是最短路径,方向顺序不同路径就不同

*/
/************************************************************************/

enum PathDir{up,down,left,right};
struct MyPoint
{
	int row;//行
	int col;//列
};

struct PathNode
{
	int val;//是否可行走
	PathDir dir;//走过的方向
	bool isFind;//标记是否寻找过
	MyPoint coor;//结点的坐标
};

int _tmain(int argc, _TCHAR* argv[])
{
	int map[MAP_LEN][MAP_LEN] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1 },
		{ 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};

	PathNode pathArr[MAP_LEN][MAP_LEN];//寻路地图辅助二维数组
	//辅助信息赋值	
	for (int i = 0; i < MAP_LEN; ++i)
	{
		for (int j = 0; j < MAP_LEN; ++j)
		{
			pathArr[i][j].val = map[i][j];
			pathArr[i][j].isFind = false;
			pathArr[i][j].dir = up;//寻路方向的顺序自己定义，上，左，下，右
			pathArr[i][j].coor.col = i;
			pathArr[i][j].coor.row = j;
		}
	}

	MyPoint beginPos = { 1, 1 };
	MyPoint endPos = { 10, 10 };
	MyPoint currPos = beginPos;
	CMyStack<MyPoint> ms;//用来回退使用,保存寻到的路径点
	ms.push(beginPos);


	PathNode nextNode = {};
	while (1)
	{
		//找路过程
		switch (pathArr[currPos.col][currPos.row].dir)//按照当前点的方向去分流
		{
		case up:
			pathArr[currPos.col][currPos.row].dir = left;//下一步一定是看左边
			 nextNode = pathArr[currPos.col-1][currPos.row];//保存当前结点的下一步结点(为了描述方便)
			if (nextNode.val == 0 \
				&& nextNode.isFind == 0)/*结点可行走并且没有走过*/
			{
				pathArr[currPos.col][currPos.row].isFind = true;//标记已访问
				MyPoint tempPos = nextNode.coor;//保存
				ms.push(tempPos);//可访问就入栈
				currPos = tempPos;//当前点行坐标上移
			}
			break;
		case left:
			pathArr[currPos.col][currPos.row].dir = down;//下一步一定是看下边
			 nextNode = pathArr[currPos.col][currPos.row-1];//保存当前结点的下一步结点(为了描述方便)
			if (nextNode.val == 0 \
				&& nextNode.isFind == 0)/*结点可行走并且没有走过*/
			{
				pathArr[currPos.col][currPos.row].isFind = true;//标记已访问
				MyPoint tempPos = nextNode.coor;//保存
				ms.push(tempPos);//可访问就入栈
				currPos = tempPos;//当前点行坐标左移
			}
			break;
		case down:
			pathArr[currPos.col][currPos.row].dir = right;//下一步一定是看右边
			 nextNode = pathArr[currPos.col + 1][currPos.row];//保存当前结点的下一步结点(为了描述方便)
			if (nextNode.val == 0 \
				&& nextNode.isFind == 0)/*结点可行走并且没有走过*/
			{
				pathArr[currPos.col][currPos.row].isFind = true;//标记已访问
				MyPoint tempPos = nextNode.coor;//保存
				ms.push(tempPos);//可访问就入栈
				currPos = tempPos;//当前点行坐标上移
			}
			break;
		case right:
			//pathArr[currPos.col][currPos.row].dir = up;//已经走了一圈,上左下右找完
			 nextNode = pathArr[currPos.col][currPos.row + 1];//保存当前结点的下一步结点(为了描述方便)
			 //nextNode.coor = pathArr[currPos.col][currPos.row + 1].coor;
			if (nextNode.val == 0 \
				&& nextNode.isFind == 0)/*结点可行走并且没有走过*///若右能走则继续走
			{
				pathArr[currPos.col][currPos.row].isFind = true;//标记已访问
				MyPoint tempPos = nextNode.coor;//保存
				ms.push(tempPos);//可访问就入栈
				currPos = tempPos;//当前点行坐标左移
			}
			else //不能走则出栈(退回)
			{
				pathArr[currPos.col][currPos.row].isFind = true;//标记已访问
				ms.pop();//出栈当前结点坐标
				if (!ms.isEmpty())
					currPos = ms.getTop();//退回上一步				
			}
			break;
		default:
			break;
		}
		if (currPos.col == endPos.col&&currPos.row == endPos.row)//找到终点
			break;
		if (ms.isEmpty())//退回到起点了也没有找到
			break;
	}


	//测试:初始化打印路径的数组
	bool print[MAP_LEN][MAP_LEN] = {};
	MyPoint tempPos;
	for (int i = 0; i < MAP_LEN; ++i)
	{
		for (int j = 0; j < MAP_LEN; ++j)
		{
			print[i][j] = true;
		}
	}
	//出栈保存进数组
	while (!ms.isEmpty())
	{
		tempPos = ms.getTop();
		print[tempPos.col][tempPos.row] = false;
		ms.pop();
	}
	//打印
	for (int i = 0; i < MAP_LEN; ++i)
	{
		for (int j = 0; j < MAP_LEN; ++j)
		{
			printf("%d ", print[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}

