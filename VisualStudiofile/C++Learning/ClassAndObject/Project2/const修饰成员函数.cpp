#include<iostream>
using namespace std;
class Person
{
public:
	//�ں������ڲ��������Ƿ񴫲Σ�ÿ����Ա�����ڲ�����һ��thisָ��
	//thisָ��ʵ������һ��ָ�볣����ָ���ָ�򲻿��޸�
	//�ڳ�Ա�������const�൱��const Person *const this;
	//�ڳ�Ա�������const���ε���thisָ�룬ʹ��ָ��ָ���ֵҲ�����޸�
	void showPerson()const
	{
		this->m_B = 100;
	//this->m_A=100;Ϊ�Ƿ�����
	}
	void func()
	{
		m_A = 100;
	}
	int m_A;
	mutable int m_B;//�����������ʹ�ڳ������У�Ҳ�����޸����ֵ
};
void test01()
{
	Person p;
	p.showPerson();
}
void test02()
{
	const Person p;//�ڶ���ǰ��const����Ϊ������
	//m_A�����޸ģ�m_B������ֵ���ڳ�������Ҳ�����޸�
	p.m_B = 100;
	//p.func();Ϊ�Ƿ�������������ֻ�ܵ��ó�����
	p.showPerson();
}
int main()
{
	test01();
	return 0;


}