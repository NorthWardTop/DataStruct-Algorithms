#ifndef _V_H_
#define _V_H_

#include <string.h>


template<class T>
class Vector
{
private:
	T *pBuf;
	size_t size;
	size_t capacity;
public: //构造析构
	Vector();
	Vector(Vector<T> const& other); //已测试
	Vector(size_t num, T const& val); //已测试
	// Vector(Vector<T>::iterator begin, Vector<T>::iterator end);
	~Vector();
public: //获取属性/读函数
	size_t getSize() const; //已测试
	size_t getCapacity() const; //已测试
public: //容器属性操作
	void reserve(size_t sz); //已测试,与库函数有区别
	void resize(size_t sz, T const& val); //已测试
public: //运算符重载
	void operator=(Vector<T> const& srcVector); //已测试(有bug)
	T & operator[](size_t const i) const; //已测试
	bool operator==(Vector<T> const& rval) const; //已测试
	bool operator!=(Vector<T> const& rval) const; //已测试
	bool operator>(Vector<T> const& rval) const; //已测试
	bool operator<(Vector<T> const& rval) const; //已测试
	bool operator>=(Vector<T> const& rval) const; //已测试
	bool operator<=(Vector<T> const& rval) const; //已测试
public: //数据操作 
	T & at(size_t const i) const; //已测试
	T & front() const; //已测试 
	T & back() const; //已测试
	bool empty() const; //已测试
	
	void push_back(T const& val); //已测试
	void pop_back(); //已测试
	void clear(); //已测试
	void assign(size_t num, T const& val); //已测试
	void swap(Vector &from);
};


/**
 * @description: 构造函数
 * @param {type} 
 * @return: 
 */
template<class T>
Vector<T>::Vector()
{
	pBuf = NULL;
	size = 0;
	capacity = 0;
}

template<class T>
Vector<T>::Vector(Vector const& other)
{
	size = other.size;
	capacity = other.capacity;
	if (other.pBuf) {
		pBuf = new T[other.capacity];
		memcpy(pBuf, other.pBuf, sizeof(T)*size);
	} else {
		pBuf = NULL;
	}
}

template <class T>
Vector<T>::Vector(size_t num, T const& val)
{
	size = num;
	capacity = num;
	pBuf = new T[sizeof(T)*size];
	for (size_t i = 0; i < size; ++i) 
		pBuf[i] = val;
}


template<class T>
Vector<T>::~Vector()
{
	if (pBuf) 
		delete []pBuf;
}


/**
 * @description: 属性获取
 * @param {type} 
 * @return: 
 */
template<class T> 
size_t Vector<T>::getSize() const
{
	return size;
}

template<class T> 
size_t Vector<T>::getCapacity() const
{
	return capacity;
}

template<class T> 
void Vector<T>::reserve(size_t sz) 
{
	if (sz < size) 
		return;
	capacity = sz + ((sz >> 1) > 1 ? sz >> 1:1);
}

template<class T> 
void Vector<T>::resize(size_t sz, T const& val)
{
	if ( sz > this->size) 
		for (size_t i = size - 1; i < sz; ++i)
			this->push_back(val);
	size = sz;
}

/**
 * @description: 运算符重载函数
 * @param {type} 
 * @return: 
 */
template <class T>
T & Vector<T>::operator[](size_t i) const
{
	return pBuf[i];
}

template <class T>
void Vector<T>::operator=(Vector<T> const& srcv)
{
	this->size = srcv.size;
	this->capacity = srcv.capacity;
	this->pBuf = new T[this->capacity];
	memcpy(this->pBuf, srcv.pBuf, (this->size)*sizeof(T));
}

template <class T>
bool Vector<T>::operator==(Vector<T> const& rval) const
{
	bool ret = true;
	if (size == rval.size && capacity == rval.capacity) {
		// if (memcmp(this->pBuf, rval.pBuf, size)) 
		// 	ret = true;
		// else 
		// 	ret = false;
		for (size_t i = 0; i < size; ++i) {
			if (this->pBuf[i] != rval.pBuf[i]) {
				ret = false;
				break;
			}
		}
	} else 
		ret = false;
	return ret;
}

template <class T>
bool Vector<T>::operator!=(Vector<T> const& rval) const
{
	return !(*this == rval);
}

template <class T>
bool Vector<T>::operator>(Vector<T> const& rval) const
{
	bool ret = true;
	size_t min = size < rval.size ? size:rval.size;
	size_t i;
	for (i = 0; i < min; ++i) {
		if (pBuf[i] < rval.pBuf[i]) {
			ret = false;
			break;
		}
	}
	if (i == min && size <= rval.size) 
		ret = false;
	return ret;
}

template <class T>
bool Vector<T>::operator<(Vector<T> const& rval) const
{
	bool ret = true;
	size_t min = size < rval.size ? size:rval.size;
	size_t i;
	for (i = 0; i < min; ++i) {
		if (pBuf[i] > rval.pBuf[i]) {
			ret = false;
			break;
		}
	}
	if (i == min && size >= rval.size) 
		ret = false;
	return ret;
}

template <class T>
bool Vector<T>::operator>=(Vector<T> const& rval) const
{
	return !(*this < rval);
}

template <class T>
bool Vector<T>::operator<=(Vector<T> const& rval) const
{
	return !(*this > rval);
}

/**
 * @description: 数据操纵函数
 * @param {type} 
 * @return: 
 */
template<class T>
T & Vector<T>::at(size_t const i) const
{
	if (i <= size)
		return pBuf[i];
	else
		throw "index out of range!";
}

template<class T>
T & Vector<T>::front() const
{
	return pBuf[0];
}

template<class T>
T & Vector<T>::back() const
{
	return pBuf[size - 1];
}

template<class T>
bool Vector<T>::empty() const
{
	return size == 0 ? true:false;
}

template<class T>
void Vector<T>::push_back(T const& val)
{
	if (size >= capacity) {
		capacity += ((capacity >> 1) > 1 ? (capacity >> 1): 1);	
		T *tmpBuf = new T[capacity];
		memcpy(tmpBuf, pBuf, sizeof(T)*size);
		if (pBuf) 
			delete []pBuf;
		pBuf = tmpBuf;
	}
	pBuf[size++] = val;
}

template <class T>
void Vector<T>::pop_back()
{
	if (size > 0)
		size--;
}

template <class T>
void Vector<T>::clear()
{
	size = 0;
}

template <class T>
void Vector<T>::assign(size_t num, T const& val)
{
	for (size_t i = 0; i < num; ++i) {
		if (i < this->size)
			this->pBuf[i] = val;
		else
			this->push_back(val);
	}
}

template <class T>
void Vector<T>::swap(Vector &from)
{
	Vector<T> tmp;
	tmp = *this;
	*this = from;
	from = tmp;
}


#endif