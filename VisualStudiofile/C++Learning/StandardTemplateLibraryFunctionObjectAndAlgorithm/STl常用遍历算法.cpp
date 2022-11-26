#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
//常用遍历算法 for_each
//普通函数
void print1(int val)
{
	cout << val << " ";
}
//仿函数
class print2
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print1);
	cout << endl;

	for_each(v.begin(), v.end(), print2());
	cout << endl;
}
//transform算法讲一个容器搬运到另一个容器中
class TransForm
{
public:
	int operator()(int val)
	{
		return val+10;
	}
};
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>target;
	//目标容器需要提前开辟空间
	target.resize(v.size());
	transform(v.begin(), v.end(), target.begin(),TransForm());
	for_each(target.begin(), target.end(), print2());
}
int main()
{
	//test01();
	//test02();
	cout << __cplusplus;
	return 0;
}