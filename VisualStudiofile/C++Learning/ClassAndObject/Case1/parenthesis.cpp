#include<iostream>
#include"parenthesis.h"
using namespace std;
parenthesis::parenthesis(const int& row, const int& col):m_row(row>0?row:0),m_column(col>0?col:0)
{
	size = row * col;
	array = new int[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = 0;
	}
}
parenthesis::~parenthesis()
{
	if (this->array != NULL)
	{
		delete[]this->array;
		this->array = NULL;
	}
}

ostream& operator<<(ostream&out, const parenthesis&p)
{
	int i;
	for (i = 0; i < p.size; i++)
	{
		out <<setw(5) << p.array[i];
		if ((i + 1) % p.m_row == 0)out << endl;
	}
	if (i % p.m_row != 0)out << endl;
	return out;
}
istream& operator>>(istream&in, parenthesis&p)
{
	for (int i = 0; i < p.size; i++)
	{
		in >> p.array[i];
	}
	return in;
}
int&parenthesis::operator()(int row,int col)
{
	int index = (row - 1) * (col - 1);
	return this->array[index];
}
const int& parenthesis::operator()(int row, int col)const
{
	int index = (row - 1) * (col - 1);
	return this->array[index];
}
parenthesis& parenthesis::operator=(const parenthesis& p)
{
	for (int i = 0; i < p.size; i++)
	{
		this->array[i] = p.array[i];
	}
	return *this;
}
bool parenthesis::operator==(const parenthesis& p)const
{
	for (int i = 0; i < p.size; i++)
	{
		if (this->array[i] != p.array[i])return false;
	}
	return true;
}
bool parenthesis::operator!=(const parenthesis& p)const
{
	return !operator==(p);
}
