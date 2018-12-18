#pragma once

/************************************************************************/
/* 
�� ���ѣ���С�ѣ� ��ȫ������
���ѣ���������һ�����ڵ�Ҫ���ڻ��������ӽڵ�
��С�ѣ���������һ�����ڵ�ҪС�ڻ������С�ӽڵ�

�ѵĲ��룺
	1������ȫ�������������룻
	2���жϲ���ڵ��Ƿ��ƻ������С���ѵ��ص㣬����ǣ������������ص�Ϊֹ�����Ͻ��������ڵ�
�ѵ�ɾ����
	1��ֻ��ɾ�����ڵ�;
	2�������һ�������Ƶ����ڵ㣻
	3���жϸ��ڵ��Ƿ��ƻ������С���ѵ��ص㣬����ǣ������������ص�Ϊֹ�����½�����Ҷ�ڵ�
�ѵĳ�ʼ����
	1����ԭʼ���ݵ�λ��һ����ȫ�����ؽ����У�
	2�������һ�����ӽڵ�Ľڵ㿪ʼ���������С���ѵ��ص㣻
	3�������һ�����ӽڵ�Ľڵ����μ����±꣬��������е����������С���ѵ��ص㣬ֱ�����ڵ�
������
*/
/************************************************************************/



#include <iostream>
using namespace std;

template<class T>
class TreeArr
{
	T* pBuf;	//��̬����
	size_t len;	///��ǰ����
	size_t maxSize;	//��󳤶�
public:
	TreeArr();
	TreeArr(T* buf, size_t len);
	~TreeArr();
	void init();
	void init(T *buf, size_t len);
	void clear();
public:
	int find(T const& findVal) const;	//���ڷ����±�, �����ڷ���-1
	void printTree() const;
	void appNode(T const& data);
	T const& getParentVal(T const& findVal) const;	//���ز���λ�õĸ�ֵ
	T const& getRightVal(T const& findVal) const;
	T const& getLeftVal(T const& findVal) const;
	void insertHeap(T const& val);//�ѵĲ���
	void delHeap();
	void initHeap(T const& arr,size_t srcLen);
private:
	void _ruleNode(size_t index);
	void _printTree(size_t index) const;
};

template<class T>
void TreeArr<T>::_ruleNode(size_t index)
{
	size_t currIndex = index;//��i�ڵ���ɻ�
	while (true)
	{
		size_t leftIndex = currIndex << 1 + 1;
		size_t rightIndex = currIndex << 1 + 1;
		if (leftIndex > len - 1)//���Խ���ұ�һ��Խ��
			break;//���Խ������
		//�����Ƿ����ұ�,�ȶ������С,�����ҽڵ�Ҳ�����С
		bool isLeft = true;
		//�����������ж�����˭С,�ı��С��־
		if (rigthIndex <= len - 1)
		{
			//����ұߵ�С,�ı��־
			if (pBuf[leftIndex] > pBuf[rightIndex])
				isLeft = false;
		}
		if (isLeft)
		{
			if (pBuf[currIndex] > pBuf[leftIndex])
			{
				T tempVal = pBuf[leftIndex];
				pBuf[leftIndex] = pBuf[currIndex];
				pBuf[currIndex] = tempVal;
				currIndex = leftIndex;
			}
			else//��ǰС�����轻��
				break;
		}
		else//���ҽ���
		{
			if (pBuf[currIndex] > pBuf[rightIndex])
			{
				T tempVal = pBuf[rightIndex];
				pBuf[rightIndex] = pBuf[currIndex];
				pBuf[currIndex] = tempVal;
				currIndex = rightIndex;
			}
			else//��ǰС�����轻��
				break;
		}
	}
}

