#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
      bool increasing = false, decreasing = false;

      for(int i = 1 ; i<nums.size() ; i++){
        int currentDiff = nums[i]-nums[i-1];
        if(currentDiff > 0){
          increasing = true;
        }else if (currentDiff < 0){
          decreasing = true;
        }

        if(increasing && decreasing) return false;
      }

      return true;
    }
};