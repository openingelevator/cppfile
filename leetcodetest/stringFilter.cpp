#include <iostream>
#include <string>
#include <vector>
using namespace std;
string check(string& str)
{
    int times=1;//�ַ����ֵĴ���
    bool isTwice=false;//BB����£�֮ǰ�Ƿ���AA
    char c=str[0];//��һ���ַ�
    for(int i=1;i<str.length();i++)
    {
        //��¼״̬
        if(str[i]==c) 
            times++;
        else 
        {
            if(times!=2)//��һ��Ԫ�ز���AA������Ϊfalse
                isTwice=false;
            times=1;//���¼���
        }
        //��״̬���Ƿ�Ҫ����
        if(isTwice&&times==2||times==3)
        {
            str.erase(i,1);
            times--;
            i--;
        }
        if(times==2) isTwice=true;
        //������һ���ַ�
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