#include<iostream>
#include"Polynomial.h"
using namespace std;
void Polynomial::set(int coef,int exp)
{
	coeff[exp] = coef;
}
int Polynomial::get(int exp)const
{
	return coeff[exp];
}
Polynomial::Polynomial(int asize)
{
	size = asize;
	for (int i = 0; i < psize; i++)
	{
		coeff.push_back(0);
	}
}

istream& operator>>(istream& input, Polynomial &p)
{
	for (size_t i = 0; i < p.size; i++)
	{
		input >> p.coeff[i];
	}
	return input;
}
ostream& operator<<(std::ostream& output, const Polynomial& p)
{
	int j = psize - 1;
	while (p.coeff[j] == 0)j--;
	for (size_t i = 0; i <psize; i++)
	{
		if (i > j)break;
		cout <<p.coeff[i] <<"x"<<"exp("<<i<<")" << " ";
	}
	return output;
}
Polynomial Polynomial::operator+(const Polynomial&p)const
{
	Polynomial temp(psize);
	for (int i = 0; i < psize; i++)
	{
		temp.coeff[i] = this->coeff[i] + p.coeff[i];
	}
	temp.size = (p.size > this->size ? p.size : this->size);
	return temp;
}
Polynomial Polynomial::operator-(const Polynomial& p)const
{
	Polynomial temp(psize);
	for (int i = 0; i < psize; i++)
	{
		temp.coeff[i] = this->coeff[i] - p.coeff[i];
	}
	temp.size=(p.size > this->size ? p.size : this->size);
	return temp;
}
Polynomial& Polynomial::operator=(Polynomial& p)
{
	this->size = p.size;
	for (int i = 0; i < psize; i++)
	{
		this->coeff[i]=p.coeff[i];
	}
	return *this;
}
Polynomial Polynomial::operator*(const Polynomial&p)const
{
	Polynomial temp(psize);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < p.size; j++)
		{
			temp.coeff[i+j] += p.coeff[j] * this->coeff[i];
		}
	}
	temp.size = this->size+p.size-1;
	return temp;
}
Polynomial& Polynomial::operator+=(const Polynomial&p)
{
	for (int i = 0; i < psize; i++)
	{
		this->coeff[i] = this->coeff[i] + p.coeff[i];
	}
	return*this;
}
Polynomial& Polynomial::operator-=(const Polynomial&p)
{
	for (int i = 0; i < psize; i++)
	{
		this->coeff[i] = this->coeff[i] - p.coeff[i];
	}
	return*this;
}
Polynomial& Polynomial::operator*=(const Polynomial& p)
{
	Polynomial temp(psize);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < p.size; j++)
		{
			temp.coeff[i + j] += p.coeff[j] * this->coeff[i];
		}
	}
	for (int i = 0; i < psize; i++)
	{
		this->coeff[i] = temp.coeff[i];
	}
	
	return *this;
}