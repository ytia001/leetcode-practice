#include "LargestPosNumWithNeg.hpp"

int Solution::findMaxK(std::vector<int>& nums){
  int maxK = -1;
  std::sort(nums.begin(),nums.end());         //sort for ascending int order vector
  for (int i = 0; i < nums.size();i++){
    int posiIndex = nums.size()-1-i;          // start from the largest positive int
    if(nums[posiIndex] > 0){                  // only work with positive int 
      int searchNegNum = -nums[posiIndex];    // find its negative counterpart

      int left = 0;                           // binary search the negative counterpart through the vector
      int right = nums.size();
      // std::cout<<"ad"<< searchNegNum<<std::endl;
      while (left<right){                     // ensure binary search will end when left and right points 1 element & return it
        int mid = left + (right-left)/2;
        if (searchNegNum>nums[mid]){
          left = mid+1;
        }else{
          right = mid;
        }
      }
      // std::cout<<"afcd"<<left<<"/t"<<right <<std::endl;
      if (nums[left] == searchNegNum){        // check if the only element is the same as negative counterpart 
        maxK = -nums[left];                   // Yes then return the positve value and end linear search
        break;
      }else{
        continue;                             // No then continue the linear search for the next largest positive integer
      }
    }else{
      break;                                   // Stop the linear search once it finish all the positive integer
    }
  }

  return maxK;
};

int main(){

  std::vector<int> test= {-10,8,6,7,-2,-3};
  Solution s1;
  std::cout<< s1.findMaxK(test)<<std::endl;
  return 0;
}