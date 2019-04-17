#ifndef _STRUCT_SIZE_H
#define _STRUCT_SIZE_H

#define SUCCESS  0

#define STACK_MAX_SIZE 5
typedef int ElemType;

typedef struct ST
{
	ElemType data[STACK_MAX_SIZE];  //�������
	int top;                       //ջ��ָ��
}myStack;

int InitQueue(void);
int EnQueue(int elem);
int DeQueue(int* elem);
int IsEmptyQueue(void);

#endif



#include "StructSize.h"

myStack g_myStack1, g_myStack2;

//��ʼ��STջ����ʼ����ɺ��ջΪ�գ�û���κ�Ԫ�أ�
int InitSt(struct ST* S)
{
	S->top = -1;
	return SUCCESS;
}

//Ԫ��x��STջ��
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

//STջ��Ԫ�س�ջ����������x��
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

//��STջ�Ƿ�Ϊ�ա�
int IsEmpty(struct ST* S)
{
	if (-1 == S->top)
	{
		return 1;
	}
	return 0;
}

//��ʼ�����У���ʼ����ɺ�Ķ���Ϊ�գ�û���κ�Ԫ�أ�
int InitQueue(void)
{
	InitSt(&g_myStack1);

	InitSt(&g_myStack2);

	return SUCCESS;
}

//��Ԫ��Elem������У�������гɹ�����0�����򷵻�1��
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

//�Ӷ�����ȡ��һ��Ԫ�ط���pElem���������гɹ�����0�����򷵻�1��
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

//���ö����Ƿ�Ϊ�գ�����ǿ��򷵻�1��������ǿ��򷵻�0��
int IsEmptyQueue(void)
{
	if (IsEmpty(&g_myStack1) && IsEmpty(&g_myStack2))
		return 1;
	return SUCCESS;
}