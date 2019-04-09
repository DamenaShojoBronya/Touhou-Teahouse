#include <iostream>
using namespace std;

class seqlist {
private:
	int *date;
	int max;
	int len;
public:
	seqlist(int a) {
		if (a > 0) {
			max = a;
			date = new int[max];
			len = 0;
			for (int i = 0; i < max; ++i) {
				date[i] = 0;
			}
		}
		else {
			max = 0;
			date = nullptr;
			len = 0;
			for (int i = 0; i < max; ++i) {
				date[i] = 0;
			}
		}
	}

	~seqlist() {
		delete[]date;
	}

	int length() {
		return len;
	}

	int find(int x) //按序号查找
	{
		if (x > len || x < 1)
			return -1;
		else {
			return date[x - 1];
		}
	}

	int length() const {
		return len;
	}

	int findx(int x)       //按值查找
	{
		for (int i = 0; i < len; ++i) {
			if (date[i] == x)
				return i;
		}
		return -1;
	}

	int insert(int x, int i)  //插入 x值i位置
	{
		if (i < 0 || len == max) {
			return -1;
		}
		else {
			len++;

			for (int j = i + 1; j < len; ++j) {
				date[j] = date[j + 1];
			}
			date[i] = x;
		}
	}

	int Dlete(int x) {
		int i = findx(x);
		if (i == -1) {
			cout << x << "is not in the list." << endl;
			return -1;
		}
		else {
			len--;
			for (int j = i; j < len; ++j) {
				date[j] = date[j + 1];
			}
			return 1;
		}
	}

	int get(int i) {
		if (i < 0 || i > len) {
			return -1;
		}
		else {
			return date[i - 1];
		}
	}

	void output() {
		for (int i = 0; i < len; ++i) {
			cout << date[i] << " ";
		}
	}

	void average() {
		int sum = 0;
		cout << len << endl;
		for (int i = 0; i < len - 1; i++) {
			sum += date[i];
		}

		int ave = sum / len;
		if (len % 2 == 0) {
			for (int i = len; i > len / 2; --i) {
				date[i] = date[i - 1];
			}
			date[len / 2] = ave;
		}
		else {
			for (int i = len; i < (len - 1) / 2; ++i) {
				date[i] = date[i - 1];
			}
			date[(len - 1) / 2] = ave;
		}
	};
};

int main()
{
	seqlist l(10);
	cout << l.length() << endl;
	l.insert(1, 1);
	l.insert(1, 2);
	l.insert(1, 3);
	l.insert(1, 4);
	l.insert(1, 5);
	l.insert(1, 6);
	cout << l.length();
	l.output();
	cout << "the element 5'location is: " << l.findx(5) << endl;
	cout << "the second number is: " << l.find(2) << endl;
	l.Dlete(6);
	cout << "After deleting element 6, the elements of this seqlist are: ";
	cout << l.length();
	for (int i = 0; i < l.length(); i++) {
		cout << l.get(i) << " ";
	}
	cout << endl;
	l.average();
	cout << "After the average is inserted, the elements of the seqlist are: ";
	for (int i = 0; i < l.length(); i++) {
		cout << l.get(i) << " ";
	}
	return 0;
}



