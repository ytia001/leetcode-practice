# include <vector>
# include <unordered_map>

using namespace std;

class Solution {
public:
    
    // int cal(unordered_map<int,int>& storage,int val){
    //   if(val == 1) return 0;
    //   else if (val == 2 || val == 3)  return 1;
      
    //   if(storage.count(val)) return storage[val];
    //   int count2 = (storage.count(val-count2)) ? storage[val-2] : cal(storage,val-2);
    //   int count3 = (storage.count(val-count3)) ? storage[val-3] : cal(storage,val-3);
    //   return storage[val] = min(count2,count3) + 1;
    // }


    int minOperations(vector<int>& nums) {
       int res = 0, maxCount = 0;
      unordered_map<int,int> mp;

      for(int i = 0 ; i < nums.size() ; i++ ){
        maxCount = max(maxCount,++mp[nums[i]]);
      }

      vector<int> dp(maxCount+1,-1);
      if(maxCount >= 2){
        dp[2] = 1;
      }
      if (maxCount >= 3){
        dp[3] = 1;
      }
      if (maxCount >= 4){
        dp[4] = 2;
      }
 
      for(int i = 5 ; i < dp.size() ; i++){
        dp[i] = min(dp[i-3],dp[i-2]) + 1;
      }

      for(auto& pr : mp){
        int totalOps = dp[pr.second];
        if(totalOps > 0){
          res += totalOps;
        }else{
          return -1;
        }
      }
      return res;
    }
};