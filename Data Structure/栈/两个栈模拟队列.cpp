#ifndef _STRUCT_SIZE_H
#define _STRUCT_SIZE_H

#define SUCCESS  0

#define STACK_MAX_SIZE 5
typedef int ElemType;

typedef struct ST
{
	ElemType data[STACK_MAX_SIZE];  //存放数据
	int top;                       //栈顶指针
}myStack;

int InitQueue(void);
int EnQueue(int elem);
int DeQueue(int* elem);
int IsEmptyQueue(void);

#endif



#include "StructSize.h"

myStack g_myStack1, g_myStack2;

//初始化ST栈，初始化完成后的栈为空，没有任何元素；
int InitSt(struct ST* S)
{
	S->top = -1;
	return SUCCESS;
}

//元素x入ST栈；
int Push(struct ST* S, int x)
{
	if (S->top >= STACK_MAX_SIZE - 1)
	{
		return 1;
	}
	else
	{
		S->top++;
		S->data[S->top] = x;
		return SUCCESS;
	}
}

//ST栈顶元素出栈，赋给变量x；
int Pop(struct ST* S, int* x)
{
	if (S->top <= -1)
	{
		return 1;
	}
	else
	{
		*x = S->data[S->top];
		S->top--;
		return SUCCESS;
	}
}

//判ST栈是否为空。
int IsEmpty(struct ST* S)
{
	if (-1 == S->top)
	{
		return 1;
	}
	return 0;
}

//初始化队列，初始化完成后的队列为空，没有任何元素；
int InitQueue(void)
{
	InitSt(&g_myStack1);

	InitSt(&g_myStack2);

	return SUCCESS;
}

//将元素Elem插入队列，若入队列成功返回0，否则返回1。
int EnQueue(int Elem)
{
	int Result = 1;
	if (g_myStack1.top >= STACK_MAX_SIZE - 1)
	{
		if (g_myStack2.top >= STACK_MAX_SIZE - 1)
		{
			return 1;
		}
		else
		{
			while (g_myStack2.top < STACK_MAX_SIZE - 1)
			{
				int topData;
				Result = Pop(&g_myStack1, &topData);
				if (SUCCESS == Result)
				{
					Result = Push(&g_myStack2, topData);
				}
			}
			if (SUCCESS == Result)
			{
				Result = Push(&g_myStack1, Elem);
			}
		}
	}
	else
	{
		Result = Push(&g_myStack1, Elem);
	}
	return Result;
}

//从队列中取出一个元素放入pElem，若出队列成功返回0，否则返回1。
int DeQueue(int* pElem)
{
	int Result = 1;
	if (IsEmpty(&g_myStack1) && IsEmpty(&g_myStack2))
	{
		return 1;
	}
	else
	{
		if (IsEmpty(&g_myStack2))
		{
			int topData;
			while (!IsEmpty(&g_myStack1))
			{
				Result = Pop(&g_myStack1, &topData);
				if (SUCCESS == Result)
				{
					Result = Push(&g_myStack2, topData);
				}
			}
			if (SUCCESS == Result)
			{
				Result = Pop(&g_myStack2, pElem);
			}
		}
		else
		{
			Result = Pop(&g_myStack2, pElem);
		}
	}
	return Result;
}

//判用队列是否为空，如果是空则返回1，如果不是空则返回0。
int IsEmptyQueue(void)
{
	if (IsEmpty(&g_myStack1) && IsEmpty(&g_myStack2))
		return 1;
	return SUCCESS;
}