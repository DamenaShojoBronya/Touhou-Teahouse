#include "stdafx.h"

#define scanf scanf_s
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data; /* 存储结点数据 */
	PtrToNode   Next; /* 指向下一个结点的指针 */
	PtrToNode   prior; /* 指向一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

List Read() {
	Node *L;
	L = (Node *)malloc(sizeof(Node)); /*申请头结点*/
	L->Next = NULL;

	Node *r; r = L;
	r->Next = NULL;

	cout << "cin the len of list:" << endl;
	int len; scanf("%d", &len);
	int data;

	cout << "cin the data of list:" << endl;
	Node *p;
	while (len--) {
		scanf("%d", &data);
		p = (Node *)malloc(sizeof(Node));
		p->Data = data;
		p->Next = r->Next;
		r->Next = p;
		r = p;
	}
	r->Next = NULL;
	return L;
}

List Del(List L, int i) {			// 删除第i个元素
	int j = 0;
	List p = L;					// p指向上一结点
	while (p->Next && j < i - 1) {
		p = p->Next;
		j++;
	}
	if (!p->Next || j > i - 1) return false;
	List q = p->Next;
	p->Next = q->Next;
	free(q);
	return L;
}

int Find(List L, int x) {			// 查找x
	List p = L->Next;
	while (p != NULL) {
		if (p->Data == x) return 1;
		p = p->Next;
	}
	return 0;
}

void Print(List L) {
	L = L->Next;
	if (L->Data == NULL) exit(-1);
	else
		while (L != NULL) {
			printf("%d ", L->Data);
			L = L->Next;
		}
	putchar('\n');
}

int main()
{
	List list = Read();
	Print(list);
	cout << "--------创建链表-------------------" << endl;
	int i = 1;
	list = Del(list, i);
	Print(list);
	cout << "--------按位置删除-------------------" << endl;
	int x = 3;
	if (Find(list, x) == 1) cout << x << " is in L" << endl;
	else cout << x << " isnot in L" << endl;
	Print(list);
	cout << "--------查找元素-------------------" << endl;
	return 0;
}