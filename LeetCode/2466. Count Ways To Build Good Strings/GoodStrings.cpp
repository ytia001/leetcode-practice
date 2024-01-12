#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int answer(int low, int high, int zero, int one) {
        vector<int> dp(high + 1);
        dp[0] = 1;
        int res = 0, mod = 1e9 + 7;
        for (int i = 1; i <= high; ++i) {
            if (i >= zero) dp[i] = (dp[i] + dp[i - zero]) % mod;
            if (i >= one) dp[i] = (dp[i] + dp[i - one]) % mod;
            if (i >= low) res = (res + dp[i]) % mod;
        }
        return res;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> container(high+1,0);
        vector<int> cumulative(high+1,0);
        //long long res = 0;
        const int MOD = 1000000007; // define the modulus
        for(int i = 1 ; i <= high ; i++){
          container[i] += (i>zero)? (container[i-zero]%MOD) : (i==zero)?  1 : 0;
          container[i] +=  (i>one)? (container[i-one]%MOD) : (i==one)?  1 : 0;
           if(i>=low){
            cumulative[i] = (cumulative[i-1] + container[i]%MOD)%MOD;
            //cumulative[i] = (cumulative[i-1]%MOD + container[i]%MOD)%MOD; --------ALSO OK----------
          }
        }

        // for(int i = low ; i <= high ; i++){
        //   res += (container[i]%MOD);
        // }

        //return res;
        return cumulative[high];
    }

};

int main(){
  Solution s;
  cout<<s.countGoodStrings(1,10000,1,1)<<endl;
  cout<<s.answer(1,10000,1,1)<<endl;
  return 0;
}