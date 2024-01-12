#include <vector>

using namespace std;

class Solution {
public:

    vector<int> searchRange(vector<int>& nums, int target) {
      //vector<int> res;
      if(nums.size() == 0) return {-1,-1};
      
      int start,end;
      int l = 0 ;
      int r = nums.size()-1;

      while(l<r){
        int mid = l + (r-l)/2;
        if(nums[mid] >= target){
          r = mid;
        }else{
          l = mid + 1;
        }
      }
      
      if(nums[l] != target){
        return {-1,-1};
      }else{
        start = l;
        target++;
      }

      l = 0 , r = nums.size()-1;

      while(l<r){
        int mid = l + (r-l)/2;
        if(nums[mid] >= target){
          r = mid;
        }else{
          l = mid + 1;
        }
      }

      if(nums[l] == target-1){
        end = l;
      }
      else if ( l-1 >= 0 && nums[l-1] == target-1){
        end = l-1;
      }
      else{
        end = start;
      }

      return {start,end};
    }
};