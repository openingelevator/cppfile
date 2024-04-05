#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
    vector<int> sortedSquares(vector<int>& nums) {
        if(nums.size()==1)return {nums[0]*nums[0]};
        vector<int>res=vector<int>(nums.size(),0);
        int j=0;
        int count=0;
        while(j<nums.size()&&nums[j]<0){
            count++;
            cout<<count<<endl;
            for(j=0;j<nums.size()-1;j++){
                if(abs(nums[j])>=abs(nums[j+1])){
                    swap(nums[j],nums[j+1]);
                }else{
                    break;
                }
            }
            // cout<<j<<endl;
            if(count>nums.size()){
                break;
            }
        }
        for(int k=0;k<nums.size();k++){
            res[k]=nums[k]*nums[k];
        }
        return res;
    }
};
int main(){
    Solution s=Solution();
    vector<int>nums={-4,-1,0,3,10};
    // vector<int>nums={-4,-3,-2,-1};
    vector<int>res=s.sortedSquares(nums);
    for(auto i:res){
      cout<<i<<" ";
    }
    system("pause");
    return 0;
}