#pragma once
#include<iostream>
using namespace std;
class Integer
{
	//������������
	friend ostream& operator<<(ostream& out, const Integer& i1);
	//�������������
	friend istream& operator>>(istream& in, Integer& i1);
public:
	Integer(int a=0):num(a){}
	//���ظ�ֵ�����
	Integer& operator=(const Integer& i1);
	Integer& operator+=(const Integer& i1);
	Integer& operator-=(const Integer& i1);
	Integer& operator*=(const Integer& i1);

	//���ؼӼ��˳������
	Integer operator+(const Integer& i1)const;
	Integer operator-(const Integer& i1)const;
	Integer operator*(const Integer& i1)const;
	Integer operator/(const Integer& i1)const;


	//���ع�ϵ�����
	bool operator==(const Integer& i1)const;
	bool operator!=(const Integer& i1)const;
	bool operator>=(const Integer& i1)const;
	bool operator<=(const Integer& i1)const;

	//����ǰ������õ��������
	Integer& operator++();
	Integer operator++(int);

	//���غ������������
	int operator()(int num1)const;
private:
	int num;
};