#include<iostream>
#include<string>
using namespace std;
class Animal
{
public:
	//纯虚函数
	virtual void speak() = 0;
	Animal()
	{
		cout << "Animal的构造函数调用" << endl;
	}
	//利用虚析构可以解决父类指针释放子类对象不干净的问题
	/*virtual~Animal()
	{
		cout << "Animal的析构函数调用" << endl;
	}*/
	//纯虚析构，virtual~Animal() = 0;会出现无法解析的外部符号，说明代码在链接阶段出现问题
	//因此纯虚析构也需要代码的实现
	virtual~Animal() = 0;
	
};
Animal::~Animal()
{
	cout << "Animal的纯虚析构函数调用" << endl;
}
class Cat:public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat的构造函数调用" << endl;
		m_name=new string(name);

	}
	~Cat()
	{
		if (m_name!= NULL)
		{

			cout << "Cat的析构函数调用" << endl;
			delete m_name;
			m_name = NULL;
		}
	}
	virtual void speak()
	{
		cout << *m_name<<"小猫在说话" << endl;
	}
	string* m_name;
};
void test01()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	//父类的指针在析构时，不会调用子类中的析构函数，导致子类中如果有堆区的属性，会出现内存泄露的情况
	delete animal;
}
int main()
{
	test01();
	return 0;
}