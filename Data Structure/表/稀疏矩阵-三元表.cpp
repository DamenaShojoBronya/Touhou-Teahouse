#include <iostream>
using namespace std;

#define MaxSize 100

typedef int ElemType;
typedef struct
{
	int row;
	int col;
	ElemType data;

} TupNode; //原矩阵中的值和位置

typedef struct
{
	int rows;
	int cols;
	int nums;//非零元素个数
	TupNode Data[MaxSize];//三元表的值即原矩阵的值和位置

} TSMatrix;

void CreatMat(TSMatrix *t, int arr[3][4]) {
	int i, j;
	t->rows = 3;
	t->cols = 4;
	t->nums = 0;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			if (arr[i][j] != 0) {
				t->Data[t->nums].row = i;
				t->Data[t->nums].col = j;
				t->Data[t->nums].data = arr[i][j];
				t->nums++;
			}
		}
	}
}

void Assign(TSMatrix t, int *data, int i, int j) {
	int k = 0;
	if (i >= t.rows || j >= t.cols) exit(0);

	while (k < t.nums && i > t.Data[k].row) {
		k++;
	}

	while (k < t.nums && i == t.Data[k].row && j > t.Data[k].col) {
		k++;
	}
	if (t.Data[k].row == i && t.Data[k].col) {
		*data = t.Data[k].data;
	}
	else *data = 0;
}

void Value(TSMatrix *t, int data, int i, int j)
{
	int k = 0, k1 = 0;
	if (i >= t->rows || j >= t->cols) {
		return;
	}
	while (k < t->nums && i > t->Data[k].row) {
		k++;
	}
	while (k < t->nums && i == t->Data[k].row && j > t->Data[k].col) {
		k++;
	}

	if (i == t->Data[k].row && j == t->Data[k].col) {
		t->Data[k].data = data;
	}
	else {//插入数据
		for (k1 = t->nums; k1 >= k; k1--) {
			t->Data[k1 + 1].col = t->Data[k1].col;
			t->Data[k1 + 1].row = t->Data[k1].row;
			t->Data[k1 + 1].data = t->Data[k1].data;
		}
		t->Data[k].row = i;
		t->Data[k].col = j;
		t->Data[k].data = data;
		t->nums++;
	}
}

void DispMat_t(TSMatrix *t) {
	if (t->nums <= 0) exit(0);
	cout << "rows cols nums" << endl;
	cout << t->rows << " " << t->cols << " " << t->nums << endl;
	for (int i = 0; i < t->nums; i++) {
		cout << "Data: rows cols nums" << endl;
		cout << t->Data[i].row << " " << t->Data[i].col << " " << t->Data[i].data << endl;
	}
}

int main(void)
{
	int arr[3][4] = {
		{ 0 , 1 , 0 , 0 },
		{ 0 , 0 , 0 , 2 },
		{ 3 , 0 , 0 , 4 }
	};

	int data = 0;
	TSMatrix t = { 0 };
	CreatMat(&t, arr);

	DispMat_t(&t);
	cout << "--------------------------" << endl;

	Assign(t, &data, 0, 1);

	Value(&t, data, 0, 0);

	DispMat_t(&t);

	return 0;
}