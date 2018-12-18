
// Ѱ·�㷨.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "CMyStack.h"
#define MAP_LEN 12
/*
���Ѱ·:
	1.һ��ֻ����һ��
	2.�߹��Ĳ�����
	3.�������ϰ��޷�ǰ����Ҫ����
*/
/************************************************************************/
/* �ص�:
		1.�п����Ҳ���·
		2.��һ�������·��,����˳��ͬ·���Ͳ�ͬ

*/
/************************************************************************/

enum PathDir{up,down,left,right};
struct MyPoint
{
	int row;//��
	int col;//��
};

struct PathNode
{
	int val;//�Ƿ������
	PathDir dir;//�߹��ķ���
	bool isFind;//����Ƿ�Ѱ�ҹ�
	MyPoint coor;//��������
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

	PathNode pathArr[MAP_LEN][MAP_LEN];//Ѱ·��ͼ������ά����
	//������Ϣ��ֵ	
	for (int i = 0; i < MAP_LEN; ++i)
	{
		for (int j = 0; j < MAP_LEN; ++j)
		{
			pathArr[i][j].val = map[i][j];
			pathArr[i][j].isFind = false;
			pathArr[i][j].dir = up;//Ѱ·�����˳���Լ����壬�ϣ����£���
			pathArr[i][j].coor.col = i;
			pathArr[i][j].coor.row = j;
		}
	}

	MyPoint beginPos = { 1, 1 };
	MyPoint endPos = { 10, 10 };
	MyPoint currPos = beginPos;
	CMyStack<MyPoint> ms;//��������ʹ��,����Ѱ����·����
	ms.push(beginPos);


	PathNode nextNode = {};
	while (1)
	{
		//��·����
		switch (pathArr[currPos.col][currPos.row].dir)//���յ�ǰ��ķ���ȥ����
		{
		case up:
			pathArr[currPos.col][currPos.row].dir = left;//��һ��һ���ǿ����
			 nextNode = pathArr[currPos.col-1][currPos.row];//���浱ǰ������һ�����(Ϊ����������)
			if (nextNode.val == 0 \
				&& nextNode.isFind == 0)/*�������߲���û���߹�*/
			{
				pathArr[currPos.col][currPos.row].isFind = true;//����ѷ���
				MyPoint tempPos = nextNode.coor;//����
				ms.push(tempPos);//�ɷ��ʾ���ջ
				currPos = tempPos;//��ǰ������������
			}
			break;
		case left:
			pathArr[currPos.col][currPos.row].dir = down;//��һ��һ���ǿ��±�
			 nextNode = pathArr[currPos.col][currPos.row-1];//���浱ǰ������һ�����(Ϊ����������)
			if (nextNode.val == 0 \
				&& nextNode.isFind == 0)/*�������߲���û���߹�*/
			{
				pathArr[currPos.col][currPos.row].isFind = true;//����ѷ���
				MyPoint tempPos = nextNode.coor;//����
				ms.push(tempPos);//�ɷ��ʾ���ջ
				currPos = tempPos;//��ǰ������������
			}
			break;
		case down:
			pathArr[currPos.col][currPos.row].dir = right;//��һ��һ���ǿ��ұ�
			 nextNode = pathArr[currPos.col + 1][currPos.row];//���浱ǰ������һ�����(Ϊ����������)
			if (nextNode.val == 0 \
				&& nextNode.isFind == 0)/*�������߲���û���߹�*/
			{
				pathArr[currPos.col][currPos.row].isFind = true;//����ѷ���
				MyPoint tempPos = nextNode.coor;//����
				ms.push(tempPos);//�ɷ��ʾ���ջ
				currPos = tempPos;//��ǰ������������
			}
			break;
		case right:
			//pathArr[currPos.col][currPos.row].dir = up;//�Ѿ�����һȦ,������������
			 nextNode = pathArr[currPos.col][currPos.row + 1];//���浱ǰ������һ�����(Ϊ����������)
			 //nextNode.coor = pathArr[currPos.col][currPos.row + 1].coor;
			if (nextNode.val == 0 \
				&& nextNode.isFind == 0)/*�������߲���û���߹�*///���������������
			{
				pathArr[currPos.col][currPos.row].isFind = true;//����ѷ���
				MyPoint tempPos = nextNode.coor;//����
				ms.push(tempPos);//�ɷ��ʾ���ջ
				currPos = tempPos;//��ǰ������������
			}
			else //���������ջ(�˻�)
			{
				pathArr[currPos.col][currPos.row].isFind = true;//����ѷ���
				ms.pop();//��ջ��ǰ�������
				if (!ms.isEmpty())
					currPos = ms.getTop();//�˻���һ��				
			}
			break;
		default:
			break;
		}
		if (currPos.col == endPos.col&&currPos.row == endPos.row)//�ҵ��յ�
			break;
		if (ms.isEmpty())//�˻ص������Ҳû���ҵ�
			break;
	}


	//����:��ʼ����ӡ·��������
	bool print[MAP_LEN][MAP_LEN] = {};
	MyPoint tempPos;
	for (int i = 0; i < MAP_LEN; ++i)
	{
		for (int j = 0; j < MAP_LEN; ++j)
		{
			print[i][j] = true;
		}
	}
	//��ջ���������
	while (!ms.isEmpty())
	{
		tempPos = ms.getTop();
		print[tempPos.col][tempPos.row] = false;
		ms.pop();
	}
	//��ӡ
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

