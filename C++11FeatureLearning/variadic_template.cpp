//reference:http://c.biancheng.net/view/8599.html
#include <iostream>
#include <cstdarg>
#include<cstddef>
#include<vector>
#include<string>
using namespace std;
//可变参数的函数
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
//处理递归的边界条件
void print()
{
    cout << "test" << endl;
}
//通过递归过程把不定个数的参数一一分解
//version 1
template<typename T,typename...Types>
void print(const T &firstArg,const Types&...args)
{
    cout << firstArg << " ";
    //剩余匹配参数的个数
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
//version 1 与 version 2哪个更加泛化，哪个更加特化

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
    //可变参数有 4 个，分别为 10、20、30、40
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