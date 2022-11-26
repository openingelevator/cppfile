#pragma once
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class HugeInt
{
	friend ostream& operator<<(ostream&, const HugeInt&);
public:
	static const int digits = 30;
	HugeInt(long = 0);
	HugeInt(const string&);

	HugeInt operator+(const HugeInt&)const;
	HugeInt operator+(int)const;
	HugeInt operator+(const string&)const;

	HugeInt operator*(const HugeInt&)const;
	HugeInt operator*(int)const;
	HugeInt operator*(const string&)const;

	HugeInt operator/(const HugeInt&)const;
	HugeInt operator/(int)const;
	HugeInt operator/(const string&)const;

private:
	short integer[digits];
};
