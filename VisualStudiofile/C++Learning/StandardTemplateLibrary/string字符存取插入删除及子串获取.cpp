#include<iostream>
#include<string>
using namespace std;
void test01()
{
	string str = "hello";
	//ͨ��[]���ʵ����ַ�
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;
	//ͨ��at��ʽ���ص����ַ�
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;
	//������ʽ�����޸�
	str[0] = 'x';
	str.at(1) = 'x';
	cout << "str=" << str << endl;

}
void test02()
{
	string str = "hello";
	//�����ַ���
	str.insert(1, "111");//str.insert(1,3,'1');
	cout << "str=" << str << endl;
	//ɾ��
	str.erase(1, 3);
	cout << "str=" << str << endl;


}
void test03()
{
	string str = "abcdefg";
	string subStr = str.substr(1, 3);
	cout << "subStr=" << subStr << endl;
}
void test04()
{
	string email = "zhangsan@sina.com";
	int pos = email.find("@");
	string userName = email.substr(0, pos);
	cout << "sybStr=" << userName << endl;
}
int main()
{
	/*test01();*/
	//test02();
	/*test03();*/
	test04();
	return 0;
}