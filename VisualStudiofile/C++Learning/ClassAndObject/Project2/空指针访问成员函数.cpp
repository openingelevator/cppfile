#include<iostream>
using namespace std;
class Person
{
public:
	void showClassName()
	{
		cout << "this is Person class" << endl;

	}
	void showAge()
	{
		//防止空指针的传入
		if (this == NULL)
		{
			return;
		}
		cout << "age=" << m_age << endl;
	}

	int m_age;
};
void test01()
{
	Person* p = NULL;
	p->showClassName();
	//p->showAge();属于非法调用，传入的指针为空，无法访问对象的属性
}
int main()
{
	test01();
	return 0;
}