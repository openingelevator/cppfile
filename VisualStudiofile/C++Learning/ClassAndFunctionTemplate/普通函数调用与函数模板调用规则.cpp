#include<iostream>
using namespace std;
//1.��ͨ�����뺯��ģ�嶼����ʵ�֣����ȵ�����ͨ����
void myPrint(int a, int b)
{
	cout << "������ͨ����" << endl;
}
template<class T>
void myPrint(T a, T b)
{
	cout << "���ú���ģ��" << endl;
}

template<class T>
void myPrint(T a, T b,T c)
{
	cout << "�������غ���ģ��" << endl;
}
void test01()
{
	int a = 10; 
	int b = 20;
	int c = 20;
	//���е�����ͨ����,����ͨ������������ʵ��ʱ��Ҳ������ͨ����
	//myPrint(a, b);

	//2.����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
	myPrint<>(a,b);
	//3.����ģ��Ҳ���Է�������
	myPrint(a, b, c);
	//4.�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
	char c1 = 'c';
	char c2 = 'a';
	myPrint(c1, c2);
}
int main()
{
	test01();
	return 0;
}