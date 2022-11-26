#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//list容器的迭代器不支持随机访问，因此不能使用下标方式或者at()方式访问
//数据接口只有front()跟back()
void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	cout << "第一个元素为：" << L1.front() << endl;
	cout << "最后一个元素为：" << L1.back() << endl;

	//验证迭代器不支持随机访问
	//list<int>::iterator it = L1.begin();支持双向操作，但不支持随机访问(it+=1错误)
}
bool cmp(int a,int b)
{
	return a > b;
}
void test02()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(40);
	L1.push_back(40);
	L1.push_back(80);
	cout << "反转前：" << endl;
	printList(L1);
	L1.reverse();
	cout << "反转后：" << endl;
	printList(L1);

	//排序，所有不支持随机访问迭代器的容器，不可以使用标准库的算法，因此必须使用成员函数sort()进行排序
	/*sort(L1.begin(), L1.end());*/
	cout << "排序后（升序）" << endl;
	L1.sort();
	printList(L1);
	cout << "排序后（降序）" << endl;
	L1.sort(cmp);
	printList(L1);
}
int main()
{
	/*test01();*/
	test02();
	return 0;

}

