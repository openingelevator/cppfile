#include<iostream>
#include<deque>
using namespace std;
void printDeque(deque<int>&d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		//使用const_iterator防止*it的内容被修改
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	//默认构造
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	//区间方式赋值
	deque<int>d2(d1.begin(), d1.end()-1);
	printDeque(d2);
	
	deque<int>d3(10, 100);
	printDeque(d3);

	//拷贝构造
	deque<int>d4(d3);
	printDeque(d4);
}
int main()
{
	test01();
	return 0;
}