#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
      int res = INT_MIN;
      int size = nums.size();
      sort(nums.begin(),nums.end());
      for(int i = 0 ;  i < nums.size()/2 ; i++){
        res = max(res,nums[i] + nums[size-1-i]);
      }
      return res; 
    }
};