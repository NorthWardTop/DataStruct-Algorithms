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
	int vertex[MAX_V];	//��Ŷ��������, ֵ�Ƕ������
	T edge[MAX_V][MAX_V];	//��űߵ��ڽӾ���, ֵ�Ǳߵ�Ȩ��
	int edge_num; //�ߵ�����
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