#include<iostream>
using namespace std;
#include"Complex.h"
Complex::Complex(double i, double j):realPart(i),imaginaryPart(j)//��ʼ���б�
{
}
ostream& operator<<(ostream& out, const Complex& c1)//��������ȡ�����
{
	out << "(" << c1.realPart << "," << c1.imaginaryPart << ")";
	return out;
}
istream& operator>>(istream& in,Complex& c1)//���������������
{
	in >> c1.realPart >> c1.imaginaryPart;
	return in;
}
Complex Complex:: operator+(const Complex&c1)const
{
	return Complex(this->realPart + c1.realPart, this->imaginaryPart + c1.imaginaryPart);
}
Complex Complex::operator-(const Complex&c1)const
{
	return Complex(this->realPart - c1.realPart, this->imaginaryPart - c1.imaginaryPart);
}
Complex Complex::operator*(const Complex&c1)const
{
	return Complex(this->realPart * c1.realPart- this->imaginaryPart*c1.imaginaryPart, 
		this->realPart * c1.imaginaryPart+this->imaginaryPart*c1.realPart);
}
bool Complex::operator==(const Complex&c1)const
{
	if (this->realPart == c1.realPart && this->imaginaryPart == c1.imaginaryPart)
		return true;
	else return false;
}
bool Complex::operator!=(const Complex&c1)const
{
	return !operator==(c1);
}