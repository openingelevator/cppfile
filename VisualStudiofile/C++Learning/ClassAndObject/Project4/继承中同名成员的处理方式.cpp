#include<iostream>
using namespace std;
//�̳���ͬ����Ա�Ĵ���
class Base
{
public:
	
	Base()
	{
		 m_A = 100;
	}
	void func()
	{
		cout << "Base��func()�ĵ���" << endl;
	}
	void func(int a)
	{
		cout << "Base��func(int a)�ĵ���" << endl;
	}
	int m_A;
};
class Son :public Base
{
public:
	Son()
	{
		 m_A = 200;
	}
	void func()
	{
		cout << "Son��func()�ĵ���" << endl;
	}
	int m_A;
};
//ͬ���ĳ�Ա���ԵĴ���
void test01()
{
	Son s1;
	//����������ֱ�ӷ��������е�ͬ����Ա
	cout << "Son�µ�m_A=" << s1.m_A << endl;
	//���ͨ�����������ʵ������е�ͬ����Ա����Ҫ��������
	cout <<"Base�µ�m_A=" << s1.Base::m_A << endl;
	
}
//ͬ���ĳ�Ա�����Ĵ���
void test02()
{
	Son s2;
	s2.func();//ֱ�ӵ����ǵ��������е�ͬ����Ա
	s2.Base::func();
	//��������г��ֺ͸���ͬ���ĳ�Ա�����������ͬ�����������ص����������е�ͬ����Ա����
	//�������ʵ������б����ص�ͬ����Ա��������Ҫ��������
	s2.Base::func(100);
}
int main()
{
	/*test01();*/
	test02();
	return 0;
}