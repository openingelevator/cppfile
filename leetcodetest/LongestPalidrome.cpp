#include<iostream>
#include<string>
using namespace std;
string longestPalindrome(string s) {
    string str;
    int maxLen=1;
    int len=s.length();
    int dp[len][len];
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            dp[i][j]=false;
        }
    }
    int start=0;
    for(int i=0;i<len;i++)
    {
        dp[i][i]=true;
        if(i<len-1&&s[i]==s[i+1])
        {
            dp[i][i+1]=true;
            maxLen=2;
            start=i;
        }
    }
    for(int strlen=3;strlen<=len;strlen++)
    {
        for(int i=0;i+strlen-1<len;i++)
        {
            int j=i+strlen-1;
            if(s[i]==s[j]&&dp[i+1][j-1]==true)
            {
                dp[i][j]=true;
                maxLen=strlen;
                start=i;
            }
        }

    }
    str=s.substr(start,maxLen);
    return str;
}
int main()
{
    string str;
    cin>>str;
    cout<<longestPalindrome(str);
    system("pause");
    return 0;

}