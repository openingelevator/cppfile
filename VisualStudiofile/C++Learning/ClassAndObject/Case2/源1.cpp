#include<iostream>
#include"Integer.h"
using namespace std;
int main()
{
	Integer i1;
	Integer i2;
	cin >> i1 >> i2;
	//���ԼӼ��˳������
	cout << "i1+i2=" << i1 + i2 << endl;
	cout << "i1-i2=" << i1 - i2 << endl;
	cout << "i1*i2=" << i1 * i2 << endl;
	cout << "i1/i2=" << i1 / i2 << endl;
	//���Ը�ֵ�����
	Integer i3 = i1;
	i3 += i2;
	cout << i3 << endl;
	Integer i4 = i1;
	i4 *= i2;
	cout << i4 << endl;
   //���Թ�ϵ�����
	if (i3 == i4)cout << "i3==i4" << endl;
	else cout << "i3!=i4" << endl;
	if (i3 >= i4)cout << "i3>=i4" << endl;
	else cout << "i3<i4" << endl;
	//���Ե��������
	cout << "i1Ϊ" << i1 << endl;
	cout << "i1++Ϊ" << i1++ << endl;
	cout << "++i1Ϊ" << ++i1 << endl;
	//���Ժ������������
	Integer i6(4);
	int num = i6(5);
	cout << "num=" << num << endl;
	return 0;

}