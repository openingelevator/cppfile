#include<iostream>
using namespace std;
//���������������Ҫ���ֺ�ǰ�õ�������õ���������
class MyInteger
{
	friend ostream& operator<<(ostream& cout,const MyInteger& integer);
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//����ǰ�õ��������������������Ϊ��һֱ��ͬһ�����ݽ��в���
	MyInteger& operator++()
	{
		m_Num++;
		return *this;
	}
	//���غ��õ��������
	//MyInteger operator++(int) int ����ռλ������������������ǰ������õ���
	//���õ�������ֵ�����������ã���Ϊ���ص��Ǿֲ�����������ִ�����ͱ��ͷţ������÷�ʽ�������ڷǷ�����
	MyInteger operator++(int)
	{
		//�ȼ�¼��ʱ���
		MyInteger temp = *this;
		//�����
		m_Num++;
		//��󽫼�¼������з���
		return temp;
	}
private:
	int m_Num;

};

ostream& operator<<(ostream &cout,const MyInteger& integer)
{
	cout << integer.m_Num ;
	return cout;
}


void test01()
{
	MyInteger myint;
	cout << ++myint << endl;
}
void test02()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint;
}

int main()
{
	//test01();
	test02();
	return 0;
}