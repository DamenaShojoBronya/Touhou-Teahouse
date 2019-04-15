#include<iostream>
using namespace std;

#define MAXSIZE 100

typedef struct SqStack {
	int data[MAXSIZE];
	int top;//ָ��ջ��λ��
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
void push(SqStack &s, int e) {
	if (!isFull(s)) {
		s.data[s.top] = e;
		s.top++;
	}
	else cout << "FULL";
}

//��ջ
void pop(SqStack &s, int &e) {
	if (!isEmpty(s)) {
		e = s.data[s.top - 1];
		s.top--;
	}
	else cout << "Empty";
}

int main()
{
	SqStack a;
	initStack(a);
	for (int i = 0; i < MAXSIZE; i++) {
		push(a, i * 2);
	}
	for (int i = 0; i < 10; i++) {
		int e; pop(a, e);
	}
	for (int i = 0; i<100; i++) {
		cout << a.data[i] << " ";
		if (i % 10 == 0 && i != 0) cout << endl;
	}
	cout << endl << "-----------------------------" << endl;
	cout << a.data[a.top];//ջ��Ԫ��
	return 0;
}