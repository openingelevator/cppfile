#include <iostream>
#include <string>
#include <vector>
using namespace std;
string check(string& str)
{
    int times=1;//字符出现的次数
    bool isTwice=false;//BB情况下，之前是否有AA
    char c=str[0];//上一个字符
    for(int i=1;i<str.length();i++)
    {
        //记录状态
        if(str[i]==c) 
            times++;
        else 
        {
            if(times!=2)//上一个元素不是AA，则置为false
                isTwice=false;
            times=1;//重新计算
        }
        //该状态下是否要处理
        if(isTwice&&times==2||times==3)
        {
            str.erase(i,1);
            times--;
            i--;
        }
        if(times==2) isTwice=true;
        //更新上一个字符
        c=str[i];
    }
    return str;
}

int main()
{
    int N;
    cin>>N;
    vector<string> vec;
    for(int i=0;i<N;i++)
    {
        string str;
        cin>>str;
        str=check(str);
        vec.push_back(str);
    }
    for(auto e:vec)
        cout<<e<<endl;
     system("pause");
    return 0;
}