#include "stdafx.h"

#define scanf scanf_s
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;				/* �洢������� */
	PtrToNode   Next;				/* ָ����һ������ָ�� */
};
typedef PtrToNode List;				/* ���嵥�������� */

List Read() {						/* ��������*/
	int len, data; List L = NULL;
	cout << "cin the len of list:" << endl;
	scanf("%d", &len);
	cout << "cin the data of list:" << endl;
	while (len--) {					/*��ֵ*/
		scanf("%d", &data);
		PtrToNode p = (Node *)malloc(sizeof(Node));
		p->Data = data;
		p->Next = NULL;
		if (L == NULL) {
			L = p;
		}
		else {
			PtrToNode tmp = L;
			while (tmp->Next) {
				tmp = tmp->Next;
			}
			tmp->Next = p;
		}
	}
	return L;
}

void Print(List L) {
	if (L == NULL)
		return;
	else
		while (L != NULL) {
			printf("%d ", L->Data);
			L = L->Next;
		}
	putchar('\n');
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

List Reverse(List L) {
	List p1 = NULL;        //��ʼΪ��
	while (L != NULL) {
		List p2 = L;
		L = L->Next;	   //ԭ����ָ��˳�����
		p2->Next = p1;	   //p2=L,P1=P2-1;P2ָ��p1,���ߵ�ָ�뷽��
		p1 = p2;
	}
	return p1;
}

int Find(List L, int x) {			// ����x
	List p = L->Next;
	while (p != NULL) {
		if (p->Data == x) return 1;
		p = p->Next;
	}
	return 0;
}

int main()
{
	List list;

	list = Read();
	Print(list);
	cout << "--------��������-------------------" << endl;
	List tmp = Reverse(list);
	Print(tmp);
	cout << "--------��ת����-------------------" << endl;
	list = Reverse(tmp);
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