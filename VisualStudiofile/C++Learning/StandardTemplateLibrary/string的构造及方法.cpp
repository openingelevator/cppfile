#include<iostream>
#include<string>
using namespace std;
//�������
void test01()
{
	string s1;//Ĭ�Ϲ���

	const char* str = "hello world";
	//�вι���
	string s2(str);
	cout << "s2=" << s2 << endl;
	//��������
	string s3(s2);
	cout << "s3=" << s3 << endl;
	//n���ַ��ĳ�ʼ��
	string s4(10, 'a');
	cout << "s4=" << s4 << endl;
}
//��ֵ����
void test02()
{
	//�Ⱥŷ�����ֵ
	string s1 = "hello world";
	cout << "s1=" << s1 << endl;
	//������ֵ
	string s2 = s1;
	cout << "s2=" << s2 << endl;
	string s3;
	s3 = 'a';
	cout << "s3=" << s3 << endl;
	//assign��ֵ������������
	string s4;
	s4.assign("hello C++");
	cout << "s4=" << s4 << endl;
	//assign��ֵ������˫����
	string s5;
	s5.assign("hello C++",5);
	cout << "s5=" << s5 << endl;
	//assign��������
	string s6;
	s6.assign(s5);
	cout << "s6=" << s6 << endl;
	//n���ַ���ֵ
	string s7;
	s7.assign(7, 'w');
	cout << "s7=" << s7 << endl;
}
int main()
{
	test02();
	return 0;
}