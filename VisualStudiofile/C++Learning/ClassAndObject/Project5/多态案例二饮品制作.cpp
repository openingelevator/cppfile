#include<iostream>
using namespace std;
class AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil() = 0;
	  //����
	  virtual void Brew() = 0;
	  //���뱭��
	  virtual void PourInCup() = 0;
	  //���븨��
	  virtual void PutSomething() = 0;
	  void makeDrink()
	  {
		  Boil();
		  Brew();
		  PourInCup();
		  PutSomething();
	  }
};
class Coffee :public AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil()
	{
		cout << "���Ȫˮ" << endl;
	}
	//����
	virtual void Brew()
	{
		cout << "���ݿ���" << endl;

	}
	//���뱭��
	virtual void PourInCup()
	{
		cout << "���뿧�ȱ���" << endl;
	}
	//���븨��
	virtual void PutSomething()
	{
		cout << "����ţ�̺���" << endl;
	}
};
class Tea :public AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil()
	{
		cout << "��ɽȪˮ" << endl;
	}
	//����
	virtual void Brew()
	{
		cout << "���ݲ�Ҷ" << endl;

	}
	//���뱭��
	virtual void PourInCup()
	{
		cout << "����豭��" << endl;
	}
	//���븨��
	virtual void PutSomething()
	{
		cout << "��������" << endl;
	}
};
void dowork(AbstractDrinking * abs)
{
	abs->makeDrink();
	delete abs;
}
void test01()
{
	//��������
	dowork(new Coffee);
	//������Ҷ
	dowork(new Tea);
	
}
int main()
{
	test01();
	return 0;
}