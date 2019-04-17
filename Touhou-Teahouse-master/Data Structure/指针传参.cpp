#include <iostream>
using namespace std;

void func(int x[], int n){
	int temp, i, j;
	int m = (n - 1) / 2;
	for (i = 0; i <= m; ++i){
		j = n - 1 - i;
		temp = x[i];
		x[i] = x[j];
		x[j] = temp;
	}


}
void func2(int*x, int n){
	int *p, *i, *j, m, temp;
	m = (n - 1) / 2;
	i = x;
	j = x + n - 1;
	p = x + m;
	for (; i <= p; ++i, j--){
		temp = *i;
		*i = *j;
		*j = temp;
	}
}

int main()                    //实参形参均用数组
{
	int list[10] = { 1,2,3,4,5,6,7,8,9,10 };
	func(list, 10);
	return 0;
}

int main()                 //实参用数组，形参用指针
{
	int list[10] = { 1,2,3,4,5,6,7,8,9,10 };
	func2(list, 10);
	return 0;

}

int main()                //实参形参均用指针
{
	int list[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int *p = list;
	p = list;
	func2(p, 10);

}

int main()                //实参用指针 形参用数组
{
	int list[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int *p = list;
	p = list;
	func(p, 10);
}