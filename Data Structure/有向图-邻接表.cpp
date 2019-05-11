#include <iostream>
#include <cstdio>
using namespace std;

#define MAX_POINT_NUM 100  //最大顶点个数
int vertex_num, arc_num;         //顶点数，边数

typedef struct arcnode {
	int vertex;
	int weight;      //边的权值
	arcnode* next;
	arcnode(int v, int w) :vertex(v), weight(w), next(NULL) {}
	arcnode(int v) :vertex(v), next(NULL) {}
};

struct vernode {
	int vex;
	arcnode* firstarc;   //该顶点与相邻顶点的边
}Ver[MAX_POINT_NUM];

void Insert(int a, int b, int w) {
	arcnode * q = new arcnode(b, w);
	if (Ver[a].firstarc == NULL)
		Ver[a].firstarc = q;
	else {
		arcnode* p = Ver[a].firstarc;
		q->next = p;
		Ver[a].firstarc = q;
	}
}

void Init() {
	for (int i = 0; i <= vertex_num; i++) {
		Ver[i].vex = i;
		Ver[i].firstarc = NULL;
	}
}

void Show()
{
	for (int i = 0; i < vertex_num; i++) {
		cout << Ver[i].vex;
		arcnode* p = Ver[i].firstarc;
		while (p != NULL) {
			cout << "->(" << p->vertex << "," << p->weight << ")";
			p = p->next;
		}
		cout << "->NULL" << endl;
	}
}

int main()
{
	cout << "please input vertex and arc" << endl;
	cin >> vertex_num >> arc_num;
	cout << "Input two vertices and the arc between them" << endl;
	Init();
	int a, b, w;
	while (arc_num--) {
		cin >> a >> b >> w;
		Insert(a, b, w);
	}
	Show();
	return 0;
}
//测试用例:
//4 8
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