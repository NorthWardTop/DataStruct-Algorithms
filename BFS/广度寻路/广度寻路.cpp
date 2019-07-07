// ���Ѱ·.cpp : �������̨Ӧ�ó������ڵ㡣
//

/************************************************************************/
/* ���Ѱ·�͹��Ѱ·�ص�:
	���Ѱ·ֻ��һ��·�ߵ���,��һ�������·��
	���Ѱ·�����е�·������,һ�������·��
	
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
	PathDir dir;//��ǰ����
	bool isFind;//�Ƿ���ҹ�
	int val;//�ڵ㱣�������
};

struct MyPathNode
{
	MyPos pos;//����
	MyPathNode* parentNode;//ָ�򸸽ڵ�
	vector<MyPathNode*> childNode;//�ӽڵ�ָ������
};

//�ж�posλ���Ƿ����,ͨ�м��
bool isCheckPoint(MyPos const& pos, PathData pathArr[MAP_ROW][MAP_COL])
{
	bool isCheck = false;
	if ((pos.row >= 0 && pos.row <= MAP_ROW - 1 && pos.col >= 0 && pos.col <= MAP_COL - 1)	/*�����ڵ�ͼ��*/
		&&pathArr[pos.row][pos.col].isFind == 0		/*û�з��ʹ�*/
		&&pathArr[pos.row][pos.col].val == 0)	/*�ǵ�·*/
		isCheck = true;
	return isCheck;
}



int _tmain(int argc, _TCHAR* argv[])
{
	//������ͼ������
	int arr[MAP_ROW][MAP_COL] = {
		{ 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 }
	};
	//����·��������
	PathData pathArr[MAP_ROW][MAP_COL];

	//��ʼ������·��������
	for (int i = 0; i < MAP_ROW; ++i)
	{
		for (int j = 0; j < MAP_COL; ++j)
		{
			pathArr[i][j].dir = up;
			pathArr[i][j].isFind = 0;
			pathArr[i][j].val = arr[i][j];//��ͼ��ֵ
		}
	}
	
	//������ʼλ�ú���ֹλ��
	MyPos beginPos = { 1, 1 };
	MyPos endPos = { 4, 6 };

	//��ǿ�ʼ�ڵ��ѷ���
	pathArr[beginPos.row][beginPos.col].isFind = true;

	//��ʼ������ȱ�����(��ʼ�����ڵ�)
	MyPathNode* root = new MyPathNode;
	root->parentNode = NULL;//root�ĸ��ڵ�Ϊ��
	root->pos = beginPos;//���ڵ������һ������ʼ�ڵ�
	//vector���ø�ֵ,root�����ʱ���޲ι����Ѿ���ʼ������

	vector<MyPathNode*> nodeList;//�������Ľڵ�����,�ȵ�ǰ�ڵ���ڽӽڵ��б�(���ڵ�����)
	nodeList.push_back(root);//�����ڵ�ѹ��

	vector<MyPathNode*> tempNodeList;//��ʱָ������(�ӽڵ�����)
	MyPos tempPos;//��¼��ǰλ��,�Ա㳢������һ��

	while (true)
	{
		bool isFind = false;
		for (size_t i = 0; i < nodeList.size(); ++i)//�ڽӽڵ�����
		{
			for (size_t j = 0; j < 4; ++j)//4������ı���
			{
				tempPos = nodeList[i]->pos;
				switch (j)//�����������ҳ���
				{
				case up:tempPos.row--; break;
				case down:tempPos.row++; break;
				case PathDir::left:tempPos.col--; break;
				case PathDir::right:tempPos.col++; break;
				}
				if (isCheckPoint(tempPos, pathArr))//pos���Ա仯��
				{
					MyPathNode *pNode = new MyPathNode;//�½�һ���ڵ�,����pos�仯��Ľڵ�
					pNode->pos = tempPos;//�Ѿ�ȷ��pos����,ֱ�Ӹ�ֵ���ڵ�
					pNode->parentNode = nodeList[i];//����ϵ(���ڵ���Ǳ��������Ľڵ�)
					nodeList[i]->childNode.push_back(pNode);//�ӹ�ϵ:ѹ���ҵ�������ڵ�(�ҵ����������ķ���ȫ��ѹ��
					//nodeList.push_back(pNode);
					//ѹ����ʱ�ڵ�(����ֱ��ѹ��nodeListʱ��size��仯,����ѹ����ʱ��,����ٸ�ֵ��nodeList
					tempNodeList.push_back(pNode);
					pathArr[tempPos.row][tempPos.col].isFind = true;
					if (pNode->pos.col == endPos.col&&pNode->pos.row == endPos.row)
					{
						isFind = true;//�ҵ���־
						//��ʱ�ڵ�ָ���������(ʧȥ��rootָ��,ֻ�ܴ����ʼ�Ҹ���
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
			cout << "��·����!" << endl;
			break;
		}
		//תΪ�ӽڵ����
		nodeList = tempNodeList;
		tempNodeList.clear();//�����ʱ����,�´μ���
	}

	system("pause");
	return 0;
}

