#include<iostream>
#include"Array.h"
using namespace std;
int main()
{
	Array Integers1(8);
	Array Integers2;

	cout << "Integers1�Ĵ�СΪ" << Integers1.getSize()
		<< "\nIntegers1������ʼ����\n" << Integers1;

	cout << "Integers2�Ĵ�СΪ" << Integers2.getSize() 
	<< "\nIntegers2������ʼ����\n" << Integers2;

	cin >> Integers1 >> Integers2;

	cout << "���������Integers1��Integers2�ֱ�Ϊ��\n";
	cout << "Integers1\n" << Integers1;
	cout<<"Integers2\n" << Integers2;

	if (Integers1 != Integers2)cout << "Integers1!=Integers2\n";

	Array Integers3(Integers1);
	cout << "Integers3�Ĵ�СΪ" << Integers3.getSize()
		<< "\nIntegers3������ʼ����\n" << Integers3;

	cout << "��Integers2��ֵ��Integers1\n";
	Integers1 = Integers2;

	if (Integers1 == Integers2)cout << "Integers1==Integers2\n";

	cout << "Integers1[2]=" << Integers1[2] << endl;
	Integers1[2] = 100;
	cout << "Integers1=\n" << Integers1;

	cout << "Խ���飬����Integers1[15]\n";
	Integers1[15] = 100;

	return 0;
}