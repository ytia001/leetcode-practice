#include "BinarySearch.hpp"

int Solution::search(std::vector<int>& nums, int target){
  int left = 0;
  int right = nums.size()-1;
  while(left<=right){
    int mid = (left+right)/2;
    if(target == nums[mid]){
      return mid;
    }else if ( target > nums[mid]){
      left = mid + 1;
    }else{
      right = mid -1 ;
    }
  }
  return -1;
};

int main(){
  std::vector<int> test = {-1,0,3,5,9,12};
  Solution s1;
  std::cout<< s1.search(test,2) << std::endl;
  return 0;
}