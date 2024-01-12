#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
      int l = 0 ;
      int r = nums.size()-1;
      while(l<r){
        bool swapped = false;
        int curR = r;
        while(l<curR){
          if(nums[l]>nums[curR]){
            swapped = true;
            swap(nums[l],nums[curR]);
          }
          curR--;
        }
        if(swapped) r--;
        l++;
      }
    }
};