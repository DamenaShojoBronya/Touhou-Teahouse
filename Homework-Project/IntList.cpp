#include <iostream>
#include "IntList.h"
using namespace std;

IntList::IntList(int numVals, int val)
{
	if (numVals > 0) {
		numberValues = numVals;
		values = new int[numVals];
		for (int i = 0; i < numVals; ++i) {
			values[i] = val;
		}
	}
	else {
		values = NULL;
		numberValues = 0;
	}
}
//构造函数
IntList::IntList(const IntList &il)
{
	numberValues = il.size();
	if (numberValues > 0)
	{
		values = new int[numberValues];
		for (int i = 0; i < numberValues; ++i) {
			values[i] = il.values[i];
		}
	}
	else {
		values = NULL;
		numberValues = 0;
	}
}
//copy
IntList::~IntList()
{
	delete[] values;
	values = NULL;
	numberValues = 0;
}
//析构函数
IntList& IntList::operator=(const IntList &il)
{
	if (values == il.values)
	{
		return *this;
	}
	else
	{
		delete[] values;
		values = NULL;
		numberValues = 0;
		if (il.numberValues >= 0)
		{
			numberValues = il.numberValues;
			values = new int[numberValues];
			for (int i = 0; i < numberValues; ++i)
			{
				values[i] = il.values[i];
			}
		}
		return *this;
	}
}
//重载运算符
int IntList::size() const
{
	return numberValues;
}
//
//
//
void IntList::resize(int n, int val)
{
	if (n > 0)
	{
		if (values == NULL)
		{
			//numberValues = n;
			values = new int[n];
			for (int i = 0; i < n; ++i)
			{
				values[i] = val;
			}
			numberValues = n;
		}
		else
		{
			int *temp = new int[n];
			if (n >= numberValues)
			{
				for (int i = 0; i <numberValues; ++i)
				{
					temp[i] = values[i];
				}
				for (int j = numberValues; j < n; ++j)
				{
					temp[j] = val;
				}
				//numberValues = n;
			}
			else {
				for (int i = 0; i < n; ++i) {
					temp[i] = values[i];
				}
			}
			delete[] values;
			numberValues = n;
			values = new int[numberValues];
			for (int j = 0; j < numberValues; ++j) {
				values[j] = temp[j];
			}
			delete[] temp;

		}
	}
	else if (n == 0) {
		numberValues = 0;
		values = NULL;
	}
}
void IntList::push_back(int val) {
	resize(numberValues + 1, val);
	//values[numberValues] = val;
}