template<class T>
void TreeArr<T>::initHeap(T const& arr, size_t srcLen)
{
	clear();//����ʱ�����,��ֹ�ڴ�й¶
	maxSize = srcLen;
	len = srcLen;
	pBuf = new T[maxSize];
	memmove(pBuf, arr, maxSize*sizeof(T));
	if (len == 0)
		return;
	//�����һ�����ӽڵ���±�((len - 2) >> 1)��ʼ
	//(len - 2) >> 1�൱��((len - 1) - 1) >> 1;
	for (size_t i = (len - 2) >> 1; i >= 0; --i)
	{
		size_t currIndex = i;//��i�ڵ���ɻ�
		while (true)
		{
			size_t leftIndex = currIndex << 1 + 1;
			size_t rightIndex = currIndex << 1 + 1;
			if (leftIndex > len - 1)//���Խ���ұ�һ��Խ��
				break;//���Խ������
			//�����Ƿ����ұ�,�ȶ������С,�����ҽڵ�Ҳ�����С
			bool isLeft = true;
			//�����������ж�����˭С,�ı��С��־
			if (rigthIndex <= len - 1)
			{
				//����ұߵ�С,�ı��־
				if (pBuf[leftIndex] > pBuf[rightIndex])
					isLeft = false;
			}
			if (isLeft)
			{
				if (pBuf[currIndex] > pBuf[leftIndex])
				{
					T tempVal = pBuf[leftIndex];
					pBuf[leftIndex] = pBuf[currIndex];
					pBuf[currIndex] = tempVal;
					currIndex = leftIndex;
				}
				else//��ǰС�����轻��
					break;
			}
			else//���ҽ���
			{
				if (pBuf[currIndex] > pBuf[rightIndex])
				{
					T tempVal = pBuf[rightIndex];
					pBuf[rightIndex] = pBuf[currIndex];
					pBuf[currIndex] = tempVal;
					currIndex = rightIndex;
				}
				else//��ǰС�����轻��
					break;
			}
		}
	}

}

/************************************************************************/
/* ��С��ɾ��
1.ֻ��ɾ�����ڵ�
2.�����һ���ڵ��ƶ������ڵ�
3.�жϸ��ڵ��Ƿ��ƻ�����С���ص�(���ڵ㶨С���ӽڵ�)
*/
/************************************************************************/
template<class T>
void TreeArr<T>::delHeap()
{
	if (len)
		return;
	//ֻ��һ���ڵ�ֱ��len--
	if (len > 1)//���������Ͻڵ�
		pBuf[0] = pBuf[len - 1];//�����һ���ڵ����...1...2
	size_t currIndex = 0;//�����ڵ���ɻ�
	while (true)
	{
		size_t leftIndex = currIndex << 1 + 1;
		size_t rightIndex = currIndex << 1 + 1;
		if (leftIndex > len - 1)//���Խ���ұ�һ��Խ��
			break;//���Խ������
		//�����Ƿ����ұ�,�ȶ������С,�����ҽڵ�Ҳ�����С
		bool isLeft = true;
		//�����������ж�����˭С,�ı��С��־
		if (rigthIndex <= len - 1)
		{
			//����ұߵ�С,�ı��־
			if (pBuf[leftIndex] > pBuf[rightIndex])
				isLeft = false;
		}
		if (isLeft)
		{
			if (pBuf[currIndex] > pBuf[leftIndex])
			{
				T tempVal = pBuf[leftIndex];
				pBuf[leftIndex] = pBuf[currIndex];
				pBuf[currIndex] = tempVal;
				currIndex = leftIndex;
			}
			else//��ǰС�����轻��
				break;
		}
		else//���ҽ���
		{
			if (pBuf[currIndex] > pBuf[rightIndex])
			{
				T tempVal = pBuf[rightIndex];
				pBuf[rightIndex] = pBuf[currIndex];
				pBuf[currIndex] = tempVal;
				currIndex = rightIndex;
			}
			else//��ǰС�����轻��
				break;
		}
	}
	len--;
}

