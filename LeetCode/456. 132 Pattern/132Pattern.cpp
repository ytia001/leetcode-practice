#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:

    bool find132pattern(vector<int>& nums) {
      if(nums.size() < 2) return false;
      map<int,int> orderedMap;
      vector<int> smallest(nums.size(),INT_MAX);
      smallest[0] = nums[0];

      for(int i = 1 ; i < nums.size() ; i ++){
        auto iter = orderedMap.upper_bound(nums[i]);
        if(iter != orderedMap.end()){
          if(iter->second < nums[i]) return true;
        }

        if (smallest[i-1] < nums[i]){
          if(orderedMap.count(nums[i])){
            orderedMap[nums[i]] = min(orderedMap[nums[i]],smallest[i-1]);
          }else{
            orderedMap[nums[i]] = smallest[i-1];
          }
        }
        smallest[i] = min(nums[i],smallest[i-1]);
      }

      return false;
    }


    bool find132pattern(vector<int>& nums) {
      if(nums.size() < 2) return false;
      
      vector<int> dp(nums.size(),INT_MAX);
      vector<int> smallest(nums.size(),INT_MAX);
      dp[0] = nums[0];
      smallest[0] = nums[0];

      for(int i = 1 ; i < nums.size() ; i ++){
        if (smallest[i-1] < nums[i]){
          dp[i] = smallest[i-1];
        }
        smallest[i] = min(nums[i],smallest[i-1]);

        if(i >=2){
          for(int j = i - 1 ; j > 0 ; j--){
            if(nums[i] < nums[j] && nums[i]  > dp[j]){
              return true;
            }
          }
        }
      }

      // for(int i = 2 ; i < nums.size() ; i++){
      //   int check = nums[i];
      //   for(int j = i - 1 ; j > 0 ; j--){
      //     if(check < nums[j] && check > dp[j]){
      //       return true;
      //     }
      //   }
      // }
      return false;
    }


    bool find132pattern(vector<int>& nums) {
      if(nums.size() < 2) return false;
      int minVal = nums[0];
      int maxVal = nums[1];
      vector<pair<int,int>> pairVect;

      for(int i = 2 ; i < nums.size() ; i++){
        if(nums[i] > minVal && nums[i] < maxVal){
          return true;
        }else{
          // minVal = min(minVal,maxVal);
          // maxVal = max(maxVal,nums[i]);
          if(maxVal < minVal){
            minVal = maxVal;
            maxVal = nums[i];
          }else{
            maxVal = max(maxVal, nums[i]);
          }
        }
      }

      return false;
    }
};