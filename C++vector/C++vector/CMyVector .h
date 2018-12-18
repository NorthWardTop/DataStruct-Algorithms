/*
	重写vector,遇到的问题:
		0.调试时候监视对象元素值只显示首个值
		1.MyVector(size_t size);无法初始化元素值
		2.reserve()系统函数为随参数大小重新分配并赋值,与作业要求不符
*/

#pragma once
//#include <vector>
template<class T>
class MyVector
{
	T* pbuf;//类似于数据域
	size_t len;
	size_t maxSize;
public://构造析构
	MyVector();
	MyVector(MyVector const& other);//拷贝构造
	MyVector(size_t size);//带参(容器大小
	MyVector(size_t size, T val); //(容器大小,初始值)
	~MyVector();
public://运算符重载部分
	MyVector operator=(MyVector const& srcVector);//赋值
	//c[2];//同上,不检查下标范围,重载[]

public://操作函数
	size_t size() const { return len; }//返回值为不可修改
	size_t capacity() const { return maxSize; }
	void push_back(T const& val);//尾部压入
	void reserve(size_t count);//扩大最大容量,参数为容量大小,提前定义大小(sizeof(T)*参数),不能变小
	T const& at(size_t index) const;
	void pop_back();//删除(缩小访问范围)最后一个
	bool empty() const;//判断空
	void assign(size_t size, T const& val);//重置容器
	void print() const;
	void swap(MyVector* obj);//交换this对象和参数对象
	T const front() const;//返回第一个元素
	T const back() const;//返回最后一个元素
	void resize(size_t size);//重置大小,仅仅改变len
	void resize(size_t size, T val);//重置大小,大于部分用参数2初始化
	void clear();//清空容器
};

//-------------------------------------------构造析构--------------------------------
template<class T>
MyVector<T>::MyVector()
{
	pbuf = NULL;
	len = 0;
	maxSize = 0;
}

template<class T>
MyVector<T>::MyVector(MyVector const& other)//拷贝构造
{
	if (other.pbuf)
	{
		len = other.len;
		maxSize = other.maxSize;
		pbuf = new T[maxSize];
		memcpy(pbuf, other.pbuf, sizeof(T)*len);//copy内存,优化for循环
		/*for (size_t i = 0; i < len; ++i)
		{
			pbuf[i] = other.pbuf[i];
		}*/
	}
	else
	{
		pbuf = NULL;
	}
}

template<class T>
MyVector<T>::MyVector(size_t size)//带参(容器大小
{
	pbuf = new T[size];
	len = size;
	maxSize = size;
	//此处缺少元素初始化代码
}

template<class T>
MyVector<T>::MyVector(size_t size, T val) //(容器大小,初始值)
{
	pbuf = new T[size];
	len = size;
	maxSize = size;
	for (size_t i = 0; i < len; ++i)
		pbuf[i] = val;//初始化赋值
}

template<class T>
MyVector<T>::~MyVector()
{
	if (pbuf)
	{
		delete[]pbuf;
	}
	len = 0;
	maxSize = 0;
}
//--------------------------------------------操作函数-------------------

template <class T>
void MyVector<T>::push_back(T const& val)//尾部压入
{
	if (len >= maxSize)//目前长度大于最大空间,重新开辟(=是要保持半开区间
	{	//数据开辟空间数算法(内存不足,重新开辟,拷贝
		maxSize = maxSize + ((maxSize >> 1) > 1 ? (maxSize >> 1) : 1);
		T* pTmpBuf = new T[maxSize];//重新开辟所有内存
		memcpy(pTmpBuf, pbuf, sizeof(T)* len);//内存copy
		if (pbuf)//当pbuf为空时候不能delete
			delete []pbuf;//删除原内存空间
		pbuf = pTmpBuf;//指针指向新内存
	}   
	pbuf[len++] = val;//赋值数据(++是将原长度加1
}

