#include<iostream>
using namespace std;
//�̳���ͬ����Ա�Ĵ���
class Base
{
public:
	static int m_A;
	static void func()
	{
		cout << "Base-static func()" << endl;
	}
};
int Base::m_A = 100;
class Son :public Base
{
public:
	static int m_A;
	static void func()
	{
		cout << "Son-static func()" << endl;
	}
};
int Son::m_A = 200;
//ͬ���ľ�̬��Ա���ԵĴ���
void test01()
{
	Son s1;
	//1ͨ�������������
	cout << "ͨ�������������" << endl;
	cout << "Son�µ�m_A=" << s1.m_A << endl;
	//���ͨ�����������ʵ������е�ͬ����̬��Ա����Ҫ��������
	cout << "Base�µ�m_A=" << s1.Base::m_A << endl;
	//ͨ��������������
	cout << "ͨ����������" << endl;
	cout << "Son�µ�m_A=" << Son::m_A<< endl;
	//��һ��::����ͨ��������ʽ���ʣ��ڶ���::������ʸ�����������
	cout << "Base�µ�m_A=" << Son::Base::m_A << endl;
}
//ͬ���ľ�̬��Ա�����Ĵ���
void test02()
{
	Son s2;
	//ͨ���������
	cout << "ͨ���������" << endl;
	s2.func();
	s2.Base::func();
	//ͨ����������
	cout << "ͨ����������" << endl;
	Son::func();
	Son::Base::func();

}
int main()
{
	/*test01();*/
	test02();
	return 0;
}