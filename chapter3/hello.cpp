#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
    string num;
    cin>>num;
    double integer=0;
    int index=0;
    while(num[index]!='.'&&index<num.length())
    {
        integer = 10 * integer + (num[index] - 48);
        index++;
    }
    string Subnum=num.substr(index+1,num.length());
    double decimal=0.0;
    double times=1.0;
    for(int i=0;i<Subnum.length();i++)
    {
        times*=0.1;
        decimal+=(Subnum[i]-48)*times;
    }
    cout<<decimal<<endl;
    cout<<setprecision(10)<<fixed;
    cout<<decimal+integer<<endl;
    system("pause");
    return 0;
}