#pragma once
#include<iostream>
#include<vector>
using namespace std;
const int psize = 10;
class Polynomial
{
	friend std::istream& operator>>(std::istream&, Polynomial&);
	friend std::ostream& operator<<(std::ostream&,const Polynomial&);
public:
	explicit Polynomial(int);
	void set(int,int);
	int get(int)const;
	Polynomial operator+(const Polynomial&)const;
	Polynomial operator-(const Polynomial&)const;
	Polynomial& operator=(Polynomial&);
	Polynomial operator*(const Polynomial&)const;
	Polynomial& operator+=(const Polynomial&);
	Polynomial& operator-=(const Polynomial&);
	Polynomial& operator*=(const Polynomial&);
private:
	vector<int>coeff;
	int size;

};