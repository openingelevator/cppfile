#include<iostream>
#include<deque>
using namespace std;
void printDeque(const deque<int>&d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//deque容器大小操作
void test01()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	if (d1.empty()) { cout << "d1为空" << endl; }
	else {
		cout << "d1不为空" << endl;
		//deque容器只有大小，没有容量
		cout << "d1的大小为：" << d1.size() << endl;
	}
	//重新指定大小
	d1.resize(15,1);
	printDeque(d1);

	d1.resize(5);
	printDeque(d1);
}
//deque插入与删除
void test02()
{
	deque<int>d1;
	//尾插
	d1.push_back(20);
	d1.push_back(10);
	//头插
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);

	//尾删
	d1.pop_back();
	printDeque(d1);

	//头删
	d1.pop_front();
	printDeque(d1);
}
//指定位置元素的插入与删除
void test03()
{
	deque<int>d1;
	d1.push_back(20);
	d1.push_back(10);
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);

	d1.insert(d1.begin(), 1000);
	printDeque(d1);

	d1.insert(d1.begin(),2, 10000);
	printDeque(d1);

	//按照区间进行插入
	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d1.insert(d1.begin(),d2.begin(),d2.end());
	printDeque(d1);

}
void test04()
{
	deque<int>d1;
	d1.push_back(20);
	d1.push_back(10);
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);
	//删除
	deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it);
	printDeque(d1);

	//按区间方式删除
	d1.erase(d1.begin(), d1.end());
	printDeque(d1);
}
int main()
{
	//test01();
	/*test02();*/
	test03();
	test04();
	return 0;
}