#include<iostream>
using namespace std;

class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);

public:
	Person(int a,int b)
	{
		m_A = a;
		m_B = b;
	}
private:
	//��Ա�����������������  p.operator<<(cout)�򻯰汾Ϊp<<cout
	// һ�㲻�����ó�Ա�������������������
	//void operator<<()
	//{

	//}
	int m_A;
	int m_B;
};
//ֻ������ȫ�ֺ����������������
ostream& operator<<(ostream &cout,Person &p)
{
	cout << "m_A=" << p.m_A << endl;
	cout << "m_B=" << p.m_B;
	return cout;
}
void test01()
{
	Person p(10,10);
	//p.m_A = 10;
	//p.m_B = 10;
	//����ʽ���˼�룬p�������Ҫ����<<�������غ����ķ���ֵ������cout������ͬ
	cout << p << endl;
}
int main()
{
	test01();
	return 0;
}