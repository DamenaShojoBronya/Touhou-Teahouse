#include<iostream>
#include<stdarg.h>
using namespace std;

#define MAX_ARRAY_DIM 8//����ά�����ֵ
typedef int ElemType;
typedef struct _ARRAY_
{
	ElemType *Base;//����Ԫ�ػ�ַ
	int dim;//ά��
	int *pBounds;//ά�߽�
	int *Contants;//����ӳ��������
}Array, *pArray;

bool InitArray(pArray A, int Dim, ...) {
	if (Dim<1 || Dim>MAX_ARRAY_DIM) return false;
	A->dim = Dim;
	int i = 0;

	A->pBounds = (int*)malloc(sizeof(int)*Dim);//Ϊά�߽������ڴ�
	if (A->pBounds == NULL) return false;//OVERFLOW

	va_list temp = { 0 };//stdarg.h�����ͣ�ֵ��ʵ��
	va_start(temp, Dim);

	int elemTotal = 1;//Ԫ�ص��ܸ���
	for (i = 0; i < Dim; i++) {
		A->pBounds[i] = va_arg(temp, int);//��ά�߽縳ֵ
		if (A->pBounds[i] < 0) {
			free(A->pBounds);
			return false;
		}
		elemTotal *= A->pBounds[i];
	}
	va_end(temp);
	A->Base = (ElemType *)malloc(sizeof(ElemType)*elemTotal);//Ϊÿһ��Ԫ�������ڴ�
	if (A->Base == NULL) {
		free(A->pBounds);
		return false;
	}

	A->Contants = (int *)malloc(sizeof(int) * Dim);//Ϊӳ�亯������ֵ�����ڴ�
	if (A->Contants == NULL) {
		free(A->pBounds);
		free(A->Base);
		return false;
	}
	A->Contants[Dim - 1] = 1;
	for (i = Dim - 2; i >= 0; i--) {
		A->Contants[i] = A->Contants[i + 1] * A->pBounds[i + 1];//��ӳ�亯��������ֵ
	}
	return true;
}

bool DestroyArray(pArray pArrayTemp)
{
	if (pArrayTemp->Base != NULL) {
		free(pArrayTemp->Base);
		pArrayTemp->Base = NULL;
	}
	if (pArrayTemp->pBounds != NULL) {
		free(pArrayTemp->pBounds);
		pArrayTemp->pBounds = NULL;
	}
	if (pArrayTemp->Contants != NULL) {
		free(pArrayTemp->Contants);
		pArrayTemp->Contants = NULL;
	}
	return true;
}

bool Locate(pArray pArrayTemp, va_list temp, int *offset)
{
	int iTemp = 0;
	int i = 0;
	*offset = 0;//��ƫ������ʼ��Ϊ0
	for (i = 0; i < pArrayTemp->dim; i++) {
		iTemp = va_arg(temp, int);
		*offset += iTemp*(pArrayTemp->Contants[i]);
	}
	return true;
}

bool Assign(pArray pArrayTemp, ElemType e, ...)
{
	va_list temp = { 0 };
	int offset = 0;
	va_start(temp, e);
	bool result = Locate(pArrayTemp, temp, &offset);
	*(pArrayTemp->Base + offset) = e;
	va_end(temp);
	return result;
}

bool Value(pArray pArrayTemp, ElemType *e, ...)
{
	va_list temp;
	va_start(temp, e);
	bool result = false;
	int offset;
	result = Locate(pArrayTemp, temp, &offset);
	*e = pArrayTemp->Base[offset];
	va_end(temp);
	return result;
}

int main()
{
	Array a;
	InitArray(&a, 3, 3, 3, 3);
	Assign(&a, 5, 2, 2, 2);//ֻ����λ���ϸ���ֵ
	int value;
	Value(&a, &value, 2, 2, 2);
	cout << value << endl;
	DestroyArray(&a);
	return 0;
}