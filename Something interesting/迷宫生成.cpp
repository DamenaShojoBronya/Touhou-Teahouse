#include<stdio.h>
#include<time.h>
#include<iostream>
using namespace std;

#define m 20	//��
#define n 40	//��	
#define MAXSIZE 200	

typedef struct {
	int x;
	int y;
}PosType;

typedef struct {
	//int ord;//ͨ������·���ϵġ���š�
	PosType seat;//ͨ�������Թ��еġ�����λ�á�
	int direction;//�Ӵ�ͨ����������һͨ����ķ���
}SElemType;

typedef struct SqStack {
	SElemType data[MAXSIZE];
	int top;//ָ��ջ��Ԫ��
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

//��ջ
void push(SqStack &s, SElemType e) {
	if (!isFull(s)) {
		s.data[s.top] = e;
		s.top++;
	}
	else cout << "FULL";
}

//��ջ
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
	maze[curpos.x][curpos.y] = '*';//�߹��Ŀ�
}

void markPrint(PosType curpos) {
	maze[curpos.x][curpos.y] = '@';//�߹��Ҳ�ͨ�Ŀ�
}

PosType nextPos(PosType curpos, int direction) {
	switch (direction) {
	case 1: curpos.y++; break;//�����ߣ��кŲ��䣬�кż�1
	case 2: curpos.x++; break;//�����ߣ��кż�1���кŲ���
	case 3: curpos.y--; break;//�����ߣ��кŲ��䣬�кż�1
	case 4: curpos.x--; break;//�����ߣ��кż�1���кŲ���
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
	SqStack s;//ջ
	initStack(s);
	PosType a = start;//��ǰ����λ��
	do {
		if (pass(a)) {
			footPrint(a);
			SElemType e;//��ǰ���飬ջ������
			e.seat = a;
			e.direction = 1;
			push(s, e);
			if (a.x == end.x&&a.y == end.y) return true;
			a = nextPos(a, 1);
		}
		else {
			SElemType e;
			pop(s, e);//ջ����ջ�����ص���һ����
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
			if (maze[i][j] == '#') cout << "��";
			if (maze[i][j] == ' ') cout << "  ";
			if (maze[i][j] == '*') cout << " *";//·��
			if (maze[i][j] == '@') cout << " @";//��ͨ��·��
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
			cout << endl << "�Թ����ڳ��ڡ�" << endl << "·��Ϊ:" << endl << endl;
			printMaze();
			break;
		}
		else cout << "�޳���" << endl;
		printMaze(); cout << endl;
	}
}

int main()
{
	//printMaze();
	mazeGeneration(1, 1, 18, 38);

	return 0;
}