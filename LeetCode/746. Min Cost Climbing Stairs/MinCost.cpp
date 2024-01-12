#include <vector>

using namespace std;

class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
      if(cost.size() == 2) return min(cost[0],cost[1]);

      for(int i = cost.size()-3 ; i >= 0 ; i--){
        cost[i] += min(cost[i+1],cost[i+2]);
      }

      return cost[0] > cost[1] ? cost[1] : cost[0] ;
    }


    // int minCostClimbingStairs(vector<int>& cost) {
    //   if(cost.size() == 2) return min(cost[0],cost[1]);

    //   vector<int> dp(cost.size(),0);

    //   for(int i = 0; i < cost.size() ; i++){
    //     if(i < 2) {
    //       dp[i] = cost[i];
    //       continue;
    //     }
    //     dp[i] += min(dp[i-1],dp[i-2]);
    //   }

    //   return dp[cost.size()-1];
    // }
};