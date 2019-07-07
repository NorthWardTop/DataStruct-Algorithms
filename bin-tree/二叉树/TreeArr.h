#pragma once

/************************************************************************/
/* 
堆 最大堆（最小堆） 完全二叉树
最大堆，树中任意一个根节点要大于或等于最大子节点
最小堆，树中任意一个根节点要小于或等于最小子节点

堆的插入：
	1、在完全二叉树的最后插入；
	2、判断插入节点是否破坏了最大（小）堆的特点，如果是，交换到符合特点为止，往上交换到根节点
堆的删除：
	1、只能删除根节点;
	2、把最后一个数据移到根节点；
	3、判断根节点是否破坏了最大（小）堆的特点，如果是，交换到符合特点为止，往下交换到叶节点
堆的初始化：
	1、按原始数据的位置一次性全部加载进堆中；
	2、从最后一个有子节点的节点开始来满足最大（小）堆的特点；
	3、从最后一个有子节点的节点依次减减下标，来完成所有的子树的最大（小）堆的特点，直至根节点
堆排序
*/
/************************************************************************/



#include <iostream>
using namespace std;

template<class T>
class TreeArr
{
	T* pBuf;	//动态数组
	size_t len;	///当前长度
	size_t maxSize;	//最大长度
public:
	TreeArr();
	TreeArr(T* buf, size_t len);
	~TreeArr();
	void init();
	void init(T *buf, size_t len);
	void clear();
public:
	int find(T const& findVal) const;	//存在返回下标, 不存在返回-1
	void printTree() const;
	void appNode(T const& data);
	T const& getParentVal(T const& findVal) const;	//返回参数位置的父值
	T const& getRightVal(T const& findVal) const;
	T const& getLeftVal(T const& findVal) const;
	void insertHeap(T const& val);//堆的插入
	void delHeap();
	void initHeap(T const& arr,size_t srcLen);
private:
	void _ruleNode(size_t index);
	void _printTree(size_t index) const;
};

template<class T>
void TreeArr<T>::_ruleNode(size_t index)
{
	size_t currIndex = index;//将i节点规律化
	while (true)
	{
		size_t leftIndex = currIndex << 1 + 1;
		size_t rightIndex = currIndex << 1 + 1;
		if (leftIndex > len - 1)//左边越界右边一定越界
			break;//左边越界跳出
		//无论是否有右边,先定义左边小,既无右节点也是左边小
		bool isLeft = true;
		//有右子树就判断左右谁小,改变大小标志
		if (rigthIndex <= len - 1)
		{
			//如果右边的小,改变标志
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
			else//当前小就无需交换
				break;
		}
		else//和右交换
		{
			if (pBuf[currIndex] > pBuf[rightIndex])
			{
				T tempVal = pBuf[rightIndex];
				pBuf[rightIndex] = pBuf[currIndex];
				pBuf[currIndex] = tempVal;
				currIndex = rightIndex;
			}
			else//当前小就无需交换
				break;
		}
	}
}

template<class T>
void TreeArr<T>::initHeap(T const& arr, size_t srcLen)
{
	clear();//重置时候清空,防止内存泄露
	maxSize = srcLen;
	len = srcLen;
	pBuf = new T[maxSize];
	memmove(pBuf, arr, maxSize*sizeof(T));
	if (len == 0)
		return;
	//从最后一个有子节点的下标((len - 2) >> 1)开始
	//(len - 2) >> 1相当于((len - 1) - 1) >> 1;
	for (size_t i = (len - 2) >> 1; i >= 0; --i)
	{
		size_t currIndex = i;//将i节点规律化
		while (true)
		{
			size_t leftIndex = currIndex << 1 + 1;
			size_t rightIndex = currIndex << 1 + 1;
			if (leftIndex > len - 1)//左边越界右边一定越界
				break;//左边越界跳出
			//无论是否有右边,先定义左边小,既无右节点也是左边小
			bool isLeft = true;
			//有右子树就判断左右谁小,改变大小标志
			if (rigthIndex <= len - 1)
			{
				//如果右边的小,改变标志
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
				else//当前小就无需交换
					break;
			}
			else//和右交换
			{
				if (pBuf[currIndex] > pBuf[rightIndex])
				{
					T tempVal = pBuf[rightIndex];
					pBuf[rightIndex] = pBuf[currIndex];
					pBuf[currIndex] = tempVal;
					currIndex = rightIndex;
				}
				else//当前小就无需交换
					break;
			}
		}
	}

}

