#include "stdafx.h"

#include<iostream>
using namespace std;

typedef struct QNode {
	int data;
	QNode *next;
}QNode, *QNodePtr;

typedef struct LinkQueue {
	QNodePtr front, rear;
}LinkQueue;

LinkQueue* Init() {
	LinkQueue* Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	if (!Q)
		exit(OVERFLOW);
	Q->front = Q->rear = (QNodePtr)malloc(sizeof(QNode));
	if (!Q->front)
		exit(OVERFLOW);
	Q->front->next = NULL;
	return Q;
}

void Destroy(LinkQueue *Q) {
	while (Q->front) {
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	free(Q);
}

void Clear(LinkQueue *Q) {
	QNodePtr p, q;
	Q->rear = Q->front;
	p = Q->front->next;
	Q->front->next = NULL;
	while (p) {
		q = p;
		p = p->next;
		free(q);
	}
}

int Empty(LinkQueue Q) {
	if (Q.front->next == NULL)
		return 1;
	else
		return -1;
}

int Length(LinkQueue Q) {
	int i = 0;
	QNodePtr p;
	p = Q.front;
	while (Q.rear != p) {
		i++;
		p = p->next;
	}
	return i;
}

void Print(LinkQueue Q) {
	int i = 0;
	QNodePtr p;
	p = Q.front;
	while (Q.rear != p) {
		i++;
		cout << p->next->data << endl;
		p = p->next;
	}
}

int GetHead(LinkQueue Q, int &e) {
	QNodePtr p;
	if (Q.front == Q.rear)
		return -1;
	p = Q.front->next;
	e = p->data;
	return e;
}
//尾插入
void Put(LinkQueue *Q, int e) {
	QNodePtr p = (QNodePtr)malloc(sizeof(QNode));
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
}
//头删除
int Poll(LinkQueue *Q, int &e) {
	QNodePtr p;
	if (Q->front == Q->rear)
		return -1;
	p = Q->front->next;
	e = p->data;
	//cout << "e=" << e << endl;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	//cout << "e=" << e << endl;
	return e;
}

int main()
{
	int n, i, x, temp;
	LinkQueue *Q;
	Q = Init();
	Put(Q, 1);//第一行元素入队
	for (n = 2; n <= 10; n++) {
		Put(Q, 1);//入队
		for (i = 1; i <= n - 2; i++) {
			temp = Poll(Q, temp);//出队的数赋给temp
			printf("%d ", temp);
			x = GetHead(*Q, x);
			temp = temp + x;
			Put(Q, temp);
		}
		x = Poll(Q, x);//出队
		printf("%d ", x);
		Put(Q, 1);
		printf("\n");
	}
	while (!Empty(*Q)) {
		x = Poll(Q, x);
		printf("%d ", x);

	}
}