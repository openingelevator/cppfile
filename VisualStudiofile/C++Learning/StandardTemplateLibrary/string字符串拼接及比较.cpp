#include<iostream>
#include<string>
using namespace std;
void test01()
{
	string s1 = "I ";
	s1 += "like playing games";
	cout << "s1=" << s1 << endl;
	//׷���ַ�
	s1 += ":";
	cout << "s1=" << s1 << endl;
	//׷���ַ���
	string s2 = "LOL DNF";
	s1 += s2;
	cout << "s1=" << s1 << endl;

	//��append����׷���ַ�
	string s3 = "I ";
	s3.append("love ");
	cout << "s3=" << s3 << endl;
	s3.append("game abcde", 4);
	cout << "s3=" << s3 << endl;
	//s3.append(s2);
	//cout << "s3=" << s3 << endl;
	s3.append(s2, 4, 3);//��ʾ��s2�ĵ�4��λ�ý�ȡ3���ַ�
	cout << "s3=" << s3 << endl;
}
//�ַ����Ƚϣ�����ַ�����ȣ��᷵��0�����>����1��<�򷵻�-1
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