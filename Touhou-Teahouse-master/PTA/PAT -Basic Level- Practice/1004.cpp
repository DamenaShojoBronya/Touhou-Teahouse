/* 1004 �ɼ����� ��20 �֣�
���� n��>0����ѧ����������ѧ�š��ɼ����ֱ�����ɼ���ߺͳɼ����ѧ����������ѧ�š�

�����ʽ��
ÿ������������� 1 ��������������ʽΪ

�� 1 �У������� n
�� 2 �У��� 1 ��ѧ�������� ѧ�� �ɼ�
�� 3 �У��� 2 ��ѧ�������� ѧ�� �ɼ�
  ... ... ...
�� n+1 �У��� n ��ѧ�������� ѧ�� �ɼ�
����������ѧ�ž�Ϊ������ 10 ���ַ����ַ������ɼ�Ϊ 0 �� 100 ֮���һ�����������ﱣ֤��һ�����������û������ѧ���ĳɼ�����ͬ�ġ�

�����ʽ��
��ÿ������������� 2 �У��� 1 ���ǳɼ����ѧ����������ѧ�ţ��� 2 ���ǳɼ����ѧ����������ѧ�ţ��ַ������� 1 �ո�

����������
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
���������
Mike CS991301
Joe Math990112 */

#include<string>
#include<iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	string *name = new string[n];
	string *id = new string[n];
	int *score = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> name[i] >> id[i] >> score[i];
	}
	for (int i = 0; i<n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (score[j] < score[j + 1]) {
				swap(name[j], name[j + 1]);
				swap(score[j], score[j + 1]);
				swap(id[j], id[j + 1]);
			}

	cout << name[0] << " " << id[0] << endl;
	cout << name[n - 1] << " " << id[n - 1];

	return 0;
}


