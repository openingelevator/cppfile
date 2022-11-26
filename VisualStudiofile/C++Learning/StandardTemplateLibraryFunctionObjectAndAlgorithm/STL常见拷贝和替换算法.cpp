#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
//常用的拷贝与替换算法
void print1(int val)
{
	cout << val << " ";
}
class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test01()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int>v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(),v2.end(),print1);


}
class Great30
{
public:
	bool operator()(int val)
	{
		return val >= 30;
	}
};
//替换算法replace/replace_if
void test02()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(30);

	cout << "替换前" << endl;
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	cout << "替换后" << endl;
	/*replace(v.begin(), v.end(), 20, 2000);*/
	replace_if(v.begin(), v.end(), Great30(), 3000);
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

}
//容器互换swap
void test03()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 100);
	}
	cout << "替换前" << endl;
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;
	cout << "----------------------------" << endl;
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;
}
int main()
{
	//test01();
	//test02();
	test03();
	return 0;

}