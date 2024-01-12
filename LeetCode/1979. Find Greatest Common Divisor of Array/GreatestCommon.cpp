#include <vector>

using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
      int minVal = min(nums[0],nums[1]);
      int maxVal = max(nums[0],nums[1]);
      for(int i = 2; i < nums.size() ; i++){
        minVal = min(minVal,nums[i]);
        maxVal = max(maxVal,nums[i]);
      }

      // if(minVal%2 != 0 && maxVal%2 !=0){
      //   return maxVal%minVal == 0 ? minVal : 1;
      // }
      // else if (minVal == 0 && maxVal == 0){
      //   int res = 0;
      //   for(int i = 2 ; i <= maxVal ; i++){
      //     if(minVal%i == 0 && maxVal%i == 0){
      //       res = i;
      //     }
      //   }
      //   return res;
      // }
      // else {

      // }

      int res = 1;
      for(int i = 2 ; i <= maxVal ; i++){
        if(minVal%i == 0 && maxVal%i == 0){
          res = i;
        }
      }
      return res;
    
    }
};