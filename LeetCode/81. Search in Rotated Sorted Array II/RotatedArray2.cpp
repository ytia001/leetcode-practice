#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
      int size = nums.size();

      int r = 0;
      int l = size-1;
      // while(l<r){
      //   int mid = l + (r-l)/2;
      //   if(nums[mid]<nums[0]){
      //     r = mid;
      //   }else{
      //     l = mid + 1;
      //   }
      // }   

      // if(nums[l]>nums[0]){
      //   l = 0;
      // }
      if(nums[size-1]<=nums[0]){
        int prev = nums[l + (r-l)/2];
        while(l<r){
          int mid = l + (r-l)/2;
          if(nums[mid]<=nums[size-1] && nums[mid] <= prev){
            r = mid;
          }else{
            l = mid + 1;
          }
          prev = nums[mid];
       }   
      }else{
        l = 0;
      }

      // if(nums[l]>nums[0]){
      //   l = 0;
      // }

      r = l + (size-1);

      while(l<r){
        int mid = l + (r-l)/2;
        if(nums[mid%size] < target){
          l = mid + 1;
        }else{
          r = mid;
        }
      }

      if(nums[l%size]==target) return true;
      return false;
    }

};