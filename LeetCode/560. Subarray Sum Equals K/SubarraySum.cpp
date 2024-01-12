#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    
    int subarraySum(vector<int>& nums, int k) {
      int res; 
      vector<int> pastValues;

      for(int i = 0 ; i < nums.size() ; i++){
        vector<int> dummy = pastValues;
        pastValues.clear();
        for(auto& a : dummy){
          int total = a + nums[i];
          if(total == k){
            res++;
          }

          pastValues.push_back(total);
        }
      }

      return res;
    }

    //  int subarraySum(vector<int>& nums, int k) {
    //   int res = 0;
    //   vector<int> dp(nums.size()+1,0);

    //   for(int i = nums.size()-1 ; i >= 0 ; i--){
    //     if(nums[i] + dp[i+1] <= k){
    //       dp[i] = nums[i] + dp[i+1];
    //     }
    //     else{
    //       dp[i] = nums[i];
    //     }

    //     if(dp[i]==k) res++;
    //   }
      
    //   return res;
    // }


     int subarraySum(vector<int>& nums, int k) {
      int res = 0;
      int l = 0, count = 0;

      for(int i = 0 ; i < nums.size() ; i ++){
        count += nums[i];

        while(count > k && l <= i){
          count -= nums[l++];
        }

        if(count == k && l<=i) res++;
      }
      
      return res;
    }


    // int subarraySum(vector<int>& nums, int k) {
    //   int res = 0;
    //   vector<int> dp(nums.size()+1,0);
    //   dp[0] = 0;
    //   for(int i = 1 ; i <= nums.size() ; i++){
    //     // if(nums[i-1] + dp[i-1] == k){
    //     //   res ++;
    //     //   dp[i] = nums[i-1] + dp[i-1];
    //     // }
    //     // else if(nums[i-1] + dp[i-1] < k){
    //     //   dp[i] = nums[i-1] + dp[i-1];
    //     // }else{
    //     //   dp[i] = nums[i-1];
    //     //   if(dp[i] == k) res++;
    //     // }

    //     if(nums[i-1] + dp[i-1] <= k){
    //       dp[i] = nums[i-1] + dp[i-1];
    //     }
    //     else{
    //       dp[i] = nums[i-1];
    //     }

    //     if(dp[i]==k) res++;
    //   }

    //   return res;
    // }
};