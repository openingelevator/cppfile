#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	static void func()
	{
		m_a = 100;
		//m_b=200�ᱨ����̬��Ա�������ܷ��ʷǾ�̬��Ա����
		//�Ǿ�̬��Ա��������ͨ��������з��ʣ��������޷��ֱ�Ǿ�̬��Ա���������ĸ��ض�����
		cout << "static void func�����ĵ���" << endl;
	}
	static int m_a;
	int m_b;
	//��̬��Ա�����з���Ȩ�ޣ�func2���������ⲻ�ɷ���
private:
	static void func2()
	{

	}

};
void test01()
{
	//1��ͨ��������з���
	Person p;
	p.func();
	//2��ͨ���������з��ʣ��������ڵ����ж�����һ����������˲��ó�ʼ��Ҳ���Ե����������
	Person::func();
}

int main()
{
	test01();
	return 0;
}