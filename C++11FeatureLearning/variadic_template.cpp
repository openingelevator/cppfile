//reference:http://c.biancheng.net/view/8599.html
#include <iostream>
#include <cstdarg>
#include<cstddef>
#include<vector>
#include<string>
using namespace std;
//�ɱ�����ĺ���
void vair_fun(int count, ...)
{
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i)
    {
        int arg = va_arg(args, int);
        std::cout << arg << " ";
    }
    va_end(args);
}
//����ݹ�ı߽�����
void print()
{
    cout << "test" << endl;
}
//ͨ���ݹ���̰Ѳ��������Ĳ���һһ�ֽ�
//version 1
template<typename T,typename...Types>
void print(const T &firstArg,const Types&...args)
{
    cout << firstArg << " ";
    //ʣ��ƥ������ĸ���
    cout << sizeof...(args) << endl;
    print(args...);
}
//version 2
template<typename...Types>
void print(const Types&...args)
{
    cout << sizeof...(args) << endl;
    print(args...);
}
//version 1 �� version 2�ĸ����ӷ������ĸ������ػ�

//spaces in template expressions
//vector<list<int> >  //ok in C++ version
//vector<list<int>>  //ok since C++11

//nullptr and std::nullptr_t
//C++11 allows you to use nullptr instead of 0 or NULL to specify that a pointer refers to no value
//nullptr is a new keyword.It automatically converts into each pointer type but not to any integral
//type. It has type nullptr_t, defined in <cstddef>
void f(int a)
{
    cout << "call f(int)" << endl;
}
void f(void* a)
{
    cout << "call f(void*)" << endl;
}

//automatic type deduction with auto  
void test()
{
    auto i = 42;
    auto j = 4.3;
    vector<string>v;
    auto k = v.begin();
    //m has a type of a lambda 
    auto m = [](int x)->bool {};
    cout << typeid(i).name() << endl;
    cout << typeid(j).name() << endl;
    cout << typeid(k).name() << endl;
    cout << typeid(m).name() << endl;
}

int main()
{
    //�ɱ������ 4 �����ֱ�Ϊ 10��20��30��40
    //vair_fun(4, 10, 20, 30, 40);
  /*  print(7.5, "hello", 42);*/

    nullptr_t a = nullptr;
    f(0);//call f(int)
    f(a);//call f(void *)
    //f(NULL);cause ambiguity

    test();
    system("pause");
    return 0;
}