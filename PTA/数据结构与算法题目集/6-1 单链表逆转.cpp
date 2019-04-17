// ConsoleApplication130.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define scanf scanf_s

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data; /* 存储结点数据 */
	PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

List Read(); /* 细节在此不表 */
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
/* 细节在此不表 */

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
	List p1 = NULL;        //初始为空
	while (L != NULL) {	   
		List p2 = L;
		L = L->Next;	   //原链表指针顺序访问
		p2->Next = p1;	   //p2=L,P1=P2-1;P2指向p1,即颠倒指针方向
		p1 = p2;
	}
	return p1;
}