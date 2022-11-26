#pragma once
#include<vector>
#include<iostream>
using namespace std;
class IntegerSet
{
public:

	IntegerSet()
	{
		for (int i = 0; i < 100; i++)
		{
			integerSet.push_back(false);
		}
	}
	IntegerSet(int *a,int k)
	{
		for (int i = 0; i < 100; i++)
		{
			integerSet.push_back(false);
		}
		for (int i = 0; i <k; i++)
		{
			integerSet[a[i]] = true;
		}
	}
	void printSet()
	{
		bool flag = 0;
		for (int i = 0; i < 100; i++)
		{
			if (integerSet[i] == true)
			{
				flag = 1;
				cout << i << " ";
			}

		}
		if (flag == 0)
		{
			cout << "---" << endl;
		}

	}
	bool isEqualTo(const IntegerSet& set)
	{
		for (int i = 0; i < 100; i++)
		{
			if (set.integerSet[i] != this->integerSet[i])
				return false;
		}
		return true;
	}
	//并集运算
	IntegerSet unionOfSets(const IntegerSet &set1)
	{
		IntegerSet set2;
		for (int i = 0; i < 100; i++)
		{
			if (set1.integerSet[i] + integerSet[i] != 0)
			{
				set2.integerSet[i] = true;
			}
			else
			{
				set2.integerSet[i] = false;
			}
		}
		return set2;
	}
	//交集运算
	IntegerSet intersectionOfSets(const IntegerSet& set1)
	{
		IntegerSet set2;
		for (int i = 0; i < 100; i++)
		{
			if (set1.integerSet[i] * integerSet[i] != 0)
			{
				set2.integerSet[i] = true;
			}
			else
			{
				set2.integerSet[i] = false;
			}
		}
		return set2;
	}
	void insertElement(int k)
	{
		for (int i = 0; i < 100; i++)
		{
			if (i == k) {
				integerSet[i] = true;
			}
		}
	}
private:
	vector<bool>integerSet;
};