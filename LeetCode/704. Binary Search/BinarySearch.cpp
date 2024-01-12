#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

     int search(vector<int>& nums, int target) {
      int l = 0;
      int r = nums.size()-1;
      while(l<=r){
        int mid = l + (r-l)/2;
        if(nums[mid]<target){
          l = mid + 1;
        }else{
          r = mid - 1;
        }
      }
       if(l>nums.size()-1 || nums[l] != target) return -1;
       return l;
    }

    int search(vector<int>& nums, int target) {
      int l = 0;
      int r = nums.size()-1;
      while(l<r){
        int mid = l + (r-l)/2;
        if(nums[mid]<target){
          l = mid + 1;
        }else{
          r = mid;
        }
      }
      if(nums[l]!=target) return -1;
      return l;
    }
};