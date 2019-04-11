#include<iostream>
using namespace std;

#define MAX_QSIZE 10 // 最大队列长度+1
// 阵列队列的存储结构
struct Queue {
	int Array[MAX_QSIZE]; // 阵列空间大小
	int front; // 队头
	int rear; // 队尾
	int length; // 队列长度
};

// 构造一个空队列Q
Queue* Q_Init() {
	Queue *Q = (Queue*)malloc(sizeof(Queue));
	if (!Q) {
		// 存储分配失败
		exit(OVERFLOW);
	}
	//初始化
	Q->front = Q->rear = Q->length = 0;
	return Q;
}

// 将Q清为空队列
void Q_Clear(Queue *Q) {
	//清除头尾下标和长度
	Q->front = Q->rear = Q->length = 0;
}

// 入列
int Q_Put(Queue *Q, int x) {
	//如果当前元素数量等于最大数量 返回 -1
	if (Q->rear + 1 == MAX_QSIZE) {
		return -1;
	}
	Q->Array[Q->rear] = x;
	Q->rear = Q->rear + 1;
	//length + 1
	Q->length = Q->length + 1;
	return 1;
}

// 出列
int Q_Poll(Queue *Q) {
	//如果当前元素数量等于最大数量 返回 -1
	if (Q->front + 1 == MAX_QSIZE)
		return -1;
	int x = Q->Array[Q->front];
	Q->front = Q->front + 1;
	// 移出后減少1
	Q->length = Q->length - 1;
	return x;
}