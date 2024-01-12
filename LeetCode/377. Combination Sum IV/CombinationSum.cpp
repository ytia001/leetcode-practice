#include <vector>

using namespace std;

class Solution {
public:

    int combinationSum4(vector<int>& nums, int target) {
      vector<unsigned int> dp(target+1,0);
      dp[0] = 1;
      for(int i = 1 ; i < dp.size();i++){
        for(int num: nums){
          if(i-num >=0){
            dp[i] += dp[i-num];
          }
        }
      }

      return dp[target];
    }


    int res = 0;

    void search(vector<int>& nums, int target, int currentTotal){
      if(currentTotal>=target){
        if(currentTotal == target) res++;
        return;
      }

      for(int i = 0 ; i < nums.size() ; i++){
        currentTotal += nums[i];
        search(nums,target,currentTotal);
        currentTotal -=nums[i];
      }

    }

    int combinationSum4(vector<int>& nums, int target) {
      search(nums,target,0);
      return res;
    }
};