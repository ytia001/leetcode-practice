#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
      int lower = 0 ,  currentVal = nums[0];
      int res = 0;
      sort(nums.begin(),nums.end());

      for(int i = 1 ; i < nums.size() ; i++){
        if(nums[i] > currentVal){
          lower++;
          currentVal = nums[i];
        }
        res += lower;
      }
      return res;
    }
};