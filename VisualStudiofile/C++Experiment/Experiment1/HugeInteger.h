#pragma once
#include<iostream>
#include<string>
using namespace std;
class HugeInteger
{
public:
	void input(int a[40])
	{
		for (int i = 0; i < 40; i++)
		{
			hugeNumber[i] = a[i];
		}
	}
	void output()
	{
		for (int i = 0; i < 40; i++)
		{
			cout << hugeNumber[i];
		}
		cout << endl;
	}
	HugeInteger add(const HugeInteger& h)
	{
		HugeInteger temp;
		int m = 0;
		for (int i = 39; i >= 0; i--)
		{
			temp.hugeNumber[i] = (hugeNumber[i] + h.hugeNumber[i] + m) % 10;
			if (hugeNumber[i] + h.hugeNumber[i] >= 10)
			{
				m = 1;
			}
			else {
				m = 0;
			}
		}
		if (m == 1)
			cout << "EOF算术溢出" << endl;
		return temp;

	}
	HugeInteger subtract(const HugeInteger &h)
	{
		if (this->isLessThan(h))
		{
			cout << "EOF，输出结果为负数已经溢出" << endl;
		}
		else
		{
			HugeInteger temp;
			int m = 0;
			for (int i = 39; i >= 0; i--)
			{
				temp.hugeNumber[i] = (hugeNumber[i] - h.hugeNumber[i] - m + 10) % 10;
				if (hugeNumber[i] - h.hugeNumber[i] < 0)
				{
					m = 1;
				}
				else {
					m = 0;
				}
			}
			return temp;
		}

	}
	bool isEqualTo(const HugeInteger& h)
	{
		bool flag = 1;
		for (int i = 0; i < 40; i++)
		{
			if (hugeNumber[i] != h.hugeNumber[i])
				flag = 0;
		}
		return flag;
	}
	bool isNotEqualTo(const HugeInteger& h)
	{
		return !isEqualTo(h);
	}
	bool isGreaterThan(const HugeInteger& h)
	{
		for (int i = 0; i < 40; i++)
		{
			if (hugeNumber[i] > h.hugeNumber[i])
			{
				return true;
			}
			else if (hugeNumber[i] == h.hugeNumber[i])
			{
				continue;
			}
			else {
				return false;
			}
		}
	}
	bool isLessThan(const HugeInteger& h)
	{
		return !isGreaterThan(h);
	}
	bool isGreatThanOrEqualTo(const HugeInteger& h)
	{
		if (isGreaterThan(h) || isEqualTo(h))
		{
			return true;
		}
		else
			return false;
	}
	bool isLessThanOrEqualTo(const HugeInteger& h)
	{
		if (isLessThan(h) || isEqualTo(h))
		{
			return true;
		}
		else
			return false;
	}
	bool isZero()
	{
		bool flag = 1;
		for (int i = 0; i < 40; i++)
		{
			if (hugeNumber[i] != 0)
			{
				flag = 0;
			}
		}
		return flag;
	}
private:
	int hugeNumber[40] = { 0 };
};