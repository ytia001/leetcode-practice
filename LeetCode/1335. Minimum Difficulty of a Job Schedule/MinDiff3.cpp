# include <vector>
# include <algorithm>
# include <numeric>

using namespace std;

class Solution {
public:

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;
        else if (n == d) return accumulate(jobDifficulty.begin(),jobDifficulty.end(),0);

        vector<vector<int>> dp(n,vector<int>(d+1,100000));
        for(int i = n-1 ; i >= 0 ; i-- ){
          if(i == n-1) {
            dp[i][1] = jobDifficulty[i];
          }
          else {
            dp[i][1] = max(dp[i+1][1], jobDifficulty[i]); 
          }
        } 

        for( int day = 2 ; day <= d ; day++){
          for(int allo = n - day ; allo >= 0 ; allo--){
            for(int i = allo ; i <= n-day ; i++){
              dp[allo][day] = min(dp[allo][day],dp[i+1][day-1] + *max_element(jobDifficulty.begin()+allo,jobDifficulty.begin()+i+1));     
               cout<<"day: "<<day<<" allo: "<<allo<<" i: "<<i<<endl;
               cout<<"sum: "<<dp[i+1][day-1] + *max_element(jobDifficulty.begin()+allo,jobDifficulty.begin()+i+1)<<endl;
            }
               cout<<"dp[i][d]: "<<dp[allo][day]<<endl;
          }
        }

        return dp[0][d];
    }

};