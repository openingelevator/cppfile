#include<iostream>
#include<string>
using namespace std;
class Animal
{
public:
	//���麯��
	virtual void speak() = 0;
	Animal()
	{
		cout << "Animal�Ĺ��캯������" << endl;
	}
	//�������������Խ������ָ���ͷ�������󲻸ɾ�������
	/*virtual~Animal()
	{
		cout << "Animal��������������" << endl;
	}*/
	//����������virtual~Animal() = 0;������޷��������ⲿ���ţ�˵�����������ӽ׶γ�������
	//��˴�������Ҳ��Ҫ�����ʵ��
	virtual~Animal() = 0;
	
};
Animal::~Animal()
{
	cout << "Animal�Ĵ���������������" << endl;
}
class Cat:public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat�Ĺ��캯������" << endl;
		m_name=new string(name);

	}
	~Cat()
	{
		if (m_name!= NULL)
		{

			cout << "Cat��������������" << endl;
			delete m_name;
			m_name = NULL;
		}
	}
	virtual void speak()
	{
		cout << *m_name<<"Сè��˵��" << endl;
	}
	string* m_name;
};
void test01()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	//�����ָ��������ʱ��������������е�������������������������ж��������ԣ�������ڴ�й¶�����
	delete animal;
}
int main()
{
	test01();
	return 0;
}