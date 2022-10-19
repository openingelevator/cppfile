#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_N=10000;
int N=5,S[MAX_N],T[MAX_N];
pair<int,int>P[MAX_N];

int solve()
{
    //将S[MAX_N],T[MAX_N]中的值赋值到P[MAX_N]中
    //为保证结束时间早的工作排在前面，将S赋值给second,T赋值给first
    for(int i=0;i<N;i++)
    {
        P[i].first=T[i];
        P[i].second=S[i];
    }
    sort(P,P+N);

    int ans=0,t=0;
    for(int i=0;i<N;i++)
    {
        if(t<P[i].second)
        {
            ans++;
            t=P[i].first;
        }
    }
    return ans;
}

int main()
{
    //test
    for(int i=0;i<N;i++)
    {
        cin>>S[i];
    }
    for(int i=0;i<N;i++)
    {
        cin>>T[i];
    }
    printf("%d\n",solve());
    system("pause");
    return 0;
}