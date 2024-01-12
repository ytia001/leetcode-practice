#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:

    int maxFrequency(vector<int>& nums, int k) {
      int res = 1;
      long long sum = 0;
      int l = 0 ;
      sort(nums.begin(),nums.end());
      
      for(int r = 1 ; r < nums.size() ; r++){
        //cout<<"sum: "<<sum<<endl;
        sum +=  (r-l)*(long long)(nums[r]-nums[r-1]) ;
        //cout<<"r-l+1: "<<r-l+1<<" sum: "<<sum<<endl;
        //cout<<"r: "<<r<<" l: "<<l<<" sum: "<<sum<<endl;
        while(sum > k && l<=r){
          sum -= (nums[r]-nums[l++]);
        }
        //cout<<"r: "<<r<<" l: "<<l<<" sum: "<<sum<<endl;
        res = max(res,r-l+1);
      }
      
      return res;
    }


    // int maxFrequency(vector<int>& nums, int k) {
    //   int res = 1;
    //   vector<int> dp(nums.size(),0);
    //   sort(nums.begin(),nums.end());
    //   // dp[0] = 1;
    //   // for(int i = 1 ; i < dp.size() ; i++){
    //   //   dp[i] = (nums[i]-nums[i-1]) + (dp[i-1] + (i-1)*(nums[i]-nums[i-1]));
    //   //   if(dp[i] <= k ){
    //   //     res = i+1;
    //   //   } 
    //   // }
    //   for(int i = 1 ; i < dp.size() ; i++){
    //     dp[i] = (nums[i]-nums[i-1]) + (dp[i-1] + (i-1)*(nums[i]-nums[i-1]));
    //   }
    //   int l = 0;
    //   for(int r = 1 ; r < dp.size() ; r++){
    //     while(l<=r && (dp[r]-dp[l]) > k){
    //       l++;
    //     }
    //     if(l > r) {
    //       break;
    //     }else{
    //       res = max(res,r-l+1);
    //     }
    //   }
    //   return res;
    // }
};