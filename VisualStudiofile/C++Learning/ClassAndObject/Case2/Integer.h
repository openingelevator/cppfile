#pragma once
#include<iostream>
using namespace std;
class Integer
{
	//重载输出运算符
	friend ostream& operator<<(ostream& out, const Integer& i1);
	//重载输入运算符
	friend istream& operator>>(istream& in, Integer& i1);
public:
	Integer(int a=0):num(a){}
	//重载赋值运算符
	Integer& operator=(const Integer& i1);
	Integer& operator+=(const Integer& i1);
	Integer& operator-=(const Integer& i1);
	Integer& operator*=(const Integer& i1);

	//重载加减乘除运算符
	Integer operator+(const Integer& i1)const;
	Integer operator-(const Integer& i1)const;
	Integer operator*(const Integer& i1)const;
	Integer operator/(const Integer& i1)const;


	//重载关系运算符
	bool operator==(const Integer& i1)const;
	bool operator!=(const Integer& i1)const;
	bool operator>=(const Integer& i1)const;
	bool operator<=(const Integer& i1)const;

	//重载前置与后置递增运算符
	Integer& operator++();
	Integer operator++(int);

	//重载函数调用运算符
	int operator()(int num1)const;
private:
	int num;
};