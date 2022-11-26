#include<iostream>
#include<cctype>
#include"HugeInt.h"
using namespace std;
HugeInt::HugeInt(long value)
{
	for (int i = 0; i < digits; i++)
	{
		integer[i] = 0;
	}
	for (int j = digits - 1; value != 0 && j >= 0; j--)
	{
		integer[j] = value % 10;
		value /= 10;
	}
}
HugeInt::HugeInt(const string& number)
{
	for (int i = 0; i < digits; i++)
	{
		integer[i] = 0;
	}
	int length = number.size();
	for (int j = digits - length, k = 0; j < digits; j++, k++)
	{
		if (isdigit(number[k]))integer[j] = number[k]-'0';
	}
}
HugeInt HugeInt::operator+(const HugeInt& op2)const
{

	HugeInt temp;
	int carry = 0;
	for (int i = digits - 1; i >= 0; i--)
	{
		temp.integer[i] = this->integer[i] + op2.integer[i] + carry;
		if (temp.integer[i] > 9)
		{
			temp.integer[i] %= 10;
			carry = 1;
		}
		else
			carry = 0;
	}
	return temp;

}
HugeInt HugeInt::operator+(int op2)const
{
	return *this + HugeInt(op2);
}
HugeInt HugeInt::operator+(const string& op2)const
{
	return *this + HugeInt(op2);
}

HugeInt HugeInt::operator*(const HugeInt& op2)const
{
	string s;
	int i1;
	for (i1 = 0; (i1 < digits) && (this->integer[i1] == 0); ++i1);
	int len1 = digits - i1;
	int j1;
	for (j1 = 0; (j1 < digits) && (op2.integer[j1] == 0); ++j1);
	int len2 = digits - j1;
	int num1[digits], num2[digits], numM[digits];
	fill(num1, num1 + digits, 0), fill(num2, num2 + digits, 0), fill(numM, numM +digits, 0);
	for (int i = digits-1; i >= 1; i--)num1[digits - i] = this->integer[i];
	for (int i = digits-1; i >= 1; i--)num2[digits - i] = op2.integer[i];
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			numM[i + j - 1] += num1[i] * num2[j];
		}
	}
	for (int i = len1+len2; i >= 0; i--)
	{
		numM[i + 1] += numM[i] / 10;
		numM[i] %= 10;
	}
	if (numM[len1+len2])s += numM[len1+len2] + '0';
	for (int i = len1 + len2 - 1; i >= 1; i--)
	{
		s += numM[i] + '0';
	}
	return HugeInt(s);
}
HugeInt HugeInt::operator*(int value)const
{
	return *this * HugeInt(value);
}
HugeInt HugeInt::operator*(const string&s)const
{
	return *this * HugeInt(s);
}
int sub(int* a, int* b, int len1, int len2)
{
	if (len1 < len2)return -1;
	if (len1 == len2)
	{
		for (int i = len1 - 1; i >= 0; i--)
			if (a[i] > b[i])break;
			else if (a[i] < b[i])return -1;
	}
	for (int i = 0; i < len1; i++)
	{
		a[i] -= b[i];
		if (a[i] < 0)
			a[i] += 10,
			a[i + 1]--;
	}
	for (int i = len1 - 1; i >= 0; i--)
		if (a[i])return i + 1;
	return 0;
}
HugeInt HugeInt::operator/(const HugeInt&op2)const
{
	string divisor;
	int i1;
	for (i1 = 0; (i1 < digits) && (this->integer[i1] == 0); ++i1);
	int len1 = digits - i1;
	int j1;
	for (j1 = 0; (j1 < digits) && (op2.integer[j1] == 0); ++j1);
	int len2 = digits - j1;
	int len3 = digits;
	int a[digits], b[digits], result[digits];
	fill(a, a + digits, 0); fill(b, b + digits, 0); fill(result, result + digits, 0);
	for (int i = digits- 1; i >= 0; i--)a[digits- 1 - i] = this->integer[i];
	for (int i = digits - 1; i >= 0; i--)b[digits - 1 - i] = op2.integer[i];
	if (len1 < len2 )
	{
		string s = "0";
		return s;
	}
	unsigned int t = len1 - len2;
	for (int i = len1 - 1; i >= 0; i--)
	{
		if (i >= t) {
			b[i] = b[i - t];
		}
		else b[i] = 0;
	}
	len2 = len1;
	for (unsigned int j = 0; j <= t; j++)
	{
		int temp;
		while ((temp = sub(a, b + j, len1, len2 - j)) >= 0)
		{
			len1 = temp;
			result[t - j]++;
		}
	}
	for (int i = 0; i < digits - 1; i++)
	{
		result[i + 1] += result[i] / 10, result[i] %= 10;

	}
	while (result[len3 - 1] == 0) {
		len3--;
	}
	for (int i = len3 - 1; i >= 0; i--)
	{
		divisor += result[i] + '0';
	}
	return HugeInt(divisor);
}
HugeInt HugeInt::operator/(int value)const
{
	return*this / HugeInt(value);
}
HugeInt HugeInt::operator/(const string& s)const
{
	return *this / HugeInt(s);
}
ostream& operator<<(ostream& out, const HugeInt& num)
{
	int i;
	for (i = 0; (i < HugeInt::digits) && (num.integer[i] == 0); ++i);
	if (i == HugeInt::digits)
	{
		out << 0;
	}
	else
	{
		for (; i < HugeInt::digits; i++)
			out << num.integer[i];
	}
	return out;
}