#include<iostream>
#include"polynomial.h"
using namespace std;
int main()
{
	Polynomial p1(2);
	cin >> p1;
	Polynomial p2(2);
	cin >> p2;
	p1 *= p2;
	cout << p1;
	return 0;
}