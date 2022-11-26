#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;
//�������������㷨
void test01()
{
	vector<int>v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}
	//����3 ��ʼ�ۼ�ֵ
	int total=accumulate(v.begin(), v.end(), 0);
	cout << total << endl;
}
void MyPrint(int val)
{
	cout << val << endl;
}
void test02()
{
	vector<int>v;
	v.resize(10);
	fill(v.begin(), v.end(), 0);
	for_each(v.begin(), v.end(), MyPrint);
}
//���������㷨   set_intersection
void test03()
{
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	v3.resize(min(v1.size(), v2.size()));
	vector<int>::iterator itEnd=set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itEnd, MyPrint);
}
//set_union  set_difference  �������ϱ���Ϊ��������
void test04()
{
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;//����Ŀ������
	vector<int>v4;//�Ŀ������
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	v3.resize(v1.size()+v2.size());
	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itEnd, MyPrint);
	cout << endl;

	v4.resize(max(v1.size(), v2.size()));
	vector<int>::iterator itEnd2 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());
	for_each(v4.begin(), itEnd2, MyPrint);
}
int main()
{
	/*test01();*/
	/*test02();*/
	//test03();
	test04();
	return 0;
}