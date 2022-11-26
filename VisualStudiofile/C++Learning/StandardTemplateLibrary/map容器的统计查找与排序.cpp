#include<map>
#include<iostream>
using namespace std;
class MyCompare
{
public:
	bool operator()(int v1,int v2)const
	{
		return v1 > v2;
	}
};
void test01()
{
	//����
	map<int, int>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	//���ҷ������ظü�ֵ��Ӧ�ĵ�����������ֵ�����ڣ��򷵻�m.end()
	map<int,int>::iterator pos= m.find(3);
	if (pos != m.end())
	{
		cout << "���ҵ���Ԫ��key=" << (*pos).first << "value=" << pos->second << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}

	//ͳ��
	//map����������ظ�Ԫ�أ���countͳ�ƶ��ԣ����Ҫô��0��Ҫô��1
	//multimap��countͳ�ƿ��ܴ���1
	int num=m.count(3);
	cout << "num=" << num << endl;
}
void test02()
{
	map<int, int,MyCompare>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));
	map<int, pair<int, int>, MyCompare>m2;
	pair<int, int>p1 = { 2,0 };
	m2.insert(make_pair(20, p1));
	m2.insert(make_pair(30, p1));
	

	for (map<int, int,MyCompare>::iterator it = m.begin();it != m.end();it++)
	{
		cout << "key=" << (*it).first << "value=" << it->second << endl;
	}
	for (map<int, pair<int, int>, MyCompare>::iterator it = m2.begin(); it != m2.end(); it++)
	{
		cout << "key=" << (*it).first << "value=" << it->second.first << endl;
	}

}
int main()
{
	//test01();
	test02();
	return 0;
}