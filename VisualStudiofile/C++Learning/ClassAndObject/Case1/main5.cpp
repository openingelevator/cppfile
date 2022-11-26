#include<iostream>
#include"Polynomial.h"
using namespace std;
int main()
{
	Polynomial p1(2);
	cin >> p1;
	Polynomial p2(2);
	cin >> p2;
	
	cout << p1*p2;
	return 0;

}