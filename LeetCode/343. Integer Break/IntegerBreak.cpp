#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
      vector<int> dp(n+1,0);
      dp[1] = 1;
      for(int i = 1 ; i <= n ; i++){
        //if(i!=n) dp[i] = i;
        for(int j = i-1 ; j > 0 ; j--){
          dp[i] = max(dp[i-j] * j, dp[i]);
        }
        if(i!=n) dp[i] = max(dp[i],i);
      }
      return dp[n];
    }
};