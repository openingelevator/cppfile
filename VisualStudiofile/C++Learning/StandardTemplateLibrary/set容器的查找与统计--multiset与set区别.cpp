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
	s1.insert(10);
	s1.insert(15);
	s1.insert(30);
	s1.insert(20);
	//����30
	set<int>::iterator pos = s1.find(30);
	if (pos != s1.end())
	{
		cout << "�ҵ�Ԫ��" << *pos << endl;
	}
	else { cout << "δ�ҵ�Ԫ��" << endl; }
	//��������set���ԣ����Ҫô��0Ҫô��1
	int num = s1.count(30);
	cout << num;
}
void test02()
{
	set<int>s;
	pair<set<int>::iterator, bool>ret = s.insert(10);
	if (ret.second)
	{
		cout << "��һ�β���ɹ�" << endl;

	}
	else
	{
		cout << "����ʧ��" << endl;
	}
	ret=s.insert(10);
	if (ret.second)
	{
		cout << "�ڶ��β���ɹ�" << endl;

	}
	else
	{
		cout << "����ʧ��" << endl;
	}

	multiset<int>ms;
	ms.insert(10);
	ms.insert(10);

	for(multiset<int>::iterator it=ms.begin();it!=ms.end();it++)
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