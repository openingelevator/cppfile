#include<iostream>
using namespace std;
class Person2
{
public:
	Person2()
	{
		m_age = 0;
		cout << "Person2���޲ι��캯������" << endl;;
	}
	Person2(int a)
	{
		m_age = a;
		cout << "Person2���вι��캯������"<<endl;
	}
	Person2(const Person2& p)
	{
		m_age = p.m_age;
		cout << "Person2�Ŀ������캯������" << endl;;
	}
	~Person2()
	{
		cout << "Person2��������������" << endl;

	}

	int m_age;
};
//1��ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
//void test02()
//{
//	Person2 p1(10);
//	Person2 p2(p1);
//
//}
//2��ֵ���ݵķ�ʽ������������ֵ
//void dowork(Person2 p)
//{
//
//}
//void test03()
//{
//	Person2 p;
//	dowork(p);//��������ʱ����
//}
//3��ֵ��ʽ�����ֲ�����
Person2 dowork2()
{
	Person2 p1;
	cout << (int*)&p1 << endl;
	return p1;

}
void test04()
{
	Person2 p = dowork2();
	cout << (int*)&p << endl;
}
int main()
{
	test04();
	return 0;

}