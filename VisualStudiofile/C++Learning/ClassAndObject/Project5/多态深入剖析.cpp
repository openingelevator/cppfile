#include<iostream>
using namespace std;
//��̬��̬��ԭ��
//��virtual�ؼ��ֺ�Animal�������һ���麯��ָ��(vfptr)��ָ���麯���б�(vftable)
//�麯���б��м�¼���麯���ĵ�ַ(&Animal::speak)
//�����̳�֮�������̳и�����麯��ָ�룬���麯���б�
//����ʱ�����жԸ����е��麯��������д���ͻὫ�麯���б��еĸ����麯����ַ����Ϊ�����麯���ĵ�ַ(&Cat:speak)
//��ʹ�ø����ָ���������ָ����������ʱ�򣬾ͻᷢ����̬
//���й����У�ִ��animal.speakʱ������ָ�����Cat������˾ͻ��Cat���麯���б���ȥѰ��speak����

class Animal
{
public:

	virtual void speak()
	{
		cout << "������˵��" << endl;
	}


};
class Dog :public Animal
{
public:
	void speak()
	{
		cout << "С����˵��" << endl;
	}
};
class Cat :public Animal
{
public:
	void speak()
	{
		cout << "Сè��˵��" << endl;
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
	//��virtual�ؼ�����Animal�����һ���Ǿ�̬��Ա����������ֻռһ���ֽ�
	//��virtual�ؼ�����Animal���ڡ�86��ռ�ĸ��ֽڣ��ڡ�64��ռ8���ֽ�
	cout << "sizeof Animal=" << sizeof(Animal) << endl;
}
int main()
{
	test02();
	return 0;
}