#include<iostream>
#include<string>
using namespace std;
void test01()
{
	string s1 = "I ";
	s1 += "like playing games";
	cout << "s1=" << s1 << endl;
	//追加字符
	s1 += ":";
	cout << "s1=" << s1 << endl;
	//追加字符串
	string s2 = "LOL DNF";
	s1 += s2;
	cout << "s1=" << s1 << endl;

	//用append方法追加字符
	string s3 = "I ";
	s3.append("love ");
	cout << "s3=" << s3 << endl;
	s3.append("game abcde", 4);
	cout << "s3=" << s3 << endl;
	//s3.append(s2);
	//cout << "s3=" << s3 << endl;
	s3.append(s2, 4, 3);//表示从s2的第4个位置截取3个字符
	cout << "s3=" << s3 << endl;
}
//字符串比较，如果字符串相等，会返回0，如果>返回1，<则返回-1
void test02()
{
	string str1 = "xello";
	string str2 = "hello";
	if (str1.compare(str2) == 0)
	{
		cout << "str1=str2" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1>str2" << endl;
	}
	else
	{
		cout << "str1<str2" << endl;
	}
}
int main()
{
	/*test01();*/
	test02();
	return 0;
}