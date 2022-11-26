#pragma once
#include<iostream>
using namespace std;
class Complex
{
	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator>>(istream&, Complex&);
public:
	explicit Complex(double =0.0, double =0.0);
	Complex operator+(const Complex&)const;//���ؼӺ������
	Complex operator-(const Complex&)const;//���ؼ��������
	Complex operator*(const Complex&)const;//���س˺������
	bool operator==(const Complex&)const;//������������
	bool operator!=(const Complex&)const;//���ز��������

private:
	double realPart;//ʵ��
	double imaginaryPart;//�鲿
};