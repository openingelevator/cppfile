#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>
using namespace std;
class Heart
{
public:
	Heart()
	{
		cout << "心脏的生成(Heart构造函数)" << endl;
	}
	~Heart()
	{
		cout << "心脏停止跳动(Heart析构函数)" << endl;
	}
};
class Lung
{
	friend class CovidVirus;
public:
	Lung():numOfLungCell(10000), seriesOfDNA("ATTCCG/TAAGGC")
	{
		cout << "肺部生成(Lung构造函数)" << endl;
		cout << "肺部细胞的DNA序列为" << seriesOfDNA << endl;
		cout << "肺部细胞数量为" << numOfLungCell << endl;
	}
	~Lung()
	{
		cout << "肺部细胞大量死亡(Lung析构函数)" << endl;
	}
private:
	int numOfLungCell;
	string seriesOfDNA;

};
class Brain
{
public:
	Brain()
	{
		cout << "大脑正在生成(Brain构造函数)" << endl;

	}
	~Brain()
	{
		cout << "大脑衰竭，脑部细胞完全死亡(Brain析构函数)" << endl;
		cout << "珍爱生命，戴好口罩，协力抗疫，呵护健康" << endl;

	}
};
class CovidVirus
{
public:
	CovidVirus()
	{
		cout << "病毒开始繁殖，侵入肺部细胞(CovidVirus无参构造函数)" << endl;
		m_Lptr = new Lung;
	}
	CovidVirus(const CovidVirus &v)
	{
		cout << "病毒开始繁殖，侵入肺部细胞(CovidVirus拷贝构造函数)" << endl;
		m_Lptr=new Lung(*v.m_Lptr);
	}
	void damageLungCell()
	{
		cout << "病毒正在损害肺部细胞" << endl;
		m_Lptr->numOfLungCell =2000;
		m_Lptr->seriesOfDNA = "AUUCCG/UAAGGC";
		cout << "此时肺部细胞数量为" << m_Lptr->numOfLungCell << endl;
		cout << "此时肺部细胞的基因序列被修改为" << m_Lptr->seriesOfDNA << endl;
	}
	~CovidVirus()
	{
		cout << "宿主状态不佳，病毒逐渐死亡()(CovidVirus析构函数)" << endl;
		if (m_Lptr != NULL)
		{
			delete m_Lptr;
			m_Lptr = NULL;
		}
	}
	Lung* m_Lptr;
};
class Person
{
public:
	Person()
	{
		cout << "一个人诞生了(Person构造函数)" << endl;
	}
	~Person()
	{
		cout << "转入重症(Person析构函数)" << endl;
	}
	
private:
	Brain m_Brain;
	Heart m_Heart;
	Lung m_Lung;
};
#endif
