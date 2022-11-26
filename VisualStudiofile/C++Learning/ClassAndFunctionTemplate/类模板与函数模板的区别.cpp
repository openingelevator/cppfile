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
        cout << "姓名为" << m_Name << " " << "年龄为" << m_Age << endl;
    }
    NameType m_Name;
    AgeType m_Age;
};
//1.类模板没有自动类型推导
void test01()
{
    //Person p("孙悟空"，1000);错误
    Person<string,int>p("孙悟空",1000);
    p.ShowPerson();

}
//2.类模板在模板的参数列表中可以有默认参数
void test02()
{
    Person<string>p("孙悟空", 1000);
    p.ShowPerson();
}
int main()
{
    test02();
    return 0;
}