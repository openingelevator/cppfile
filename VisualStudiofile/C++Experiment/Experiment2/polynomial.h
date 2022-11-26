#pragma once
#include<iostream>
using namespace std;
class Polynomial
{
	friend std::istream& operator>>(std::istream&, Polynomial&);
	friend std::ostream& operator<<(std::ostream&, const Polynomial&);
public:
	explicit Polynomial(int=10);
	Polynomial(const Polynomial&);
	~Polynomial();
	void set(int, int);
	int get(int)const;
	Polynomial operator+(const Polynomial&)const;
	Polynomial operator-(const Polynomial&)const;
	Polynomial& operator=(Polynomial&);
	Polynomial operator*(const Polynomial&)const;
	Polynomial& operator+=(const Polynomial&);
	Polynomial& operator-=(const Polynomial&);
	Polynomial& operator*=(const Polynomial&);

private:
	int size;//数组尺寸
	int* coefficence;//系数数组
};