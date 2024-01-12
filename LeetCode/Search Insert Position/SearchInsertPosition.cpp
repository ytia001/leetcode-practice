#include "SearchInsertPosition.hpp"
// o(log n) runtime complexity means binary search with sorted array
// input is sorted array

int Solution::searchInsert(std::vector<int>& nums, int target){
   int left = 0;
   int right = nums.size()-1;
    while (left <= right) {                  
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        } 
        std::cout <<"Left:"<< left << "\tRight:"<<right << std::endl;
    }
    
    // left != right
    // If target greater than final element, Left will be greater than right , Left will be the new position of target
    // If target less than final element, right less than left == left greater than right, Left will be the new position
      return (left);
    
}

// int low = 0;
//         int high = nums.size()-1;
//         int mid;
//         while(low<=high)
//         {
//             mid = low + (high-low)/2;
//             if(nums[mid]==target){
//                 return mid;
//             }
//             else if(nums[mid]<target)
//                 low = mid+1;
//             else
//                 high = mid-1;
//         }
//         return low;

int main(){
  Solution s1;
  std::vector<int> input = {1,7,12,15,21};
  std::cout<< s1.searchInsert(input,18) << std::endl;
  return 0;
}