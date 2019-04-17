/*  (Merge two sorted)Write the following function that merges two sorted lists into a new sorted list:
	void merge(const int list1[],int size1,const list2[],int size2,int list3[])
	Write a test program that prompts the user to enter two sorted lists and display the merged list.Here is a sample run.
	Note that the first number in the input indicates the number of the elements in the list.This number is not partof the list.Assume the maximum list size si 80.

	Enter list1: 5 1 5 16 61 111
	Enter list2: 4 2 4 5 6
	The merged list: 1 2 4 5 5 6 16 61 111  */

#include<string>
#include<iostream>
using namespace std;

void merge(const int list1[], int size1, const int list2[], int size2, int list3[]) {
	for (int i = 0; i < size1; i++) {
		list3[i] = list1[i];
	}
	for (int i = 0; i < size2; i++) {
		list3[i+size1] = list2[i];
	}

	for (int i = 0; i < size1+size2-1; i++)
		for (int j = 0; j < size1+size2-1-i; j++)
			if (list3[j] > list3[j+1]) swap(list3[j],list3[j+1]);

	for (int i = 0; i < size1+size2; i++) {
		cout << list3[i]<<" ";
	}
}

int main()
{
	int size1, size2, size3;

	cout << "Enter list1: ";
	cin >> size1; int *list1 = new int[size1];
	for (int i = 0; i < size1; i++) {
		cin >> list1[i];
	}
	cout << "Enter list2: ";
	cin >> size2; int *list2 = new int[size2];
	for (int i = 0; i < size2; i++) {
		cin >> list2[i];
	}

	int *list3 = new int[size1 + size2];
	merge(list1, size1, list2, size2, list3);
	
	return 0;
}






