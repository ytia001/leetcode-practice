#include "TwoSum.hpp"

std::vector<int> Solution::twoSum(std::vector<int>& nums, int target){
  std::vector<int> sumIndices;
  bool foundBoth = false;
  int firstIndex , secondIndex;
  for (int i=0 ; i < nums.size( ) ; i++){ //2,7,11,5
    firstIndex = i;
    for ( int j = 0 ; j < nums.size() ; j++){
      if (j!=firstIndex){
      int sum = nums[firstIndex] + nums[j];
      // std::cout<<nums[firstIndex]<<std::endl;
      // std::cout<<nums[j]<<std::endl;
      if ( sum == target){
        secondIndex = j;
        foundBoth = true;
        break;
      }
      }
    
    }
    
    if (foundBoth){
       break;}
  } 
     sumIndices.push_back(firstIndex);
     sumIndices.push_back(secondIndex);
     return sumIndices;

}

std::vector<int> Solution::twoSumSoln(std::vector<int>& nums, int target){
        std::unordered_map<int, int> sums;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            auto iter_num = sums.find(target - num);
            if (iter_num != sums.end()) {
                return {i, iter_num->second};
            }
            sums.insert({num, i});
        }
        return {0, 0};
};

int main(){
  Solution s;
  std::vector<int> input = {3,3};
  std::vector<int> result = s.twoSum(input,6);
  for (int i : result){
    std::cout << i <<" ";
  }
  return 0;
}