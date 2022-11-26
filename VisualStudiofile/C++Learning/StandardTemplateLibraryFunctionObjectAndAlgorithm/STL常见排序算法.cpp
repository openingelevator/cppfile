#include<algorithm>
#include<iostream>
#include<vector>
#include<functional>
#include<ctime>
using namespace std;
//常见排序算法sort
void myPrint(int val)
{
	cout << val << endl;
}
void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(50);
	v.push_back(40);
	//sort进行升序
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
	//sort进行降序
	sort(v.begin(), v.end(),greater<int>());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}
//洗牌算法，random_shuffle
void test02()
{
	vector<int>v;
	for(int i=0;i<10;i++)
	v.push_back(i);
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}
//合并算法，merge
void test03()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	//目标容器
	vector<int>vTarget;
	vTarget.resize(v1.size()+v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), myPrint);
	cout << endl;

}
//反转容器元素reverse
void test04()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(50);
	v.push_back(40);

	cout << "反转前" << endl;
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
	reverse(v.begin(), v.end());
	cout << "反转后" << endl;
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;


}
int main()
{
	//test01();
	//srand(static_cast<unsigned int>(time(0)));
	//test02();
	//test03();
	test04();
	return 0;
}
