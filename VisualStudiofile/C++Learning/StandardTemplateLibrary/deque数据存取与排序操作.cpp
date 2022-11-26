#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
int cmp(int a,int b)
{
	return a > b;
}
void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	deque<int>d1;
	d1.push_back(20);
	d1.push_back(10);
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);

	//通过at方式访问元素
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1.at(i) << " ";
	}
	cout << endl;

	cout << "第一个元素为：" << d1.front() << endl;
	cout << "第二个元素为：" << d1.back() << endl;

}
void test02()
{
	deque<int>d2;
	d2.push_back(10);
	d2.push_back(20);
	d2.push_front(200);
	d2.push_front(100);
	cout << "未排序前的容器为：" << endl;
	printDeque(d2);
	//排序，sort默认升序
	cout << "排序后的容器为" << endl;
	cout << "升序版本" << endl;
	sort(d2.begin(), d2.end());
	printDeque(d2);
	cout << "降序版本" << endl;
	sort(d2.begin(), d2.end(),cmp);
	printDeque(d2);

}
int main()
{
	/*test01();*/
	test02();
	return 0;
}