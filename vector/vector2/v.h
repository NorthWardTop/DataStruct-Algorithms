
#ifndef _V_H_
#define _V_H_

#include <string.h>
#include <malloc.h>


template<class T>
class Vector
{
private:
	T *pBuf;
	size_t size;
	size_t capacity;
public:
	struct Iterator {
		T *pHead;
		Iterator();

		void operator=(Iterator const& src); //已测试
		Iterator & operator++(); //++i  //已测试
		const Iterator operator++(int i = 0); //i++ //已测试
		Iterator & operator--(); //--i  //已测试
		const Iterator operator--(int i = 0); //i--  //已测试
		void operator-=(int index);  //已测试
		void operator+=(int index); //已测试
		Iterator operator+(int index) const; //已测试
		Iterator operator-(int index) const; //已测试
		size_t operator+(Iterator const& it); //已测试
		size_t operator-(Iterator const& it); //已测试

		bool operator!=(Iterator const& it) const; //已测试
		bool operator==(Iterator const& it) const; //已测试
		bool operator<=(Iterator const& it) const; //已测试
		bool operator<(Iterator const& it) const; //已测试
		bool operator>=(Iterator const& it) const; //已测试
		bool operator>(Iterator const& it) const; //已测试

		T const& operator[](int index) const; //已测试
		T 	& operator*(); //已测试
		T const *const operator->() const;
	};
public: //构造析构
	Vector();
	Vector(Vector<T> const& other); //已测试
	Vector(size_t num, T const& val); //已测试
	Vector(Vector<T>::Iterator begin, Vector<T>::Iterator end); //已测试
	~Vector();
public: //获取属性/读函数
	Iterator begin() const; //已测试
	Iterator end() const; //已测试
	size_t getSize() const; //已测试
	size_t getCapacity() const; //已测试
public: //容器属性操作
	void reserve(size_t sz); //已测试,与库函数有区别
	void resize(size_t sz, T const& val); //已测试
public: //运算符重载
	void operator=(Vector<T> const& srcVector); //已测试
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
public:
	void push_back(T const& val); //已测试
	void pop_back(); //已测试
	void assign(size_t num, T const& val); //已测试
	void assign(Iterator begin, Iterator end ); //已测试
	Iterator erase(Iterator loc); //已测试
	Iterator erase(Iterator begin, Iterator end);

	void clear(); //已测试
	void swap(Vector &from); //已测试
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


template <class T>
Vector<T>::Vector(Vector<T>::Iterator begin, Vector<T>::Iterator end)
{
	this->size = end - begin;
	this->capacity = this->size;
	this->pBuf = new T[this->size];
	//memcpy(this->pBuf, begin, this->size);
	for (size_t i = 0; i < this->size; ++i) 
		this->pBuf[i] = begin.pHead[i];
}

template<class T>
Vector<T>::~Vector()
{
	if (pBuf) 
		delete []pBuf;
}


template<class T>
Vector<T>::Iterator::Iterator()
{
	this->pHead = NULL;
}

template<class T>
void Vector<T>::Iterator::operator=(Iterator const& src)
{
	this->pHead = src.pHead;
}

template<class T>
typename Vector<T>::Iterator & Vector<T>::Iterator::operator++() //++i 
{
	++pHead;
	return *this;
}

template<class T>
const typename Vector<T>::Iterator 
Vector<T>::Iterator::operator++(int i = 0) //i++
{
	Iterator tmp = *this; //使用=
	++(*this); //使用前++
	return tmp;
}

template<class T>
typename Vector<T>::Iterator & Vector<T>::Iterator::operator--() //--i 
{
	--pHead;
	return *this;
}

template<class T>
typename Vector<T>::Iterator const Vector<T>::Iterator::operator--(int i = 0) //i--
{
	Iterator tmp = *this; //使用=
	--(*this); //使用前++
	return tmp;
}

template<class T>
void Vector<T>::Iterator::operator-=(int index) 
{
	this->pHead-=index;
}

template<class T>
void Vector<T>::Iterator::operator+=(int index) 
{
	this->pHead+=index;
}

template<class T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator+(int index) const
{
	Iterator tmp = *this;
	tmp.pHead += index;
	return tmp;
}

template<class T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator-(int index) const
{
	Iterator tmp = *this;
	tmp.pHead -= index;
	return tmp;
}

// template<class T>
// typename size_t Vector<T>::Iterator::operator+(Iterator const& it)  //已测试
// {
// 	return 
// }

template<class T>
size_t Vector<T>::Iterator::operator-(Iterator const& it)  //已测试
{
	return (this->pHead - it.pHead);
}

template<class T>
bool Vector<T>::Iterator::operator!=(Iterator const& it) const
{
	return (pHead != it.pHead);
}

template<class T>
bool Vector<T>::Iterator::operator==(Iterator const& it) const
{
	return (pHead == it.pHead);
}

template<class T>
bool Vector<T>::Iterator::operator<=(Iterator const& it) const
{
	return (this->pHead <= it.pHead);
}

template<class T>
bool Vector<T>::Iterator::operator<(Iterator const& it) const
{
	return (this->pHead < it.pHead);
}

template<class T>
bool Vector<T>::Iterator::operator>=(Iterator const& it) const
{
	return (this->pHead >= it.pHead);
}

template<class T>
bool Vector<T>::Iterator::operator>(Iterator const& it) const
{
	return (this->pHead > it.pHead);
}

template<class T>
T const& Vector<T>::Iterator::operator[](int index) const
{
	return *(this->pHead);
}

template<class T>
T & Vector<T>::Iterator::operator*()
{
	return *(this->pHead);
}

template<class T>
T const *const Vector<T>::Iterator::operator->() const
{
	return this->pHead;
}


/**
 * @description: 属性获取
 * @param {type} 
 * @return: 
 */
template<class T> 
typename Vector<T>::Iterator Vector<T>::begin() const
{
	Iterator tmp;
	tmp.pHead = pBuf;
	return tmp;
}

template<class T> 
typename Vector<T>::Iterator Vector<T>::end() const
{
	Iterator tmp;
	tmp.pHead = pBuf + size;
	return tmp;
}


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
	this->size = 0;
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
void Vector<T>::assign(Iterator begin, Iterator end)
{
	this->clear();
	for (Iterator i = begin; i < end; ++i)
		this->push_back(*i);
}

template <class T>
typename Vector<T>::Iterator Vector<T>::erase(Iterator loc)
{
	Iterator tmp = loc;
	for (; tmp < this->end(); ++tmp)
		*tmp = *(tmp+1);
	this->size--;
	return loc;
}

// template <class T>
// Vector<T>::Iterator Vector<T>::erase(Iterator begin, Iterator end)
// {

// }

template <class T>
void Vector<T>::swap(Vector &from)
{
	Vector<T> tmp;
	tmp = *this;
	*this = from;
	from = tmp;
}


#endif