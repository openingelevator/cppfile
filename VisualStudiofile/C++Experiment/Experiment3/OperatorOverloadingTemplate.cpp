#include<iostream>
using namespace std;
//template<class T>
//bool isEqualTo( T & a,T & b)
//{
//	if (a == b)return true;
//	else return false;
//}
//class Person
//{
//public:
//	Person(string name, int age):m_name(name),m_age(age)
//	{
//
//	}
//	bool operator==(const Person&p)
//	{
//		if (this->m_age == p.m_age && this->m_name == p.m_name)
//			return true;
//		else return false;
//	}
//private:
//	string m_name;
//	int m_age;
//};
//int main()
//{
//	cout << "自定义类型比较" << endl;
//	Person p1("张三",18);
//	Person p2("李四", 19);
//	bool flag1=isEqualTo(p1, p2);
//	cout << "Person数据类型" << endl;
//	if (flag1)cout << "p1==p2";
//	else cout << "p1!=p2";
//	cout << "/n内置数据类型比较" << endl;
//	int a1 = 22;
//	int a2 = 23;
//	bool flag2 = isEqualTo(a1, a2);
//	cout << "int 数据类型" << endl;
//	if (flag2)cout << "a1==a2";
//	else cout << "a1!=a2";
//
//	double d1 = 0.1241415;
//	double d2 = 0.1241415;
//	bool flag3 = isEqualTo(d1, d2);
//	cout << "\ndouble 数据类型" << endl;
//	if (flag3)cout << "d1==d2";
//	else cout << "d1!=d2";
//	 
//	char c1 = 'a';
//	char c2 = 'b';
//	bool flag4 = isEqualTo(c1, c2);
//	cout << "\nchar 数据类型" << endl;
//	if (flag4)cout << "c1==c2";
//	else cout << "c1!=c2";
//	return 0;
//}
template<class T1,class T2>
void test(const T1 a,const T2 b)
{
	cout << "test";
}
int main()
{
	int a = 1;
	const int b= 4;
	test(a, b);
	return 0;
}