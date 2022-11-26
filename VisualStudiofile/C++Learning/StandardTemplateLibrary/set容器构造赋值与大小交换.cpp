#include<set>
#include<iostream>
using namespace std;
void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	set<int>s1;
	//插入数据时只有insert方式
	s1.insert(10);
	s1.insert(15);
	s1.insert(30);
	s1.insert(20);
	//遍历容器
	//set容器特点，所有容器在被插入的时候会自动被排序
	//set容器不允许插入重复值
	printSet(s1);
	//拷贝构造
	set<int>s2(s1);
	printSet(s2);
	//赋值操作
	set<int>s3;
	s3 = s2;
	printSet(s3);
	
	if (s1.empty())cout << "s1为空" << endl;
	else cout << "s1不为空，s1的大小为"<<s1.size() << endl;

}
void test02()
{
	//set容器不允许重新指定大小
	set<int>s1;
	s1.insert(10);
	s1.insert(15);
	s1.insert(30);
	s1.insert(20);

	set<int>s2;
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);
	s2.insert(100);
	
	cout << "交换前的结果" << endl;
	cout << "s1结果为" << endl;
	printSet(s1);
	cout << "s2结果为" << endl;
	printSet(s2);
	cout << "交换后的结果为" << endl;
	s1.swap(s2);
	cout << "s1结果为" << endl;
	printSet(s1);
	cout << "s2结果为" << endl;
	printSet(s2);
}
int main()
{
	//test01();
	test02();
	return 0;
}