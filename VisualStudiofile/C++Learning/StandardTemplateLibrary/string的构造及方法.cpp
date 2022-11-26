#include<iostream>
#include<string>
using namespace std;
//构造操作
void test01()
{
	string s1;//默认构造

	const char* str = "hello world";
	//有参构造
	string s2(str);
	cout << "s2=" << s2 << endl;
	//拷贝构造
	string s3(s2);
	cout << "s3=" << s3 << endl;
	//n个字符的初始化
	string s4(10, 'a');
	cout << "s4=" << s4 << endl;
}
//赋值操作
void test02()
{
	//等号方法赋值
	string s1 = "hello world";
	cout << "s1=" << s1 << endl;
	//拷贝赋值
	string s2 = s1;
	cout << "s2=" << s2 << endl;
	string s3;
	s3 = 'a';
	cout << "s3=" << s3 << endl;
	//assign赋值操作，单参数
	string s4;
	s4.assign("hello C++");
	cout << "s4=" << s4 << endl;
	//assign赋值操作，双参数
	string s5;
	s5.assign("hello C++",5);
	cout << "s5=" << s5 << endl;
	//assign拷贝构造
	string s6;
	s6.assign(s5);
	cout << "s6=" << s6 << endl;
	//n个字符赋值
	string s7;
	s7.assign(7, 'w');
	cout << "s7=" << s7 << endl;
}
int main()
{
	test02();
	return 0;
}