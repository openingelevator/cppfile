#include<iostream>
using namespace std;
//��̳��﷨
class Base1
{
public:
	Base1()
	{
		m_A = 100;
	}
	int m_A;
};
class Base2
{
public:
	Base2()
	{
		m_A = 200;
	}
	int m_A;
};
//����
class Son:public Base1, public Base2
{
public:
	Son()
	{
		m_C = 300;
		m_D = 400;
	}
	int m_C;
	int m_D;
};
void test01()
{
	Son s1;
	cout << "sizeof Son=" << sizeof(s1) << endl;
	//��̳�ʱ�������г���ͬ����Ա����Ҫ���������������
	cout << "Base1�µ�m_A=" << s1.Base1::m_A << endl;
	cout << "Base2�µ�m_A=" << s1.Base2::m_A;
}


int main()
{
	test01();
	return 0;

}