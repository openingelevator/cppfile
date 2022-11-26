#include<iostream>
#include<string>
using namespace std;
void test01()
{
	pair<string, int>p("Tom", 20);
	cout << "姓名为：" << p.first << "年龄" << p.second << endl;

	pair<string, int>p2 = make_pair("Jerry", 30);
	cout << "姓名为：" << p2.first << "年龄" << p2.second << endl;

}
int main()
{
	test01();
	return 0;
}