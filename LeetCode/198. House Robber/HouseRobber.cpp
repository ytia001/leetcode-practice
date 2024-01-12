#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
      //int res = INT_MIN;

      for(int i = 0 ; i < nums.size(); i++){
        if(i == 1) nums[i] = max(nums[i],nums[i-1]);
        if(i >= 2){
          nums[i] = max(nums[i]+nums[i-2],nums[i-1]);
        }
        //res = max(res,nums[i]);
      }
      //return res; 
      return nums[nums.size()-1];
    }
};