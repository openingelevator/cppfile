#pragma once
#include<iostream>
using namespace std;
class Complex
{
	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator>>(istream&, Complex&);
public:
	explicit Complex(double =0.0, double =0.0);
	Complex operator+(const Complex&)const;//重载加号运算符
	Complex operator-(const Complex&)const;//重载减号运算符
	Complex operator*(const Complex&)const;//重载乘号运算符
	bool operator==(const Complex&)const;//重载相等运算符
	bool operator!=(const Complex&)const;//重载不等运算符

private:
	double realPart;//实部
	double imaginaryPart;//虚部
};