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
	return 1;
}
//Î²²åÈë
void Put(LinkQueue *Q, int e) {
	QNodePtr p = (QNodePtr)malloc(sizeof(QNode));
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
}
//Í·É¾³ý
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
	return 1;
}

int main()
{
	LinkQueue *a;
	a = Init();
	for (int i = 0; i < 10; i++) {
		Put(a, i);
	}
	Print(*a);
	cout << "----------------------------" << endl;
	int e;
	Poll(a, e);
	Poll(a, e);
	Print(*a);
}