#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int res = nums[0];
      int current = nums[0];
      for(int i = 1 ; i < nums.size() ; i++){
        current = nums[i] > current+nums[i] ? nums[i] : current+nums[i];
        res = max(res,current);
      }
      return res;
    }
};