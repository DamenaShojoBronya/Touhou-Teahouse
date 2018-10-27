/* 1003 ��Ҫͨ���� ��20 �֣�
  ������ȷ�����Զ�����ϵͳ�����������˻�ϲ�Ļظ����������� PAT �ġ�����ȷ�������� ���� ֻҪ������ַ�����������������ϵͳ�����������ȷ��������������𰸴��󡱡�
   �õ�������ȷ���������ǣ�
   �ַ����б������ P�� A�� T�������ַ��������԰��������ַ���
   �������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
   ��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a�� b�� c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
   ���ھ�����Ϊ PAT дһ���Զ����г����ж���Щ�ַ����ǿ��Ի�á�����ȷ���ġ�

   �����ʽ��
   ÿ������������� 1 �������������� 1 �и���һ�������� n (<10)������Ҫ�����ַ���������������ÿ���ַ���ռһ�У��ַ������Ȳ����� 100���Ҳ������ո�

   �����ʽ��
   ÿ���ַ����ļ����ռһ�У�������ַ������Ի�á�����ȷ��������� YES��������� NO��

   ����������
   8
   PAT
   PAAT
   AAPATAA
   AAPAATAAAA
   xPATx
   PT
   Whatever
   APAAATAA

   ���������
   YES
   YES
   YES
   YES
   NO
   NO
   NO
   NO */

#include<string>
#include<iostream>
using namespace std;

string pat(string str) {
	int a = 0, b = 0, c = 0;

	for (int i = 0; i<str.length(); i++) {
		if (str.at(i) != 'P'&&str.at(i) != 'A'&&str.at(i) != 'T') return "NO";
		if (str.at(i) == 'P') a = i;
		if (str.at(i) == 'T') b = i;
		if (i == str.length() - 1) c = i;
	}
	c = c - b; b = b - a - 1;
	if (c != a + (b - 1)*a || b == 0) return "NO";
	else return"YES";
}

int main()
{
	int n; cin >> n;
	string *str = new string[n];
	string *ans = new string[n];

	for (int i = 0; i < n; i++) {
		cin >> str[i]; ans[i] = pat(str[i]);
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << endl;
	}

	return 0;
}



