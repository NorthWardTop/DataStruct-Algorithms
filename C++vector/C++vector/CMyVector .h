/*
	��дvector,����������:
		0.����ʱ����Ӷ���Ԫ��ֵֻ��ʾ�׸�ֵ
		1.MyVector(size_t size);�޷���ʼ��Ԫ��ֵ
		2.reserve()ϵͳ����Ϊ�������С���·��䲢��ֵ,����ҵҪ�󲻷�
*/

#pragma once
//#include <vector>
template<class T>
class MyVector
{
	T* pbuf;//������������
	size_t len;
	size_t maxSize;
public://��������
	MyVector();
	MyVector(MyVector const& other);//��������
	MyVector(size_t size);//����(������С
	MyVector(size_t size, T val); //(������С,��ʼֵ)
	~MyVector();
public://��������ز���
	MyVector operator=(MyVector const& srcVector);//��ֵ
	//c[2];//ͬ��,������±귶Χ,����[]

public://��������
	size_t size() const { return len; }//����ֵΪ�����޸�
	size_t capacity() const { return maxSize; }
	void push_back(T const& val);//β��ѹ��
	void reserve(size_t count);//�����������,����Ϊ������С,��ǰ�����С(sizeof(T)*����),���ܱ�С
	T const& at(size_t index) const;
	void pop_back();//ɾ��(��С���ʷ�Χ)���һ��
	bool empty() const;//�жϿ�
	void assign(size_t size, T const& val);//��������
	void print() const;
	void swap(MyVector* obj);//����this����Ͳ�������
	T const front() const;//���ص�һ��Ԫ��
	T const back() const;//�������һ��Ԫ��
	void resize(size_t size);//���ô�С,�����ı�len
	void resize(size_t size, T val);//���ô�С,���ڲ����ò���2��ʼ��
	void clear();//�������
};

//-------------------------------------------��������--------------------------------
template<class T>
MyVector<T>::MyVector()
{
	pbuf = NULL;
	len = 0;
	maxSize = 0;
}

