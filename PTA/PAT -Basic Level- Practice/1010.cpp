#include<stdio.h>
int main()
{
	int i, coefficient[100], index[100];
	for (i = 0; ; i++)
	{
		scanf_s("%d %d", &coefficient[i], &index[i]);
		char a;
		scanf_s("%c", &a);
		if (a == '\n') break;
	}
	for (int i1 = 0; i1 <= i; i1++)
	{
		if (coefficient[i1] > 1000 || coefficient[i1] < -1000) return 0;
		if (index[i1] > 1000 || index[i1] < -1000) return 0;

		if (index[i1] == 0 && coefficient[i1] == 0) printf("0 0");
		if (index[i1 + 1] != 0)
		{
			if (i1 != i && index[i1] != 0) printf("%d %d ", coefficient[i1] * index[i1], index[i1] - 1);
			if (i1 == i && index[i1] != 0) printf("%d %d", coefficient[i1] * index[i1], index[i1] - 1);
		}
		else
			if (coefficient[i1] != 0)  printf("%d %d", coefficient[i1] * index[i1], index[i1] - 1);
	}
	return 0;
}