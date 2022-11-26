#include<iostream>
using namespace std;
class AbstractDrinking
{
public:
	//煮水
	virtual void Boil() = 0;
	  //冲泡
	  virtual void Brew() = 0;
	  //倒入杯中
	  virtual void PourInCup() = 0;
	  //加入辅料
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
	//煮水
	virtual void Boil()
	{
		cout << "煮矿泉水" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;

	}
	//倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入咖啡杯中" << endl;
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入牛奶和糖" << endl;
	}
};
class Tea :public AbstractDrinking
{
public:
	//煮水
	virtual void Boil()
	{
		cout << "煮山泉水" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡茶叶" << endl;

	}
	//倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入茶杯中" << endl;
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入柠檬" << endl;
	}
};
void dowork(AbstractDrinking * abs)
{
	abs->makeDrink();
	delete abs;
}
void test01()
{
	//制作咖啡
	dowork(new Coffee);
	//制作茶叶
	dowork(new Tea);
	
}
int main()
{
	test01();
	return 0;
}