#include<iostream>
#include"RationalNumber.h"
using namespace std;
int gcd(int num1,int num2)
{
	int large, small;
	if (num1 == num2)return num1;
	while (num1 != num2)
	{
		if (num1 > num2)
		{
			large = num1;
			small = num2;
		}
		else if (num1 < num2) {
			large = num2;
			small = num1;
		}
		num1 = large - small;
		num2 = small;
	}
	return num2;
}
RationalNumber::RationalNumber(int dividend, int divisor)
{
	if (divisor == 0 || divisor < 0)
	{
		m_dividend = 0;
		m_divisor = 1;
	}
	else
	{
		m_dividend = dividend / gcd(dividend, divisor);
		m_divisor = divisor / gcd(dividend, divisor);
	}
	cout << m_dividend << "/" << m_divisor << endl;
}
RationalNumber RationalNumber::operator+(const RationalNumber& r)const
{
	int divis = r.m_divisor *this->m_divisor;
	int divid = r.m_dividend * this->m_divisor + r.m_divisor * this->m_dividend;
	RationalNumber temp(divid, divis);
	return temp;
}
RationalNumber RationalNumber::operator-(const RationalNumber& r)const
{
	int divis = r.m_divisor * this->m_divisor;
	int divid = r.m_divisor * this->m_dividend- r.m_dividend * this->m_divisor;
	RationalNumber temp(divid, divis);
	return temp;
}
RationalNumber RationalNumber::operator*(const RationalNumber& r)const
{
	int divis = r.m_divisor * this->m_divisor;
	int divid = r.m_dividend * this->m_dividend;
	RationalNumber temp(divid, divis);
	return temp;
}
RationalNumber RationalNumber::operator/(const RationalNumber&r)const
{
	int divis = r.m_dividend * this->m_divisor;
	int divid = r.m_divisor * this->m_dividend;
	RationalNumber temp(divid, divis);
	return temp;
}
bool RationalNumber::operator==(const RationalNumber& r)const
{
	if (this->m_dividend * r.m_divisor == this->m_divisor * r.m_dividend)
		return true;
	else
		return false;
}
bool RationalNumber::operator!=(const RationalNumber& r)const
{
	if (!operator==(r))return true;
	else
		return false;
}
bool RationalNumber::operator>=(const RationalNumber& r)const
{
	if (this->m_dividend * r.m_divisor >= this->m_divisor * r.m_dividend)
		return true;
	else
		return false;
}
bool RationalNumber::operator<=(const RationalNumber& r)const
{
	if (this->m_dividend * r.m_divisor <= this->m_divisor * r.m_dividend)
		return true;
	else
		return false;
}
void RationalNumber::print()const
{
	cout << m_dividend << "/" << m_divisor << endl;
}