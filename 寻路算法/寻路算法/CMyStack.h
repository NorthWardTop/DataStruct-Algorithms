#pragma once

template<class T>
class CMyStack
{
public:
	CMyStack();
	~CMyStack();
	bool isEmpty() const;
	T getTop() const;
	void pop();
	void push(T const& data);
private:
	T *pBuf;
	size_t maxSize;
	size_t len;
};

template<class T>
void CMyStack<T>::push(T const& data)
{
	if (len >= maxSize)
	{
		maxSize = maxSize + ((maxSize >> 1) > 1 ? (maxSize >> 1) : 1);
		T* temp = new T[maxSize];
		memmove(temp, pBuf, sizeof(T)*len);
		if (pBuf)
			delete[]pBuf;
		pBuf = temp;
	}
	pBuf[len++] = data;
}

template<class T>
void CMyStack<T>::pop()
{
	len--;
}

template<class T>
T CMyStack<T>::getTop() const
{
	return pBuf[len-1];
}

template<class T>
bool CMyStack<T>::isEmpty() const
{
	return len==0;
}

template<class T>
CMyStack<T>::~CMyStack()
{
	if (pBuf)
		delete[]pBuf;
	pBuf = NULL;
	maxSize = 0;
	len = 0;
}

template<class T>
CMyStack<T>::CMyStack()
{
	pBuf = NULL;
	maxSize = 0;
	len = 0;
}




