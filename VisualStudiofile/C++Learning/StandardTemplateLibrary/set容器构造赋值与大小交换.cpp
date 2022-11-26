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
	//��������ʱֻ��insert��ʽ
	s1.insert(10);
	s1.insert(15);
	s1.insert(30);
	s1.insert(20);
	//��������
	//set�����ص㣬���������ڱ������ʱ����Զ�������
	//set��������������ظ�ֵ
	printSet(s1);
	//��������
	set<int>s2(s1);
	printSet(s2);
	//��ֵ����
	set<int>s3;
	s3 = s2;
	printSet(s3);
	
	if (s1.empty())cout << "s1Ϊ��" << endl;
	else cout << "s1��Ϊ�գ�s1�Ĵ�СΪ"<<s1.size() << endl;

}
void test02()
{
	//set��������������ָ����С
	set<int>s1;
	s1.insert(10);
	s1.insert(15);
	s1.insert(30);
	s1.insert(20);

	set<int>s2;
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);
	s2.insert(100);
	
	cout << "����ǰ�Ľ��" << endl;
	cout << "s1���Ϊ" << endl;
	printSet(s1);
	cout << "s2���Ϊ" << endl;
	printSet(s2);
	cout << "������Ľ��Ϊ" << endl;
	s1.swap(s2);
	cout << "s1���Ϊ" << endl;
	printSet(s1);
	cout << "s2���Ϊ" << endl;
	printSet(s2);
}
int main()
{
	//test01();
	test02();
	return 0;
}