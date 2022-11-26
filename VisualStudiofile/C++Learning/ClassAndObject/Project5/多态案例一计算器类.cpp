#include<iostream>
using namespace std;
//利用普通写法与多态写法实现计算器

class Calculator
{
public:
	int getResult(string oper)
	{
		if (oper == "+")
		{
			return m_num1 + m_num2;
		}
		else if (oper == "-")
		{
			return m_num1 - m_num2;
		}
		else if (oper == "*")
		{
			return m_num1 * m_num2;
		}
		
	}
	int m_num1;
	int m_num2;
};
void test01()
{
	Calculator c;
	c.m_num1 = 20;
	c.m_num2 = 10;
	cout << c.m_num1 << "+" << c.m_num2 <<"=" <<c.getResult("+") << endl;
	cout << c.m_num1 << "-" << c.m_num2 << "=" << c.getResult("-") << endl;
	cout << c.m_num1 << "*" << c.m_num2 << "=" << c.getResult("*") << endl;
	//如果想拓展新的功能，需要修改源码
	//开发中提倡开闭原则：对拓展进行开发，对修改进行关闭
}
//利用多态实现计算器
//实现计算器抽象类
//组织结构清晰，可读性强，前期与后期的拓展性及可维护性高
class AbstractCalculator
{
public:
	virtual int getResult()
	{
		return 0;
	}
	int m_num1;
	int m_num2;
};
//加法计算器类
class Add :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_num1 + m_num2;
	}
};
//减法计算器类
class Sub :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_num1 - m_num2;
	}
};
//乘法计算器类
class Mul :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_num1 * m_num2;
	}
};
void test02()
{
	AbstractCalculator* ptr = new Add;
	ptr->m_num1 = 20;
	ptr->m_num2 = 10;
	cout << ptr->m_num1 << "+" << ptr->m_num2 << "=" << ptr->getResult() << endl;
	delete ptr;
	AbstractCalculator* ptr2 = new Sub;
	ptr2->m_num1 = 20;
	ptr2->m_num2 = 10;
	cout << ptr2->m_num1 << "-" << ptr2->m_num2 << "=" << ptr2->getResult() << endl;
	delete ptr2;
	AbstractCalculator* ptr3 = new	Mul;
	ptr3->m_num1 = 20;
	ptr3->m_num2 = 10;
	cout << ptr3->m_num1 << "*" << ptr3->m_num2 << "=" << ptr3->getResult() << endl;
	delete ptr3;
}
int main()
{
	test02();
	return 0;
}