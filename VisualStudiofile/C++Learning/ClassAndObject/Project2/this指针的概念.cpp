#include<iostream>
using namespace std;
class Person
{

public:
	Person(int age)
	{
		this->age = age;
	}
	Person &PersonAddAge(Person &p)
	{
		this->age += p.age;
		//thisָ��p2��ָ�룬*this��ָ��ľ���p2���������
		return *this;
	}
	int age;

};
//������Ƴ�ͻ���⣬thisָ��ָ����Ǳ����õĳ�Ա����ָ��Ķ���
void test01()
{
	Person p1(18);
	cout << "p1������Ϊ" << p1.age << endl;
}
//���ض�������*this
void test02()
{
	Person p1(10);
	Person p2(10);
	//��ʽ���˼��
	//�����ֵ��ʽ���ؾֲ����󣬺������صĲ���p2�ı��壬���ǵ��ÿ������캯�����������һ���¶���
	p2.PersonAddAge(p1).PersonAddAge(p1);
	cout << "p2������Ϊ" << p2.age << endl;
}
int main()
{
	/*test01();*/
	test02();
	return 0;

}