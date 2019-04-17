// ConsoleApplication130.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define scanf scanf_s

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data; /* �洢������� */
	PtrToNode   Next; /* ָ����һ������ָ�� */
};
typedef PtrToNode List; /* ���嵥�������� */

List Read(); /* ϸ���ڴ˲��� */
void Print(List L){
	if (L == NULL)
		return;
	else
		while (L != NULL) {
			printf("%d ", L->Data);
			L = L->Next;
		}
	putchar('\n');
} 
/* ϸ���ڴ˲��� */

List Reverse(List L);

int main()
{
	List L1, L2;
	L1 = Read();
	L2 = Reverse(L1);
	Print(L1);
	Print(L2);
	return 0;
}

List Read() {
	int len,data; List L = NULL;
	scanf("%d", &len);
	while (len--) {
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