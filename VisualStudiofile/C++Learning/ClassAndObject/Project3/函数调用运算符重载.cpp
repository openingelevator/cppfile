#include<iostream>
using namespace std;
class MyPrint
{

public:
	void operator()(string test)
	{
		cout << test << endl;
	}

};
class MyAdd
{
public:
	int operator()(int num1,int num2)
	{
		return num1 + num2;
	}

};
void test01()
{
	MyPrint myprint;
	myprint("hello world");//仿函数
}
void test02()
{
	MyAdd myadd;
	int ret=myadd(10, 20);
	cout << "ret=" << ret << endl;
	//匿名函数对象
	cout << MyAdd()(100, 100) << endl;

}
int main()
{
	test01();
	test02();
	return 0;

}