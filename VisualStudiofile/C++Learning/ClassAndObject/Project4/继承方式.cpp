#include<iostream>
#include<iomanip>
using namespace std;
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son1 :public Base1
{
public:
	void func()
	{
		m_A = 10;//�����еĹ���Ȩ�޳�Ա������������Ȼ�ǹ���Ȩ��
		m_B = 10;//�����еı���Ȩ�޳�Ա������������Ȼ�Ǳ���Ȩ��
	}
	//�����е�˽��Ȩ�޳�Ա��������ʲ���
};
void test01()
{
	Son1 s1;
	s1.m_A = 100;
//s1.m_B=100;������Son1��m_B�Ǳ���Ȩ�ޣ�������ʲ���
}
//�����̳�
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son2 :protected Base2
{
public:
	void func()
	{
		m_A = 10;//�����еĹ���Ȩ�޳�Ա���������б�Ϊ����Ȩ��
		m_B = 10;//�����еı���Ȩ�޳�Ա������������Ȼ�Ǳ���Ȩ��
	}
	//�����е�˽��Ȩ�޳�Ա��������ʲ���
};
//˽�м̳�
class Base3
{
public:
	int m_A;
	
protected:
	int m_B;
private:
	int m_C;
};
class Son3 :private Base3
{
public:
	void func()
	{
		m_A = 10;//�����еĹ���Ȩ�޳�Ա���������б�Ϊ˽��Ȩ��
		m_B = 10;//�����еı���Ȩ�޳�Ա����������Ҳ��Ϊ˽��Ȩ��
	}
	//�����е�˽��Ȩ�޳�Ա��������ʲ���
};
int main()
{
	/*test01();*/
	return 0;
}
