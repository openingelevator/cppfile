#include<iostream>
using namespace std;
class Person
{
public:
	Person()
	{
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}
	Person(int age,int height)
	{
		m_age = age;
		m_height = new int(height);
		cout << "Person���вι��캯������" << endl;
	}
	//�Լ�ʵ�ֿ������캯�������ǳ��������������
	Person(const Person& p)
	{
		cout << "Person�������캯������" << endl;
		m_age = p.m_age;
		//�������
		m_height = new int(*p.m_height);
	}
	~Person()
	{
		//�������룬���������ٵ��������ͷŲ���
		if (m_height != NULL)
		{
			delete m_height;
			m_height = NULL;
		}
		cout << "Person��������������" << endl;
	}
	int m_age=0;
	int* m_height=NULL;
};
void test01()
{
	Person p1(10, 160);
	cout << "p1������Ϊ��" << p1.m_age << "���Ϊ��" << *p1.m_height << endl;
	//������ñ������ṩ�Ŀ������캯��������ǳ��������
	//p1��p2��ִ���ͷŲ��������ھֲ���������ջ�������Ƚ����ԭ������ͷ�p2
    //ǳ���������������Ƕ������ڴ��ظ��ͷţ����ʹ���������
	Person p2(p1);
	cout << "p2������Ϊ��" << p2.m_age << "���Ϊ��" << *p2.m_height << endl;
}
int main()
{
	test01();
	return 0;
}