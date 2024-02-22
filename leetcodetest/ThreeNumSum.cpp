#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        int left=1,right=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            left=i+1;
            right=nums.size()-1;
            if(nums[i]>0){
                break;
            }
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            while(left<right){
            int sum =nums[i]+nums[left]+nums[right];
            if(sum>0){
                right--;
            }else if(sum<0){
                left++;
            }else{
                if((left>i+1&&
                right<nums.size()-1&&
                nums[left]!=nums[left-1]&&
                nums[right]!=nums[right+1])){
                    result.push_back({nums[i],nums[left],nums[right]});
                }else if(left==i+1||right==nums.size()-1){
                    result.push_back({nums[i],nums[left],nums[right]});
                }
                right--;
                left++;
            }
            }
            
        }
        return result;
    }
};
int main(){
    vector<int>nums={-1,-1,-1,1};
    Solution s=Solution();
    vector<vector<int>>res=s.threeSum(nums);
    for(auto iter:res){
      cout<<"[";
      for(auto i:iter){
        cout<<i<<",";
      }
      cout<<"]\n";
    }
    system("pause");
    return 0;
}