#pragma once 

#include <iostream>
using namespace std;

template<class T>
class Tree
{

	struct TreeNode
	{
		T data;
		struct TreeNode* parent;//ָ�򸸽ڵ�
		struct TreeNode* child;//�ӽڵ�
		struct TreeNode* brother;// �ֵܽڵ�
	};
	TreeNode* pRoot;
public: 
	Tree();
	~Tree();
	void clear();//������ڵ�
	bool isFind(T const &findData);//���Һ���
	void printTree();
	int insertNode(T const& findData, T const& insertData, bool isChild = 0);
private:
	void _clear(TreeNode* root);//���ĳ���ڵ�
	TreeNode* _find(TreeNode* root,T const& finddata)//���Ҹ����ڵ��ڵ�����
	{
		if (root)
		{//������rootָ��ָ��Ϊ��(root�ڵ㲻����)ֱ�ӷ���NULL,û���κνڵ�������
			if (root->data == finddata)
				return root;//�ҵ��󷵻ص�ǰ���
			//���ڵ�û�ҵ��������ӽڵ�
			TreeNode* tmpNode = _find(root->child, finddata);
			if (tmpNode) //����ӽڵ�ķ��ز�Ϊ��, ˵���ҵ���
				return tmpNode;
			//�ӷ�֧û�з���,����ִ�����ַ�֧
			tmpNode = _find(root->child, finddata);
			if (tmpNode)
				return tmpNode;
		}
		return NULL;  //ָ��ǰroot�ڵ��ָ��Ϊ��, root�ڵ㲻����, �������, û���ҵ�
	}
	void _printTree(TreeNode* root); //���ı���
};


//############################����ʵ��

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
void Tree<T>::clear()//������ڵ�
{
	if (pRoot)
		_clear(pRoot);
}

template<class T>
void Tree<T>::_clear(TreeNode* root)//���ĳ���ڵ�
{
	if (root)
	{//������ڵ�û���ӽڵ���û���ֵ�ʱ��if���
		_clear(root->child);//�������ߵ�����ӽڵ�
		_clear(root->brother);//�����һ���ӽڵ�����ɾ��,��ɾ���ֵ�
		delete root;a
		root = NULL;
	}
}

template<class T>
bool Tree<T>::isFind(T const &findData)//���Һ���
{
	return _find(pRoot, findData) != NULL;
}

template<class T>
void Tree<T>::_printTree(TreeNode* root) //���ı���
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
		return 1;	//û���ҵ��ڵ�,����ʧ��
	TreeNode* tmpInsertNode = new TreeNode;
	tmpInsertNode->data = insertData;
	tmpInsertNode->parent = NULL;
	tmpInsertNode->child = NULL;
	tmpInsertNode->brother = NULL;
	if (!tmpInsertNode)
		return 2;	//�½��ڵ�ʧ��
	if (isChild)  //���Ӳ���
	{
		if (tmpFindNode->child) //�к���
		{
			TreeNode* tmpNode = tmpFindNode->child;  //��ʱ�ڵ�ָ�����ĺ���
			while (tmpNode->brother)
				tmpNode = tmpNode->brother;  //�ҵ����һ���ֵ�
			tmpNode->brother = tmpInsertNode;  //�������һ���ֵܺ���
			tmpInsertNode->parent = tmpFindNode->parent;	//��Ϊ�ֵ�,������ͬ
			return 0;
		}
		else  //�޺���
		{
			tmpFindNode->child = tmpInsertNode;  //û�к���,���½ڵ�ֱ�Ӻ��������
			tmpInsertNode->parent = tmpFindNode;	//ָ���½ڵ㸸��
			return 0;
		}
	}
	else  //�ֵܲ���
	{
		if (tmpFindNode->brother) //���ֵ�
		{
			TreeNode* tmpNode = tmpFindNode->brother;  //��ʱ�ڵ�ָ�������ֵ�
			while (tmpNode->brother)
				tmpNode = tmpNode->brother;  //�ҵ����һ���ֵ�
			tmpNode->brother = tmpInsertNode;  //�������һ���ֵܺ���
			tmpInsertNode->parent = tmpFindNode->parent;	//��Ϊ�ֵ�,������ͬ
			return 0;
		}
		else  //���ֵ�
		{
			tmpFindNode->brother = tmpInsertNode;  //���½ڵ�ֱ�Ӻ�����ֵ�
			tmpInsertNode->parent = tmpFindNode->brother;	//�½ڵ㸸�׺����ֵ�����ͬ����
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








