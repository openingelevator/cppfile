#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
//�ڽ���������
//�����º���
void test01()
{
	//negate һԪ�º���  ȡ���º���
	negate<int>n;
	cout << n(50) << endl;

	//plus ��Ԫ�º��� �ӷ�
	plus<int>p;
	cout << p(21, 3);
}
//��ϵ�º���
void test02()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(50);

	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//�߼��º���
void test03()
{
	vector<bool>v;

	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(true);
	v.push_back(false);


	cout << boolalpha;
	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//�����߼��� ������v���˵�v2�в�ִ��ȡ���Ĳ���
	vector<bool>v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(),logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main()
{
	//test01();
	//test02();
	test03();
	return 0;
}