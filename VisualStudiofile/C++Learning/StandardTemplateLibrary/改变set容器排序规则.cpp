#include<set>
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
	set<int>s1;
	s1.insert(10);
	s1.insert(15);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//ĞŞ¸ÄÅÅĞò¹æÔò
	set<int,const MyCompare>s2;
	s2.insert(10);
	s2.insert(15);
	s2.insert(30);
	s2.insert(20);
	s2.insert(40);
	for (set<int,MyCompare>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;


}
int main()
{
	test01();
	return 0;
}