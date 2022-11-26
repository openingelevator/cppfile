#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//仿函数 返回值为bool数据类型，称为谓词
//一元谓词
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
//二元谓词
class MyCompare
{
public:
	bool operator()(int a,int b)
	{
		return a > b;
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//查找容器中是否有大于五的数字
	vector<int>::iterator it=find_if(v.begin(), v.end(),GreaterFive());
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了大于五的数字为" << *it << endl;
	}

}
void test02()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);

	sort(v.begin(), v.end(),MyCompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main()
{
	//test01();
	test02();
	return 0;
}