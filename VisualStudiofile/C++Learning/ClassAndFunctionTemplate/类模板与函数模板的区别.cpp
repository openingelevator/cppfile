#include<iostream>
#include<string>
using namespace std;
template<class NameType, class AgeType=int>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    void ShowPerson()
    {
        cout << "����Ϊ" << m_Name << " " << "����Ϊ" << m_Age << endl;
    }
    NameType m_Name;
    AgeType m_Age;
};
//1.��ģ��û���Զ������Ƶ�
void test01()
{
    //Person p("�����"��1000);����
    Person<string,int>p("�����",1000);
    p.ShowPerson();

}
//2.��ģ����ģ��Ĳ����б��п�����Ĭ�ϲ���
void test02()
{
    Person<string>p("�����", 1000);
    p.ShowPerson();
}
int main()
{
    test02();
    return 0;
}