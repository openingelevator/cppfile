#include<iostream>
#include<string>
using namespace std;
int lengthOfLongestSubstring(string s) {
        int res=1;
        int maxlen=0;
        bool flag;
        for(int i=0;i<s.length();i++)
        {
            res=1;
            flag=true;
            for(int j=i+1;j<s.length();j++)
            {

                for(int k=i;k<j;k++)
                {
                    if(s[k]==s[j])
                    {
                        flag=false;
                    }
                }
                if(flag)
                {
                    res++;
                }else
                {
                    break;
                }
            }
            if(res>maxlen)
            {
                maxlen=res;
            }
        }
        return maxlen;
    }
int main()
{
    string str;
    cin>>str;
    cout<<lengthOfLongestSubstring(str);
    system("pause");
    return 0;
}