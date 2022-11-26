#include<iostream>
using namespace std;
//动态多态的原理
//加virtual关键字后，Animal类会生成一个虚函数指针(vfptr)，指向虚函数列表(vftable)
//虚函数列表中记录着虚函数的地址(&Animal::speak)
//发生继承之后，子类会继承父类的虚函数指针，与虚函数列表
//若此时子类中对父类中的虚函数进行重写，就会将虚函数列表中的父类虚函数地址覆盖为子类虚函数的地址(&Cat:speak)
//当使用父类的指针或者引用指向子类对象的时候，就会发生多态
//运行过程中，执行animal.speak时，由于指向的是Cat对象，因此就会从Cat的虚函数列表中去寻找speak函数

class Animal
{
public:

	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}


};
class Dog :public Animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};
class Cat :public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}

};

void doSpeak(Animal& animal)
{
	animal.speak();
}
void test01()
{
	Cat cat;
	//Animal &animal=cat;
	doSpeak(cat);
	Dog dog;
	doSpeak(dog);
}
void test02()
{
	//无virtual关键字下Animal类仅有一个非静态成员函数函数，只占一个字节
	//有virtual关键字下Animal类在×86下占四个字节，在×64下占8个字节
	cout << "sizeof Animal=" << sizeof(Animal) << endl;
}
int main()
{
	test02();
	return 0;
}