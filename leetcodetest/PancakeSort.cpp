#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxPos(int end,vector<int>&arr)
{
    int maxpos=0;
    if(end>=arr.size())
    {
        return -1;
    }else
    {
        int maxValue=0;
        for(int i=0;i<=end;i++)
        {
            if(arr[i]>maxValue)
            {
                maxValue=arr[i];
                maxpos=i;
            }
        }
    }
    return maxpos;
}
bool isOrdered(const vector<int>&arr)
{
    int flag=true;
    for(int i=0;i+1<arr.size();i++)
    {
        if(arr.at(i)>arr.at(i+1))
        {
            flag=false;
            break;
        }
    }
    return flag;
}
vector<int> pancakeSort(vector<int>& arr) {
    vector<int>ans;
    if(isOrdered(arr))
    {
        return ans;
    }
    int end=arr.size()-1;
    while(end!=0)
    {
        int pos=maxPos(end,arr);
        auto iterator=arr.begin();
        auto enditerator=arr.begin();
        for(int i=0;i<=pos;i++)
        {
            iterator++;
        }
        for(int i=0;i<=end;i++)
        {
            enditerator++;
        }
        reverse(arr.begin(),iterator);
        ans.push_back(pos+1);
        reverse(arr.begin(),enditerator);
        ans.push_back(end+1);
        end--;
    }
return ans;
}
int main()
{
    vector<int>v{3,2,4,1};
    vector<int>ans=pancakeSort(v);
    for(auto i:ans)
    {
        cout<<ans[i]<<"";
    }
    system("pause");
    return 0;
}