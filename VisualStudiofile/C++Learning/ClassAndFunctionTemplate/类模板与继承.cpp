#include<iostream>
using namespace std;
template<class T>
class Base
{
public:
	Base(T b) { m = b; }
	T m;
};
//class Son :public Base<int>//����Ҫ֪��������T�����Ͳ��ܸ��������ռ�
//{
//
//};
//��������ָ�����ͣ�����Ҳ��Ҫ�����ģ��

template<class T1,class T2>
class Son2:public Base<T2>
{
public:
	Son2(T1 a,T2 b):Base<T2>(b)
	{
		this->obj = a;
		cout << "T1������Ϊ��" << typeid(T1).name() << endl;
		cout << "T2������Ϊ��" << typeid(T2).name() << endl;
	}
	T1 obj;
};
void test01()
{
	Son2<int, char>s2(2,'c');

}
int main()
{
	test01();
	return 0;
}