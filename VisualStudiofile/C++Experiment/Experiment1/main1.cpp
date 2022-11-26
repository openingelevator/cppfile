#include<iostream>
#include"Complex.h"
using namespace std;
int main()
{
	Complex c1;
	Complex c2;
	cin >> c1 >> c2;
	Complex c3 = c1 + c2;
	Complex c4 = c1 - c2;
	Complex c5 = c1 * c2;
	cout << "c1=" << c1 << "c2=" << c2 << "c3=" << c3 << "c4=" << c4 << "c5=" << c5 << endl;
	if (c2 == c3)cout << "c2==c3";
	else cout << "c2!=c3";
	return 0;
}