#include "stdafx.h"

#define scanf scanf_s
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data; /* �洢������� */
	PtrToNode   Next; /* ָ����һ������ָ�� */
	PtrToNode   prior; /* ָ��һ������ָ�� */
};
typedef PtrToNode List; /* ���嵥�������� */

List Read() {
	Node *L;
	L = (Node *)malloc(sizeof(Node)); /*����ͷ���*/
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

List Del(List L, int i) {			// ɾ����i��Ԫ��
	int j = 0;
	List p = L;					// pָ����һ���
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

int Find(List L, int x) {			// ����x
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
	cout << "--------��������-------------------" << endl;
	int i = 1;
	list = Del(list, i);
	Print(list);
	cout << "--------��λ��ɾ��-------------------" << endl;
	int x = 3;
	if (Find(list, x) == 1) cout << x << " is in L" << endl;
	else cout << x << " isnot in L" << endl;
	Print(list);
	cout << "--------����Ԫ��-------------------" << endl;
	return 0;
}