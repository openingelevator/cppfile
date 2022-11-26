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
		cout << "���������(Heart���캯��)" << endl;
	}
	~Heart()
	{
		cout << "����ֹͣ����(Heart��������)" << endl;
	}
};
class Lung
{
	friend class CovidVirus;
public:
	Lung():numOfLungCell(10000), seriesOfDNA("ATTCCG/TAAGGC")
	{
		cout << "�β�����(Lung���캯��)" << endl;
		cout << "�β�ϸ����DNA����Ϊ" << seriesOfDNA << endl;
		cout << "�β�ϸ������Ϊ" << numOfLungCell << endl;
	}
	~Lung()
	{
		cout << "�β�ϸ����������(Lung��������)" << endl;
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
		cout << "������������(Brain���캯��)" << endl;

	}
	~Brain()
	{
		cout << "����˥�ߣ��Բ�ϸ����ȫ����(Brain��������)" << endl;
		cout << "�䰮���������ÿ��֣�Э�����ߣ��ǻ�����" << endl;

	}
};
class CovidVirus
{
public:
	CovidVirus()
	{
		cout << "������ʼ��ֳ������β�ϸ��(CovidVirus�޲ι��캯��)" << endl;
		m_Lptr = new Lung;
	}
	CovidVirus(const CovidVirus &v)
	{
		cout << "������ʼ��ֳ������β�ϸ��(CovidVirus�������캯��)" << endl;
		m_Lptr=new Lung(*v.m_Lptr);
	}
	void damageLungCell()
	{
		cout << "���������𺦷β�ϸ��" << endl;
		m_Lptr->numOfLungCell =2000;
		m_Lptr->seriesOfDNA = "AUUCCG/UAAGGC";
		cout << "��ʱ�β�ϸ������Ϊ" << m_Lptr->numOfLungCell << endl;
		cout << "��ʱ�β�ϸ���Ļ������б��޸�Ϊ" << m_Lptr->seriesOfDNA << endl;
	}
	~CovidVirus()
	{
		cout << "����״̬���ѣ�����������()(CovidVirus��������)" << endl;
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
		cout << "һ���˵�����(Person���캯��)" << endl;
	}
	~Person()
	{
		cout << "ת����֢(Person��������)" << endl;
	}
	
private:
	Brain m_Brain;
	Heart m_Heart;
	Lung m_Lung;
};
#endif
