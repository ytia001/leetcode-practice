#include "twoArrayDiff.hpp"

std::vector<std::vector<int>> Solution::findDifference(std::vector<int>& nums1, std::vector<int>& nums2){

  std::vector<std::vector<int>> result;
  std::unordered_set<int> newNums1(nums1.begin(),nums1.end());
  std::unordered_set<int> newNums2(nums2.begin(),nums2.end());

  for(int i : std::unordered_set<int>(newNums2.begin(),newNums2.end())){  // iterate over a temporary unordered set object 
    //std::cout<<i<<std::endl;
    if(newNums1.count(i)){
      newNums1.erase(i);
      newNums2.erase(i);
    }
  }
  result = {std::vector<int>(newNums1.begin(),newNums1.end()),std::vector<int>(newNums2.begin(),newNums2.end())};
  return result;
}

int main(){
  Solution s1;
  std::vector<int> nums1 = {1,2,3,3};
  std::vector<int> nums2 = {1,1,2,2};
  std::vector<std::vector<int>> soln = s1.findDifference(nums1,nums2);
  for(auto i : soln){
    for(int j : i) std::cout<<j<<std::endl;
    std::cout<<""<<std::endl;
  }
  return 0;
}