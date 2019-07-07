#pragma once 

#include <iostream>
using namespace std;

template<class T>
class Tree
{

	struct TreeNode
	{
		T data;
		struct TreeNode* parent;//指向父节点
		struct TreeNode* child;//子节点
		struct TreeNode* brother;// 兄弟节点
	};
	TreeNode* pRoot;
public: 
	Tree();
	~Tree();
	void clear();//清除根节点
	bool isFind(T const &findData);//查找函数
	void printTree();
	int insertNode(T const& findData, T const& insertData, bool isChild = 0);
private:
	void _clear(TreeNode* root);//清除某个节点
	TreeNode* _find(TreeNode* root,T const& finddata)//查找给定节点内的数据
	{
		if (root)
		{//给定的root指针指向为空(root节点不存在)直接返回NULL,没有任何节点无需找
			if (root->data == finddata)
				return root;//找到后返回当前结点
			//本节点没找到找他的子节点
			TreeNode* tmpNode = _find(root->child, finddata);
			if (tmpNode) //如果子节点的返回不为空, 说明找到了
				return tmpNode;
			//子分支没有返回,继续执行找兄分支
			tmpNode = _find(root->child, finddata);
			if (tmpNode)
				return tmpNode;
		}
		return NULL;  //指向当前root节点的指针为空, root节点不存在, 查找完成, 没有找到
	}
	void _printTree(TreeNode* root); //树的遍历
};


//############################函数实现

template<class T>
Tree<T>::Tree()
{
	pRoot = new TreeNode;
	pRoot->data = 0;
	pRoot->child = NULL;
	pRoot->brother = NULL;
	pRoot->parent = NULL;
}

template<class T>
Tree<T>::~Tree()
{
	clear();
}

template<class T>
void Tree<T>::clear()//清除根节点
{
	if (pRoot)
		_clear(pRoot);
}

template<class T>
void Tree<T>::_clear(TreeNode* root)//清除某个节点
{
	if (root)
	{//当传入节点没有子节点且没有兄弟时候if完成
		_clear(root->child);//先向下走到最后子节点
		_clear(root->brother);//从最后一个子节点向上删除,先删除兄弟
		delete root;a
		root = NULL;
	}
}

template<class T>
bool Tree<T>::isFind(T const &findData)//查找函数
{
	return _find(pRoot, findData) != NULL;
}

template<class T>
void Tree<T>::_printTree(TreeNode* root) //树的遍历
{
	if (root)
	{
		cout << root->data << "-->";
		_printTree(root->child);
		_printTree(root->brother);
	}
}

template<class T>
int Tree<T>::insertNode(T const& findData, T const& insertData, bool isChild)
{
	TreeNode* tmpFindNode = _find(pRoot, findData);
	if (!tmpFindNode)
		return 1;	//没有找到节点,插入失败
	TreeNode* tmpInsertNode = new TreeNode;
	tmpInsertNode->data = insertData;
	tmpInsertNode->parent = NULL;
	tmpInsertNode->child = NULL;
	tmpInsertNode->brother = NULL;
	if (!tmpInsertNode)
		return 2;	//新建节点失败
	if (isChild)  //孩子插入
	{
		if (tmpFindNode->child) //有孩子
		{
			TreeNode* tmpNode = tmpFindNode->child;  //临时节点指向他的孩子
			while (tmpNode->brother)
				tmpNode = tmpNode->brother;  //找到最后一个兄弟
			tmpNode->brother = tmpInsertNode;  //跟到最后一个兄弟后面
			tmpInsertNode->parent = tmpFindNode->parent;	//互为兄弟,父亲相同
			return 0;
		}
		else  //无孩子
		{
			tmpFindNode->child = tmpInsertNode;  //没有孩子,将新节点直接后跟做孩子
			tmpInsertNode->parent = tmpFindNode;	//指明新节点父亲
			return 0;
		}
	}
	else  //兄弟插入
	{
		if (tmpFindNode->brother) //有兄弟
		{
			TreeNode* tmpNode = tmpFindNode->brother;  //临时节点指向他的兄弟
			while (tmpNode->brother)
				tmpNode = tmpNode->brother;  //找到最后一个兄弟
			tmpNode->brother = tmpInsertNode;  //跟到最后一个兄弟后面
			tmpInsertNode->parent = tmpFindNode->parent;	//互为兄弟,父亲相同
			return 0;
		}
		else  //无兄弟
		{
			tmpFindNode->brother = tmpInsertNode;  //将新节点直接后跟做兄弟
			tmpInsertNode->parent = tmpFindNode->brother;	//新节点父亲和上兄弟属于同父亲
			return 0;
		}
	}
}

template<class T>
void Tree<T>::printTree()
{
	_printTree(pRoot);
	cout << "NULL\n";
}








