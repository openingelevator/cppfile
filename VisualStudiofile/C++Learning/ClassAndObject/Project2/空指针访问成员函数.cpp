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
		//��ֹ��ָ��Ĵ���
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
	//p->showAge();���ڷǷ����ã������ָ��Ϊ�գ��޷����ʶ��������
}
int main()
{
	test01();
	return 0;
}