#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//�º��� ����ֵΪbool�������ͣ���Ϊν��
//һԪν��
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
//��Ԫν��
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
	//�����������Ƿ��д����������
	vector<int>::iterator it=find_if(v.begin(), v.end(),GreaterFive());
	if (it == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��˴����������Ϊ" << *it << endl;
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