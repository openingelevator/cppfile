#include<iostream>
using namespace std;
//������ͨд�����̬д��ʵ�ּ�����

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
	//�������չ�µĹ��ܣ���Ҫ�޸�Դ��
	//�������ᳫ����ԭ�򣺶���չ���п��������޸Ľ��йر�
}
//���ö�̬ʵ�ּ�����
//ʵ�ּ�����������
//��֯�ṹ�������ɶ���ǿ��ǰ������ڵ���չ�Լ���ά���Ը�
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
//�ӷ���������
class Add :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_num1 + m_num2;
	}
};
//������������
class Sub :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_num1 - m_num2;
	}
};
//�˷���������
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