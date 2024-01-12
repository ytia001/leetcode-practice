#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int res = nums[0];
      for(int i = 1 ; i < nums.size() ; i++){
        res ^= nums[i];
        if(!res) return true;
        else res = nums[i];
      }
      return false;
    }
};