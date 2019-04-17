#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int Status;
typedef int listdata;
typedef struct {
	listdata *data;
	int length;
	int listsize;
}list;

void Print(list &L) {
	if (&L == NULL) exit(OVERFLOW);
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << " ";
	}
	cout << endl;
}

Status Init(list *l, int num) {		//初始化
	(*l).data = (listdata*)malloc(num * sizeof(listdata));	//初次分配空间量 num=长度
	if ((*l).data == NULL) {
		exit(OVERFLOW);
	}
	(*l).length = 0;
	(*l).listsize = num;
	return 1;
}

int Insert(list & L, listdata a, int pos) {      //a为要插入的数据，pos为位置
	if (pos < 1 || pos > L.length) return 0;
	int *q = &(L.data[pos]);					//q指向pos的位置
	for (int *p = &(L.data[L.length - 1]); p >= q; p--) {	//p指向data的最后一位
		*(p + 1) = *p;
	}
	*q = a; L.length++;
	return 1;
}

int Find1(list &L, listdata x) {				//按值查找
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == x) return i;			//返回位置
	}
	return -1;
}

int Find2(list &L, listdata n) {				//按序号查找
	if (n < L.length) return L.data[n];
	return -1;
}

int Delete(list &L, listdata x)
{
	int pos = Find1(L, x);
	if (pos >= 0) {
		L.length--;
		for (int i = pos; i < L.length; i++) {
			L.data[i] = L.data[i + 1];
		}
		return 1;
	}
	return 0;
}

void Insert_aver(list &L)
{
	listdata ave = 0;
	if (L.data == NULL) exit(1);
	for (int i = 0; i < L.length; i++) {
		ave += L.data[i];
	}
	ave /= L.length;
	if (L.length % 2) {							//奇数
		int b = (L.length + 1) / 2;
		Insert(L, ave, b);
	}
	else {										//偶数
		int b = L.length / 2;
		Insert(L, ave, b);
	}
}

int main()
{
	list L;
	int num = 20; Init(&L, num);				//分配内存空间大小为num
	L.length = 9;								//顺序表使用的length
	for (int i = 0; i < L.length; i++) {
		L.data[i] = i;
	}
	//---------------插入测试----------------------------------
	Print(L); cout << endl;
	Insert(L, 666, 5);
	Print(L); cout << endl;
	//---------------查找测试(按值)----------------------------
	num = 6;
	int re = Find1(L, num);
	if (re == -1) cout << "没找着" << endl;
	else cout << num << "在" << re << "(from 0)" << endl;
	//---------------查找测试(按序号)--------------------------
	num = 6;
	re = Find2(L, num);
	if (re == -1) cout << "没找着" << endl;
	else cout << num << "是" << re << "(from 0)" << endl;
	//----------------删除测试(按值)---------------------------
	int x = 666;
	if (Delete(L, x) == 0) cout << "没找着儿" << endl;
	Print(L);
	//----------------求平均值并插入测试-----------------------
	Insert_aver(L);
	Print(L);

	return 0;
}