template<class T>
void MyVector<T>::reserve(size_t count)
{//扩大最大容量,参数为容量大小,提前定义大小(sizeof(T)*参数),不能变小
	if (count > len && count > maxSize)
	{//如果参数大于容器最大值,重新开辟并赋值
		MyVector<T>* pTmp = new MyVector<T>;
		memcpy(pTmp, pbuf, len*sizeof(T));
		maxSize = count;//赋值新最大大小
	}
}

template<class T>
T const& MyVector<T>::at(size_t index) const
{//返回下标为2的元素值,超范围抛异常
	if (index<0||index>=len)
		throw "error:下标范围超出!";
	return pbuf[index];
}

template<class T>
void MyVector<T>::pop_back()//删除(缩小访问范围)最后一个
{
	if (len>0)
		len--;
}

template<class T>
bool MyVector<T>::empty() const//判断空
{
	if (len > 0)
		return 1;
	return 0;
}

template<class T>
void MyVector<T>::assign(size_t size, T const& val)//重置容器
{
	if (pbuf)
		delete[]pbuf;
	pbuf = new T[size];
	len = size;
	maxSize = size;
	for (size_t i = 0; i < len; ++i)
		pbuf[i] = val;//初始化赋值
}

template<class T>
void MyVector<T>::print() const
{
	cout << "打印结果:";
	for (size_t i = 0; i < len; ++i)
		cout << at(i) << "\t";
	cout << endl;
}

template<class T>
void MyVector<T>::swap(MyVector* obj)//交换this对象和参数对象
{
	/*
	MyVector<T>* pTmp = new MyVector<T>;//开辟临时的内存保存值
	memcpy(pTmp, obj, sizeof(&pTmp)>sizeof(&obj) ? sizeof(&pTmp):sizeof(&obj));//将参数指针copy到临时指针
	memcpy(obj, this, sizeof(&obj)>sizeof(&this) ? sizeof(&obj):sizeof(&this));//这里也许有bug,不知道obj空间能否足够保存this,进行判断从而确定内存大小
	memcpy(this, pTmp, sizeof(&this)>sizeof(&pTmp) ? sizeof(&this):sizeof(&pTmp));//bug同上
	if (pTmp)
	{
	delete pTmp;
	pTmp=NULL;
	}
	*/
	MyVector<T> pTmp = *obj;
	*obj = *this;
	*this = *pTmp;
	pTmp = NULL;
}

template<class T>
T const MyVector<T>::front() const//返回第一个元素
{
	return pbuf[0];
}

template<class T>
T const MyVector<T>::back() const//返回最后一个元素
{
	return pbuf[len - 1];
}

template<class T>
void MyVector<T>::resize(size_t size)//重置大小,仅仅改变len
{
	if (size <= len)
		len = size;
	else
	{
		T* pTmp = new T[size];
		memcpy(pTmp, pbuf, sizeof(T)*len);//将原来数值拷贝进去
		if (pbuf)//释放pbuf
		{
			delete pbuf;
			pbuf = NULL;
		}
		pbuf = pTmp;//pbuf指向新内存
		size_t oldLen = len;//保存旧长度(用于初始化多余空间
		len = size;
		//for (size_t i = oldLen; i < size; ++i){初始化多余空间}
	}
}

template <class T>
void MyVector<T>::resize(size_t size, T val)//重置大小,大于部分用参数2初始化
{
	if (size <= len)
		len = size;
	else
	{
		T* pTmp = new T[size];
		memcpy(pTmp, pbuf, sizeof(T)*len);//将原来数值拷贝进去
		if (pbuf)//释放pbuf
		{
			delete pbuf;
			pbuf = NULL;
		}
		pbuf = pTmp;//pbuf指向新内存
		size_t oldLen = len;//保存旧长度(用于初始化多余空间
		len = size;
		for (size_t i = oldLen; i < size; ++i)
		{//初始化多余空间
			pbuf[i] = val;
		}
	}
}

template<class T>
void MyVector<T>::clear()//删除所有元素清空容器
{
	if (pbuf)
	{
		delete[]pbuf;
	}
	len = 0;
	maxSize = 0;
}




















































//template<class T>
//MyVector MyVector::operator=(MyVector const& srcVector)
//{
//
//}