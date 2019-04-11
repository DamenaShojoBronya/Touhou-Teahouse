#include<iostream>
using namespace std;

#define MAX_QSIZE 10 // �����г���+1
// ���ж��еĴ洢�ṹ
struct Queue {
	int Array[MAX_QSIZE]; // ���пռ��С
	int front; // ��ͷ
	int rear; // ��β
	int length; // ���г���
};

// ����һ���ն���Q
Queue* Q_Init() {
	Queue *Q = (Queue*)malloc(sizeof(Queue));
	if (!Q) {
		// �洢����ʧ��
		exit(OVERFLOW);
	}
	//��ʼ��
	Q->front = Q->rear = Q->length = 0;
	return Q;
}

// ��Q��Ϊ�ն���
void Q_Clear(Queue *Q) {
	//���ͷβ�±�ͳ���
	Q->front = Q->rear = Q->length = 0;
}

// ����
int Q_Put(Queue *Q, int x) {
	//�����ǰԪ����������������� ���� -1
	if (Q->rear + 1 == MAX_QSIZE) {
		return -1;
	}
	Q->Array[Q->rear] = x;
	Q->rear = Q->rear + 1;
	//length + 1
	Q->length = Q->length + 1;
	return 1;
}

// ����
int Q_Poll(Queue *Q) {
	//�����ǰԪ����������������� ���� -1
	if (Q->front + 1 == MAX_QSIZE)
		return -1;
	int x = Q->Array[Q->front];
	Q->front = Q->front + 1;
	// �Ƴ���p��1
	Q->length = Q->length - 1;
	return x;
}