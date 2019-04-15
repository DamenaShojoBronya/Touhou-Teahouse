#include "stdafx.h"
#include<iostream>

typedef int type;
using namespace std;

typedef struct stack {
	type data;
	struct stack *next;
}stack, *Stack;

//������ջ����
Stack CreateChainStack(Stack s)
{
	s = (Stack)malloc(sizeof(stack)); //�൱�������ͷ���
	if (NULL == s)
	{
		return NULL;
	}

	s->data = -1;
	s->next = NULL;
	return s;
}
//��ջ
Stack Push(Stack s, type data)
{
	Stack temp = (Stack)malloc(sizeof(stack));
	if (NULL == temp)
	{
		cout << "�����ڴ�ʧ��!" << endl;
		exit(-1);
	}

	temp->data = data;
	temp->next = s->next;

	s->next = temp;

	return s;
}

//������ջ�ĳ���
int LengthStack(Stack s)
{
	int i = 0;
	Stack temp = s->next;

	while (NULL != temp)
	{
		i++;
		temp = temp->next;
	}
	return i;
}

//��ջ
Stack Pop(Stack s)
{
	Stack temp;
	int len = LengthStack(s);
	if (NULL == s->next)
	{
		return NULL;
	}
	temp = s->next;
	s->next = temp->next;

	return temp;
}

//��ӡ��ջ�е�Ԫ��
void PrintSatck(Stack s)
{
	Stack temp = s->next;
	if (NULL == s->next)
	{
		exit(-1);
	}

	while (NULL != temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int a[6] = { 20,22,24,26,28,30 };

	Stack s = NULL;
	s = CreateChainStack(s);
	for (int i = 0; i<6; i++)
		Push(s, a[i]);

	PrintSatck(s);
	Stack tp = Pop(s);
	cout << tp->data << endl;
	return 0;
}