#include<iostream>
using namespace std;
class Person
{
	int m_a;//�Ǿ�̬��Ա�������ڶ�����
	static int m_b;//��̬��Ա��������������Ķ�����
	void func(){}//�Ǿ�̬��Ա��������Ա�������Ա�����ֿ��洢����������Ķ�����
	static void func1(){}//��̬��Ա��������������Ķ�����
};
int Person::m_b= 0;
void test01()
{
	Person p;
	//�ն���ռ�õ��ڴ�ռ�Ϊ1���ֽ�
	//C++���������ÿ���ն���Ҳ����1���ֽڵĿռ���Ϊ�����ֿն���ռ�ڴ��λ��
	cout << "size of p=" << sizeof(p) << endl;
}
void test02()
{
	//������ֻ��int m_aһ���Ǿ�̬��Ա����ʱ��p���ڴ�Ϊ4���ֽ�
	//�������ж�����һ��static���͵ĳ�Ա����ʱ��p���ڴ���Ϊ4���ֽ�
	//��Ϊ��̬��Ա�����������������
	Person p;
	cout << "size of p=" << sizeof(p) << endl;
}
int main()
{
	//test01();
	test02();
	return 0;
}