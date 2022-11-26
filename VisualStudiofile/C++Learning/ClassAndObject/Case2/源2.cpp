#include<iostream>
#include"Array.h"
using namespace std;
int main()
{
	Array Integers1(8);
	Array Integers2;

	cout << "Integers1的大小为" << Integers1.getSize()
		<< "\nIntegers1经过初始化后\n" << Integers1;

	cout << "Integers2的大小为" << Integers2.getSize() 
	<< "\nIntegers2经过初始化后\n" << Integers2;

	cin >> Integers1 >> Integers2;

	cout << "经过输入后，Integers1与Integers2分别为：\n";
	cout << "Integers1\n" << Integers1;
	cout<<"Integers2\n" << Integers2;

	if (Integers1 != Integers2)cout << "Integers1!=Integers2\n";

	Array Integers3(Integers1);
	cout << "Integers3的大小为" << Integers3.getSize()
		<< "\nIntegers3经过初始化后\n" << Integers3;

	cout << "将Integers2赋值给Integers1\n";
	Integers1 = Integers2;

	if (Integers1 == Integers2)cout << "Integers1==Integers2\n";

	cout << "Integers1[2]=" << Integers1[2] << endl;
	Integers1[2] = 100;
	cout << "Integers1=\n" << Integers1;

	cout << "越界检查，输入Integers1[15]\n";
	Integers1[15] = 100;

	return 0;
}