#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
class parenthesis
{
	friend ostream& operator<<(ostream&, const parenthesis&);
	friend istream& operator>>(istream&, parenthesis&);
public:
	parenthesis(const int&,const int&);
	~parenthesis();
	int& operator()(int, int);
	const int& operator()(int, int)const;
	parenthesis& operator=(const parenthesis&);
	bool operator==(const parenthesis&)const;
	bool operator!=(const parenthesis&)const;

private:
	int m_row;
	int m_column;
	int size;
	int* array;
};
