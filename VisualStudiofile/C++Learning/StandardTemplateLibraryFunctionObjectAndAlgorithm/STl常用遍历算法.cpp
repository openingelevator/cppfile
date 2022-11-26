#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
//���ñ����㷨 for_each
//��ͨ����
void print1(int val)
{
	cout << val << " ";
}
//�º���
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
//transform�㷨��һ���������˵���һ��������
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
	//Ŀ��������Ҫ��ǰ���ٿռ�
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