#include<iostream>
#include"Integer.h"
using namespace std;
ostream& operator<<(ostream& out, const Integer& i1)
{
	out << i1.num;
	return out;
}
istream& operator>>(istream& in, Integer& i1)
{
	in >> i1.num;
	return in;
}
Integer& Integer::operator=(const Integer& i1)
{
	this->num = i1.num;
	return *this;
}
Integer& Integer::operator+=(const Integer& i1)
{
	this->num += i1.num;
	return *this;
}
Integer& Integer::operator-=(const Integer& i1)
{
	this->num -= i1.num;
	return *this;
}
Integer& Integer::operator*=(const Integer& i1)
{
	this->num *= i1.num;
	return *this;
}
Integer Integer::operator+(const Integer& i1)const
{
	Integer temp;
	temp.num = this->num + i1.num;
	return temp;
}
Integer Integer::operator-(const Integer& i1)const
{
	Integer temp;
	temp.num = this->num -i1.num;
	return temp;
}
Integer Integer::operator*(const Integer& i1)const
{
	Integer temp;
	temp.num = this->num * i1.num;
	return temp;
}
Integer Integer::operator/(const Integer& i1)const
{
	Integer temp;
	if (i1.num != 0) {
		temp.num = this->num / i1.num;
	}
	return temp;
}
bool Integer::operator==(const Integer& i1)const
{
	if (this->num == i1.num)return true;
	else return false;

}
bool Integer::operator!=(const Integer& i1)const
{
	return !operator==(i1);
}
bool Integer::operator>=(const Integer& i1)const
{
	if (this->num >= i1.num)return true;
	else return false;
}
bool Integer::operator<=(const Integer& i1)const
{
	if (this->num <= i1.num)return true;
	else return false;
}
Integer& Integer::operator++()
{
	this->num++;
	return *this;
}
Integer  Integer::operator++(int)
{
	Integer temp=*this;
	this->num++;
	return temp;
}
int Integer::operator()(int num1)const
{
	return this->num + num1;
}