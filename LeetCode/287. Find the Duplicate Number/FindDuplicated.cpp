#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:

    int findDuplicate(vector<int>& nums) {
      for(int i = 0 ; i < nums.size() ; i++){
        for(int j = i + 1; j <nums.size() ; j++){
          if(nums[i] == nums[j]) return nums[i];
        }
      }
      
      return -1;
    }

    // int search (vector<int>& nums, int left , int right ){
      
    //   int currentSize = right-left +1;
    //   int mid = left + (right - left)/2;

    //   if(currentSize==2 && nums[left]==nums[right]){
    //     return nums[left];
    //   }
    //   else if (currentSize == 1){
    //     return nums[left];
    //   }

    //   if(currentSize % 2 != 0){
    //     //bool midDupe = false;
    //     for(int i = left ; i <= right ; i++){
    //       if(nums[i] == nums[mid]) return nums[i];
    //     }
    //     search(nums,left,mid-1);
    //     search(nums,mid+1,right);
    //   }

    //   return search(nums,left,mid) || search(nums,mid+1,right);
    // }

    // int findDuplicate(vector<int>& nums) {
    //   unordered_set<int> history(nums.size());
      
    // }
};