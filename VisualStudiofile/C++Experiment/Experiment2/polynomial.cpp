#include"polynomial.h"
void Polynomial::set(int coef, int exp)
{
	this->coefficence[exp] = coef;
}
int Polynomial::get(int exp)const
{
	return this->coefficence[exp];
}
Polynomial::Polynomial(int asize):size(asize),coefficence(new int[size])
{
	for (int i = 0; i < size; i++)
	{
		this->coefficence[i] = 0;
	}

}
Polynomial::Polynomial(const Polynomial& p):size(p.size),coefficence(new int[size])
{
	for (int i = 0; i < p.size; i++)
	{
		this->coefficence[i]=p.coefficence[i];
	}
}
Polynomial::~Polynomial()
{

	if (this->coefficence != NULL)
	{
	
		delete[] this->coefficence;
		this->coefficence = NULL;
	}
}
istream& operator>>(istream& input, Polynomial& p)
{
	for (int i = 0; i < p.size; i++)
	{
		input >> p.coefficence[i];
	}
	return input;
}
ostream& operator<<(std::ostream& output, const Polynomial& p)
{
	for (int i = p.size-1; i>=0; i--)
	{
		cout << p.coefficence[i] << "x" << "exp(" << i << ")" << " ";
	}
	return output;
}
Polynomial Polynomial::operator+(const Polynomial& p)const
{
	int bigsize = (this->size > p.size) ? this->size: p.size;
	int smallsize= (this->size < p.size) ? this->size : p.size;
	Polynomial temp(bigsize);
	for (int i = 0; i < bigsize; i++)
	{
		if (i < smallsize)
		{
			temp.coefficence[i] = this->coefficence[i] + p.coefficence[i];
		}
		else
		{
			if (this->size == bigsize) {
				temp.coefficence[i] = this->coefficence[i];
			}
			else
			{
				temp.coefficence[i] = p.coefficence[i];
			}
		}
	}
	return temp;
}
Polynomial Polynomial::operator-(const Polynomial& p)const
{
	int bigsize = (this->size > p.size) ? this->size : p.size;
	int smallsize = (this->size < p.size) ? this->size : p.size;
	Polynomial temp(bigsize);
	for (int i = 0; i < bigsize; i++)
	{
		if (i < smallsize)
		{
			temp.coefficence[i] = this->coefficence[i] - p.coefficence[i];
		}
		else
		{
			if (this->size == bigsize) {
				temp.coefficence[i] = this->coefficence[i];
			}
			else
			{
				temp.coefficence[i] = -p.coefficence[i];
			}
		}
	}
	return temp;
	
}
Polynomial& Polynomial::operator=(Polynomial& p)
{
	for (int i = 0; i < p.size; i++)
	{
		 this->coefficence[i]=p.coefficence[i];
	}
	return *this;
}
Polynomial Polynomial::operator*(const Polynomial& p)const
{
	int newspace = p.size + this->size-1;
	Polynomial temp(newspace);
	for (int i = 0; i <this->size; i++)
	{
		for (int j = 0; j < p.size; j++)
		{
			temp.coefficence[i + j] += this->coefficence[i] * p.coefficence[j];
		}
	}
	return temp;
}
Polynomial& Polynomial::operator+=(const Polynomial&p)
{
	int bigsize = (this->size > p.size) ? this->size : p.size;
	int smallsize = (this->size < p.size) ? this->size : p.size;
	Polynomial temp(bigsize);
	for (int i = 0; i < bigsize; i++)
	{
		if (i < smallsize)
		{
			this->coefficence[i] = this->coefficence[i] + p.coefficence[i];
		}
		else
		{
			if(bigsize==p.size)
			{
				temp.coefficence[i] =p.coefficence[i];
			}
		}
	}
	return *this;
}
Polynomial& Polynomial::operator-=(const Polynomial& p)
{
	int bigsize = (this->size > p.size) ? this->size : p.size;
	int smallsize = (this->size < p.size) ? this->size : p.size;
	Polynomial temp(bigsize);
	for (int i = 0; i < bigsize; i++)
	{
		if (i < smallsize)
		{
			this->coefficence[i] = this->coefficence[i] - p.coefficence[i];
		}
		else
		{
			if (bigsize == p.size)
			{
				temp.coefficence[i] = -p.coefficence[i];
			}
		}
	}
	return *this;
}
Polynomial& Polynomial::operator*=(const Polynomial& p)
{
	int newspace = p.size + this->size - 1;
	Polynomial temp(newspace);
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < p.size; j++)
		{
			temp.coefficence[i + j] += this->coefficence[i] * p.coefficence[j];
		}
	}
	delete[] this->coefficence;
	this->coefficence = new int[newspace];
	this->size = newspace;
	for (int i = 0; i < newspace; i++)
	{
		this->coefficence[i] = temp.coefficence[i];
	}
	return *this;
}
