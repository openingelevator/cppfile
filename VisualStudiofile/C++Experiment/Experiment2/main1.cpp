#include<iostream>
#include<string>
#include"HugeInt.h"
using namespace std;
int main()
{
	HugeInt n1("62513");
	HugeInt n2("25");
	HugeInt n3 = n1/"6";
	cout << n3;
	return 0;
}