/************************************************************************/
/* 最小堆删除
1.只能删除根节点
2.把最后一个节点移动至根节点
3.判断根节点是否破坏了最小堆特点(父节点定小于子节点)
*/
/************************************************************************/
template<class T>
void TreeArr<T>::delHeap()
{
	if (len)
		return;
	//只有一个节点直接len--
	if (len > 1)//有两个以上节点
		pBuf[0] = pBuf[len - 1];//把最后一个节点给根...1...2
	size_t currIndex = 0;//将根节点规律化
	while (true)
	{
		size_t leftIndex = currIndex << 1 + 1;
		size_t rightIndex = currIndex << 1 + 1;
		if (leftIndex > len - 1)//左边越界右边一定越界
			break;//左边越界跳出
		//无论是否有右边,先定义左边小,既无右节点也是左边小
		bool isLeft = true;
		//有右子树就判断左右谁小,改变大小标志
		if (rigthIndex <= len - 1)
		{
			//如果右边的小,改变标志
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
			else//当前小就无需交换
				break;
		}
		else//和右交换
		{
			if (pBuf[currIndex] > pBuf[rightIndex])
			{
				T tempVal = pBuf[rightIndex];
				pBuf[rightIndex] = pBuf[currIndex];
				pBuf[currIndex] = tempVal;
				currIndex = rightIndex;
			}
			else//当前小就无需交换
				break;
		}
	}
	len--;
}

//最小堆插入
template<class T>
void TreeArr<T>::insertHeap(T const& val)
{
	appNode(val);
	size_t currIndex = len - 1;//当前插入值的下标
	size_t parentIndex = (currIndex - 1) >> 1;//当前下标的父下标
	while (currIndex)//若不为跟节点,继续循环比较
	{
		if (pBuf[currIndex]<pBuf[parentIndex])
		{
			T tempVal = pBuf[parentIndex];
			pBuf[parentIndex] = pBuf[currIndex];
			pBuf[currIndex] = tempVal;
		}
		else
			break;
		currIndex = parentIndex;//交换后更改当前(带插入值)下标
	}
}

//#######################函数实现
//------------------------------构造析构
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
//----------------------------操作函数
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
		_printTree(2 * index + 1);	//打印左子树
		_printTree(2 * index + 2);	//打印右子数
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
		//116行正确吗,按理说buf指向的内存小于sizeof(T)*maxSize呀,那岂不是内存越界访问了
		if (pBuf)
		{
			memmove(tmpBuf, this->pBuf, sizeof(T)*len);	//将内存内容移入
			delete[]pBuf;	//释放原buf内存
		}
		pBuf = tmpBuf;	//指向新空间
	}
	pBuf[len++] = data;
}

template<class T>
T const& TreeArr<T>::getParentVal(T const& findVal) const
{
	size_t tmpIndex = find(findVal);
	if (tmpIndex<=0)
	{	//找父节点的方法: 下标-1除以2
		throw "no parent!";
	}
	return pBuf[(tmpIndex - 1) >> 1];
}

template<class T>
T const& TreeArr<T>::getRightVal(T const& findVal) const
{
	size_t tmpIndex = find(findVal);
	//当是根节点或超出范围或自身是右节点时候抛异常
	if (tmpIndex<=0||tmpIndex >= len||tmpIndex%2 == 0)
	{	
		throw "no RightBrother!";
	}
	//找右节点的方法: 下标+1
	return pBuf[tmpIndex+1];
}

template<class T>
T const& TreeArr<T>::getLeftVal(T const& findVal) const
{
	size_t tmpIndex = find(findVal);
	//当是根节点或超出范围或自身是右节点时候抛异常
	if (tmpIndex <= 0 || tmpIndex % 2 == 0)
	{
		throw "no LeftBrother!";
	}
	//找右节点的方法: 下标-1
	return pBuf[tmpIndex - 1];
}