//��С�Ѳ���
template<class T>
void TreeArr<T>::insertHeap(T const& val)
{
	appNode(val);
	size_t currIndex = len - 1;//��ǰ����ֵ���±�
	size_t parentIndex = (currIndex - 1) >> 1;//��ǰ�±�ĸ��±�
	while (currIndex)//����Ϊ���ڵ�,����ѭ���Ƚ�
	{
		if (pBuf[currIndex]<pBuf[parentIndex])
		{
			T tempVal = pBuf[parentIndex];
			pBuf[parentIndex] = pBuf[currIndex];
			pBuf[currIndex] = tempVal;
		}
		else
			break;
		currIndex = parentIndex;//��������ĵ�ǰ(������ֵ)�±�
	}
}

//#######################����ʵ��
//------------------------------��������
template<class T>
TreeArr<T>::TreeArr()
{
	init();
}

template<class T>
TreeArr<T>::TreeArr(T* buf, size_t len)
{
	init(buf, len);
}

template<class T>
TreeArr<T>::~TreeArr()
{
	clear();
}
//----------------------------��������
template<class T>
void TreeArr<T>::init()
{
	pBuf = NULL;
	len = 0;
	maxSize = 0;
}

template<class T>
void TreeArr<T>::init(T *buf, size_t len)
{
	clear();
	this->len = len;
	maxSize = len;
	this->pBuf = new T[maxSize];
	memmove(this->pBuf, buf, sizeof(T)*len);
}

template<class T>
void TreeArr<T>::clear()
{
	if (pBuf)
		delete[]pBuf;
	pBuf = NULL;
	maxSize = 0;
	len = 0;
}
//------------------------------
template<class T>
int TreeArr<T>::find(T const& findVal) const
{
	for (size_t i = 0; i < len; i++)
	{
		if (pBuf[i] == findVal)
			return i;
	}
	return -1;
}

template<class T>
void TreeArr<T>::printTree() const
{
	_printTree(0);
}

template<class T>
void TreeArr<T>::_printTree(size_t index) const
{
	if (index < len)
	{
		_printTree(2 * index + 1);	//��ӡ������
		_printTree(2 * index + 2);	//��ӡ������
		cout << pBuf[index] << "  ";
	}
}

template<class T>
void TreeArr<T>::appNode(T const& data)
{
	if (len >= maxSize)
	{
		maxSize = maxSize + ((maxSize >> 1) >1 ? (maxSize >> 1) : 1); 
		T *tmpBuf = new T[maxSize];
		//116����ȷ��,����˵bufָ����ڴ�С��sizeof(T)*maxSizeѽ,�������ڴ�Խ�������
		if (pBuf)
		{
			memmove(tmpBuf, this->pBuf, sizeof(T)*len);	//���ڴ���������
			delete[]pBuf;	//�ͷ�ԭbuf�ڴ�
		}
		pBuf = tmpBuf;	//ָ���¿ռ�
	}
	pBuf[len++] = data;
}

template<class T>
T const& TreeArr<T>::getParentVal(T const& findVal) const
{
	size_t tmpIndex = find(findVal);
	if (tmpIndex<=0)
	{	//�Ҹ��ڵ�ķ���: �±�-1����2
		throw "no parent!";
	}
	return pBuf[(tmpIndex - 1) >> 1];
}

template<class T>
T const& TreeArr<T>::getRightVal(T const& findVal) const
{
	size_t tmpIndex = find(findVal);
	//���Ǹ��ڵ�򳬳���Χ���������ҽڵ�ʱ�����쳣
	if (tmpIndex<=0||tmpIndex >= len||tmpIndex%2 == 0)
	{	
		throw "no RightBrother!";
	}
	//���ҽڵ�ķ���: �±�+1
	return pBuf[tmpIndex+1];
}

template<class T>
T const& TreeArr<T>::getLeftVal(T const& findVal) const
{
	size_t tmpIndex = find(findVal);
	//���Ǹ��ڵ�򳬳���Χ���������ҽڵ�ʱ�����쳣
	if (tmpIndex <= 0 || tmpIndex % 2 == 0)
	{
		throw "no LeftBrother!";
	}
	//���ҽڵ�ķ���: �±�-1
	return pBuf[tmpIndex - 1];
}