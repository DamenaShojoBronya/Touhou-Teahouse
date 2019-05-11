#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAX_VALUE 10000 //初始化数组的默认值，相当于无限大
#define MAX_POINT_NUM 10  //最大顶点数

typedef int matrix[MAX_POINT_NUM][MAX_POINT_NUM];
typedef struct {
	matrix node;
	int vertex[MAX_POINT_NUM];//顶点
	int vertex_num;
	int arc_num;//边数
}digraph;

int locatevertex(digraph* graph, int v) {
	for (int i = 0; i<graph->vertex_num; i++) {
		if (graph->vertex[i] == v) {
			return i;
		}
	}
	return -1;
}

void init_digraph(digraph* graph) {
	cout << "please input vertex and arc" << endl;
	cin >> graph->vertex_num >> graph->arc_num;
	cout << "please input vertex point value" << endl;
	for (int i = 0; i<graph->vertex_num; i++) {
		cin >> graph->vertex[i];
	}
	for (int i = 0; i<graph->vertex_num; i++) {
		for (int j = 0; j<graph->vertex_num; j++) {
			graph->node[i][j] = MAX_VALUE;//初始化所有节点值
			if (i == j) graph->node[i][j] = 0;//顶点
		}
	}

	int v1, v2;
	int weight;
	cout << "Input two vertices and the arc between them" << endl;
	for (int k = 0; k<graph->arc_num; k++) {
		cin >> v1 >> v2 >> weight;
		int i = locatevertex(graph, v1);
		int j = locatevertex(graph, v2);
		graph->node[i][j] = weight;
	}
}

void print_digraph(digraph * graph) {
	for (int i = 0; i<graph->vertex_num; i++) {
		for (int j = 0; j<graph->vertex_num; j++) {
			if (graph->node[i][j] == MAX_VALUE) {
				cout << "N  ";
			}
			else {
				cout << graph->node[i][j] << "  ";
			}
		}
		cout << endl;
	}
}

int main(int argc, const char *argv[])
{
	digraph graph;
	init_digraph(&graph);
	print_digraph(&graph);

	return 0;
}
//测试用例:
//4 8
//0 1 2 3
/*
0 1 1
0 3 4
1 2 9
1 3 2
3 2 6
2 3 8
2 0 3
2 1 5
*/