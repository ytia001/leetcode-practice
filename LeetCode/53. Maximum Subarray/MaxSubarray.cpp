#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:

    int maxSubArray(vector<int>& nums) {
      int res = nums[0];
      int sum = res;
      for(int i = 1 ; i<nums.size();i++){
        int cur = nums[i];
        sum = max(sum+cur,cur);
        if(sum>res) res = sum;
      }
      return res;
    }

    int maxSubArrayTest(vector<int>& nums) {
      //int res = nums[0];
      vector<int> container(nums.size(),0);
      container[0] = nums[0];
      for(int i = 1 ; i<nums.size();i++){
        container[i] = max(container[i-1]+nums[i],nums[i]);
        //res = max(res,container[i]);
      }
      //return res;
      return *max_element(container.begin(),container.end());
    }

    // void subArray(vector<int>& nums, int startIndex,int curTotal,int& res){
    //   if(startIndex==nums.size()){
    //     return;
    //   }
    //   curTotal += nums[startIndex];
    //   res = max(res,curTotal);
    //   subArray(nums,startIndex+1,curTotal,res);
    // }
    // int maxSubArray(vector<int>& nums) {
    //   int res = INT_MIN;
    //   for(int i = 0 ; i < nums.size() ; i++){
    //     subArray(nums,i,0,res);
    //   }
    //   return res;
    // }


    // void search(vector<int>& nums, int startIndex,int curTotal,int& res){
    //   //curTotal += nums[startIndex];
    //   for(int i = startIndex ; i <nums.size(); i++){
    //     // for(int j = i + 1; j< nums.size() ; j++){
    //     //   search(nums,j,curTotal,res);
    //     // }
    //     curTotal += nums[i];
    //     search(nums,i+1,curTotal,res);
    //     cout<<"curtotal: "<<curTotal<<endl;
    //     res = max(res,curTotal);
    //     curTotal -= nums[i];
    //   }
    // }
    // int maxSubArray(vector<int>& nums) {
    //   int res = INT_MIN;
    //   search(nums,0,0,res);
    //   return res;
    // }
};

int main(){
  Solution s;
  vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
  cout<<s.maxSubArray(nums)<<endl;
  return 0;
}