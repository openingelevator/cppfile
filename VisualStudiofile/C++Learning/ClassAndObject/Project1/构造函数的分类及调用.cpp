#include<iostream>
using namespace std;
class Person 
{public:
	//���캯��
	Person()
	{
		cout << "Person���޲ι������" << endl;
	}
	Person(int a)
	{
		age = a;
		cout << "Person���вι������" << endl;
	}
	Person(const Person &p)
	{
		age = p.age;
		cout << "Person�Ŀ������캯������" << endl;
	}
	int age;
};
void test01()
{
	//1���ŷ�
	//����Ĭ�Ϲ��캯��ʱ��Ҫ��()
	//������()ʱ������������Ϊ����һ������������
	Person p1;
	Person p2(10);
	Person p3(p2);
	//2��ʾ��
	//Person(10) Person(p4)��Ϊ�������󣬵�ǰ��ִ�н�����ϵͳ���������յ���������
	//��Ҫ���ÿ������캯����ʼ���������� ��������ΪPerson(p4)�ȼ���Person p4,�൱�ڶ��������
	Person p4 = Person(10);
	Person p5 = Person(p4);
	/*3��ʽת����*/
	Person p6 = 10;
	Person p7 = p6;
}
int main()
{
	test01();
	return 0;
}