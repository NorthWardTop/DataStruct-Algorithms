
// #include <vector>
// using std::vector;

/*
Constructors 构造函数 
Operators 对vector进行赋值或比较 

assign() 对Vector中的元素赋值 
at() 返回指定位置的元素 OK
back() 返回最末一个元素 
begin() 返回第一个元素的迭代器 
capacity() 返回vector所能容纳的元素数量(在不重新分配内存的情况下） 
clear() 清空所有元素 
empty() 判断Vector是否为空（返回true时为空） 
end() 返回最末元素的迭代器(译注:实指向最末元素的下一个位置) 
erase() 删除指定元素 
front() 返回第一个元素 
get_allocator() 返回vector的内存分配器 
insert() 插入元素到Vector中 
max_size() 返回Vector所能容纳元素的最大数量（上限） 
pop_back() 移除最后一个元素 
push_back() 在Vector最后添加一个元素 OK
rbegin() 返回Vector尾部的逆迭代器 
rend() 返回Vector起始的逆迭代器 
reserve() 设置Vector最小的元素容纳数量 
resize() 改变Vector元素数量的大小 
size() 返回Vector元素数量的大小 
swap() 交换两个Vector 
 */

/*
	vector();
	vector( size_type num, const TYPE &val );
	vector( const vector &from );
	vector( input_iterator start, input_iterator end );
	v1 == v2
	v1 != v2
	v1 <= v2
	v1 >= v2
	v1 < v2
	v1 > v2 
	v[]
	
	void assign( input_iterator start, input_iterator end );
 	void assign( size_type num, const TYPE &val );
	
	iterator erase( iterator loc );
	iterator erase( iterator start, iterator end );
	
	iterator insert( iterator loc, const TYPE &val );
	void insert( iterator loc, size_type num, const TYPE &val );
	void insert( iterator loc, input_iterator start, input_iterator end );

	TYPE at( size_type loc ); ok
	TYPE back(); ok
	

	void clear();
	bool empty();
	
	TYPE front(); ok

	void pop_back();
	void push_back( const TYPE &val );

	void swap( vector &from );

	iterator begin();
	iterator end();
	reverse_iterator rbegin();
	reverse_iterator rend();

	size_type capacity();
	allocator_type get_allocator();
	size_type max_size();
	void reserve( size_type size );
	void resize( size_type size, TYPE val );
	size_type size();



 */

#include <iostream>
#include "v.h"

#include <vector>


using namespace std;

template <class T>
void dbgPrint(Vector<T> v)
{
	size_t size = v.getSize();
	size_t capacity = v.getCapacity();
	T val;
	cout << '[' << size << '/' << capacity << ']' << '	' ;
	for (size_t i = 0; i < v.getSize(); ++i) {
		val = v.at(i);
		cout << val << ' ';
	}
	cout << endl;
}


template <class T>
void stdDbgPrint(vector<T> v)
{
	size_t size = v.size();
	size_t capacity = v.capacity();
	T val;
	cout << '[' << size << '/' << capacity << ']' << '	' ;
	for (size_t i = 0; i < v.size(); ++i) {
		val = v.at(i);
		cout << val << ' ';
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	Vector<int> v(4, 78);
	Vector<int> v2;
	v2 = v;
	dbgPrint<int>(v);
	dbgPrint<int>(v2);
	



	return 0;
}


