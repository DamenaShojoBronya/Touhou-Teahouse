#include<stdio.h>
#include<time.h>
#include<iostream>
using namespace std;

#define m 20	//行
#define n 40	//列	
#define MAXSIZE 200	

typedef struct {
	int x;
	int y;
}PosType;

typedef struct {
	//int ord;//通道块在路径上的“序号”
	PosType seat;//通道块在迷宫中的“坐标位置”
	int direction;//从此通道块走向下一通道块的方向
}SElemType;

typedef struct SqStack {
	SElemType data[MAXSIZE];
	int top;//指向栈顶元素
}SqStack;

void initStack(SqStack &s) {
	s.top = 0;
}

bool isEmpty(SqStack s) {
	if (s.top == 0) return true;
	else return false;
}

bool isFull(SqStack s) {
	if (s.top == MAXSIZE) {
		return true;
	}
	else return false;
}

//入栈
void push(SqStack &s, SElemType e) {
	if (!isFull(s)) {
		s.data[s.top] = e;
		s.top++;
	}
	else cout << "FULL";
}

//出栈
void pop(SqStack &s, SElemType &e) {
	if (!isEmpty(s)) {
		e = s.data[s.top - 1];
		s.top--;
	}
	else cout << "Empty";
}

char maze[m][n] = {
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
	{ '#', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#' },
	{ '#', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#' },
	{ '#', ' ', ' ', ' ', ' ', '#', '#', ' ', ' ', '#' },
	{ '#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#' },
	{ '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#' },
	{ '#', ' ', '#', '#', '#', ' ', '#', '#', ' ', '#' },
	{ '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' }
};

void footPrint(PosType curpos) {
	maze[curpos.x][curpos.y] = '*';//走过的块
}

void markPrint(PosType curpos) {
	maze[curpos.x][curpos.y] = '@';//走过且不通的块
}

PosType nextPos(PosType curpos, int direction) {
	switch (direction) {
	case 1: curpos.y++; break;//向右走，行号不变，列号加1
	case 2: curpos.x++; break;//向下走，行号加1，列号不变
	case 3: curpos.y--; break;//向左走，行号不变，列号减1
	case 4: curpos.x--; break;//向上走，行号减1，列号不变
	}
	return curpos;
}

bool pass(PosType curpos) {
	if (maze[curpos.x][curpos.y] == ' ')
		return true;
	else
		return false;
}

bool mazePath(PosType start, PosType end) {
	SqStack s;//栈
	initStack(s);
	PosType a = start;//当前方块位置
	do {
		if (pass(a)) {
			footPrint(a);
			SElemType e;//当前方块，栈的类型
			e.seat = a;
			e.direction = 1;
			push(s, e);
			if (a.x == end.x&&a.y == end.y) return true;
			a = nextPos(a, 1);
		}
		else {
			SElemType e;
			pop(s, e);//栈顶出栈，即回到上一方块
			while (e.direction == 4 && !isEmpty(s)) {
				markPrint(e.seat);
				pop(s, e);
			}
			if (e.direction < 4) {
				e.direction++;
				push(s, e);
				a = nextPos(e.seat, e.direction);
			}
		}
	} while (!isEmpty(s));
	return false;
}

void printMaze() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (maze[i][j] == '#') cout << "█";
			if (maze[i][j] == ' ') cout << "  ";
			if (maze[i][j] == '*') cout << " *";//路径
			if (maze[i][j] == '@') cout << " @";//不通的路径
			if (maze[i][j] == '?') cout << " ?";
		}
		cout << endl;
	}
}

void randMaze() {
	srand(time(0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if ((rand() % 3) == 1) maze[i][j] = '#';
			else maze[i][j] = ' ';
			if (i == 0 || i == m - 1) maze[i][j] = '#';
			if (j == 0 || j == n - 1) maze[i][j] = '#';
		}
	}
}

void mazeGeneration(int x1, int y1, int x2, int y2) {
	while (1) {
		randMaze();
		maze[x1][y1] = ' '; PosType Start = { x1, y1 };
		maze[x2][y2] = ' '; PosType End = { x2, y2 };
		printMaze();
		if (mazePath(Start, End)) {
			cout << endl << "迷宫存在出口。" << endl << "路径为:" << endl << endl;
			printMaze();
			break;
		}
		else cout << "无出口" << endl;
		printMaze(); cout << endl;
	}
}

int main()
{
	//printMaze();
	mazeGeneration(1, 1, 18, 38);

	return 0;
}