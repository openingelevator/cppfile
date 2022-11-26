#pragma once
#include<iostream>
using namespace std;
class RationalNumber
{
public:
	RationalNumber(int, int);
	RationalNumber operator+(const RationalNumber&)const;
	RationalNumber operator-(const RationalNumber&)const;
	RationalNumber operator*(const RationalNumber&)const;
	RationalNumber operator/(const RationalNumber&)const;
	bool operator==(const RationalNumber&)const;
	bool operator!=(const RationalNumber&)const;
	bool operator>=(const RationalNumber&)const;
	bool operator<=(const RationalNumber&)const;
	void print()const;
private:
	int m_dividend;
	int m_divisor;
};