#include "stdafx.h"

#define scanf scanf_s
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;				/* 存储结点数据 */
	PtrToNode   Next;				/* 指向下一个结点的指针 */
};
typedef PtrToNode List;				/* 定义单链表类型 */

List Read() {						/* 创建链表*/
	int len, data; List L = NULL;
	cout << "cin the len of list:" << endl;
	scanf("%d", &len);
	cout << "cin the data of list:" << endl;
	while (len--) {					/*赋值*/
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

List Reverse(List L) {
	List p1 = NULL;        //初始为空
	while (L != NULL) {
		List p2 = L;
		L = L->Next;	   //原链表指针顺序访问
		p2->Next = p1;	   //p2=L,P1=P2-1;P2指向p1,即颠倒指针方向
		p1 = p2;
	}
	return p1;
}

int Find(List L, int x) {			// 查找x
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
	cout << "--------创建链表-------------------" << endl;
	List tmp = Reverse(list);
	Print(tmp);
	cout << "--------翻转链表-------------------" << endl;
	list = Reverse(tmp);
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