#include<iostream>
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
void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	if (L1.empty())
	{
		cout << "L1为空" << endl;
	}
	else
	{
		cout << "L1不为空" << endl;
		cout << "L1的元素个数为：" << L1.size() << endl;
	}
	L1.resize(10, 1000);
	printList(L1);

	L1.resize(2);
	printList(L1);

}
void test02()
{
	list<int>L1;
	//尾插
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	//头插
	L1.push_front(100);
	L1.push_front(200);
	L1.push_front(300);
	printList(L1);

	//尾删
	L1.pop_back();
	printList(L1);

	//头删
	L1.pop_front();
	printList(L1);

	//insert插入
	list<int>::iterator it = L1.begin();
	L1.insert(++it, 1000);
	printList(L1);

	//删除
	it = L1.begin();
	L1.erase(it);
	printList(L1);

	//移除
	L1.push_back(10000);
	printList(L1);
	//移除会删除容器中所有和element匹配的元素
	L1.remove(10000);
	printList(L1);

	//清空
	L1.clear();
	printList(L1);
}
int main()
{
	/*test01();*/
	test02();
	return 0;

}