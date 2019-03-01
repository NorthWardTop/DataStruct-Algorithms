#pragma once

#include <stdio.h>
#include <stdlib.h>

#define MAX_V	5

template<class T>
class Map
{
public:
	Map();
	~Map();

private:
	int vertex[MAX_V];	//存放顶点的数组, 值是顶点序号
	T edge[MAX_V][MAX_V];	//存放边的邻接矩阵, 值是边的权重
	int edge_num; //边的条数
};

template<class T>
Map::Map()
{
	for (int i = 0; i < MAX_V; ++i)
		vertex[i] = i;
	edge[]
}

template<class T>
Map::~Map()
{
}