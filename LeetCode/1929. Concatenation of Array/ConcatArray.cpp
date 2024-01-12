#include "ConcatArray.hpp"

std::vector<int> Solution::getConcatenation(std::vector<int>& nums){
  std::vector<int> copy(begin(nums),end(nums));
  for(int i = 0 ; i < nums.size() ; i++ ){
    copy.push_back(nums[i]);
  }
   return copy;
}

int main(){
  std::vector<int> testing = {1,2,3,4,0,9,-1,12};
  Solution s;
  std::vector<int> result = s.getConcatenation(testing);
  for( auto i : result){
      std::cout<<i<<" ";
    }
}

// Solution
// std::vector<int> Solution::getConcatenation(std::vector<int>& nums){
//   int size = nums.size();
//   for(int i = 0 ; i <size ; i++ ){
//     nums.push_back(nums[i]);
//   }
//    return nums;
// }