#include<iostream>
using namespace std;
class Base
{
public:
	//ֻҪ��һ�����麯���������ͳ�Ϊ������
	//�������޷�ʵ��������
	virtual void func() = 0;
};
class Son :public Base
{
public:
	virtual void func() { cout << "func��������"; }
};
void test01()
{
/*	Son s;*///���������д�����еĴ��麯���������޷�ʵ��������
	Base* base = new Son;
	base->func();
	delete base;
}
int main()
{
	test01();
	return 0;
}