template<class T>
MyVector<T>::MyVector(MyVector const& other)//��������
{
	if (other.pbuf)
	{
		len = other.len;
		maxSize = other.maxSize;
		pbuf = new T[maxSize];
		memcpy(pbuf, other.pbuf, sizeof(T)*len);//copy�ڴ�,�Ż�forѭ��
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
MyVector<T>::MyVector(size_t size)//����(������С
{
	pbuf = new T[size];
	len = size;
	maxSize = size;
	//�˴�ȱ��Ԫ�س�ʼ������
}

template<class T>
MyVector<T>::MyVector(size_t size, T val) //(������С,��ʼֵ)
{
	pbuf = new T[size];
	len = size;
	maxSize = size;
	for (size_t i = 0; i < len; ++i)
		pbuf[i] = val;//��ʼ����ֵ
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
//--------------------------------------------��������-------------------

template <class T>
void MyVector<T>::push_back(T const& val)//β��ѹ��
{
	if (len >= maxSize)//Ŀǰ���ȴ������ռ�,���¿���(=��Ҫ���ְ뿪����
	{	//���ݿ��ٿռ����㷨(�ڴ治��,���¿���,����
		maxSize = maxSize + ((maxSize >> 1) > 1 ? (maxSize >> 1) : 1);
		T* pTmpBuf = new T[maxSize];//���¿��������ڴ�
		memcpy(pTmpBuf, pbuf, sizeof(T)* len);//�ڴ�copy
		if (pbuf)//��pbufΪ��ʱ����delete
			delete []pbuf;//ɾ��ԭ�ڴ�ռ�
		pbuf = pTmpBuf;//ָ��ָ�����ڴ�
	}   
	pbuf[len++] = val;//��ֵ����(++�ǽ�ԭ���ȼ�1
}

template<class T>
void MyVector<T>::reserve(size_t count)
{//�����������,����Ϊ������С,��ǰ�����С(sizeof(T)*����),���ܱ�С
	if (count > len && count > maxSize)
	{//������������������ֵ,���¿��ٲ���ֵ
		MyVector<T>* pTmp = new MyVector<T>;
		memcpy(pTmp, pbuf, len*sizeof(T));
		maxSize = count;//��ֵ������С
	}
}

template<class T>
T const& MyVector<T>::at(size_t index) const
{//�����±�Ϊ2��Ԫ��ֵ,����Χ���쳣
	if (index<0||index>=len)
		throw "error:�±귶Χ����!";
	return pbuf[index];
}

template<class T>
void MyVector<T>::pop_back()//ɾ��(��С���ʷ�Χ)���һ��
{
	if (len>0)
		len--;
}

template<class T>
bool MyVector<T>::empty() const//�жϿ�
{
	if (len > 0)
		return 1;
	return 0;
}

template<class T>
void MyVector<T>::assign(size_t size, T const& val)//��������
{
	if (pbuf)
		delete[]pbuf;
	pbuf = new T[size];
	len = size;
	maxSize = size;
	for (size_t i = 0; i < len; ++i)
		pbuf[i] = val;//��ʼ����ֵ
}

template<class T>
void MyVector<T>::print() const
{
	cout << "��ӡ���:";
	for (size_t i = 0; i < len; ++i)
		cout << at(i) << "\t";
	cout << endl;
}

template<class T>
void MyVector<T>::swap(MyVector* obj)//����this����Ͳ�������
{
	/*
	MyVector<T>* pTmp = new MyVector<T>;//������ʱ���ڴ汣��ֵ
	memcpy(pTmp, obj, sizeof(&pTmp)>sizeof(&obj) ? sizeof(&pTmp):sizeof(&obj));//������ָ��copy����ʱָ��
	memcpy(obj, this, sizeof(&obj)>sizeof(&this) ? sizeof(&obj):sizeof(&this));//����Ҳ����bug,��֪��obj�ռ��ܷ��㹻����this,�����жϴӶ�ȷ���ڴ��С
	memcpy(this, pTmp, sizeof(&this)>sizeof(&pTmp) ? sizeof(&this):sizeof(&pTmp));//bugͬ��
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
T const MyVector<T>::front() const//���ص�һ��Ԫ��
{
	return pbuf[0];
}

template<class T>
T const MyVector<T>::back() const//�������һ��Ԫ��
{
	return pbuf[len - 1];
}

template<class T>
void MyVector<T>::resize(size_t size)//���ô�С,�����ı�len
{
	if (size <= len)
		len = size;
	else
	{
		T* pTmp = new T[size];
		memcpy(pTmp, pbuf, sizeof(T)*len);//��ԭ����ֵ������ȥ
		if (pbuf)//�ͷ�pbuf
		{
			delete pbuf;
			pbuf = NULL;
		}
		pbuf = pTmp;//pbufָ�����ڴ�
		size_t oldLen = len;//����ɳ���(���ڳ�ʼ������ռ�
		len = size;
		//for (size_t i = oldLen; i < size; ++i){��ʼ������ռ�}
	}
}

template <class T>
void MyVector<T>::resize(size_t size, T val)//���ô�С,���ڲ����ò���2��ʼ��
{
	if (size <= len)
		len = size;
	else
	{
		T* pTmp = new T[size];
		memcpy(pTmp, pbuf, sizeof(T)*len);//��ԭ����ֵ������ȥ
		if (pbuf)//�ͷ�pbuf
		{
			delete pbuf;
			pbuf = NULL;
		}
		pbuf = pTmp;//pbufָ�����ڴ�
		size_t oldLen = len;//����ɳ���(���ڳ�ʼ������ռ�
		len = size;
		for (size_t i = oldLen; i < size; ++i)
		{//��ʼ������ռ�
			pbuf[i] = val;
		}
	}
}

template<class T>
void MyVector<T>::clear()//ɾ������Ԫ���������
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