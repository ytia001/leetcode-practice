#include "NoZeroSubArray.hpp"

//solution
//long long zeroFilledSubarray(vector<int>& nums) {
//     long long res = 0;
//     for (int i = 0, j = 0; i < nums.size(); ++i) {
//         if (nums[i] != 0)
//             j = i + 1;
//          res += i - j + 1;
//     }
//     return res;
// }


// for an subarray of [6,1,9] from [6,1,9,2,3,1]
//option 1:
// considering subarray [6,1,9] by starting as [6] and find the number of new subarray
// then adding [1] to become subrray [6,1] and find the number of new subarray
// then adding [9] to become subrray [6,1,9] and find the number of new subarray
// [6]: [6] 
// [6,1]: [1] [6,1]
// [6,1,9]: [9] [1,9] [6,1,9]
//option 2:
// look at subarray all at once 
// 3 + 2 + 1

// for an subarray of [0,0,0]
//option 1:
// considering subarray [0,0,0] by starting as [0] and find the number of new subarray
// then adding [0] to become subrray [0,0] and find the number of new subarray
// then adding [0] to become subrray [0,0,0] and find the number of new subarray
// [0]: [0] 
// [0,0]: [0] [0,0]
// [0,0,0]: [0] [0,0] [0,0,0]
//option 2:
// look at subarray all at once
// 3 + 2 + 1

long long Solution::currSubArrayCount (int adjCount){
  long long currCount = 0;
  while (adjCount>0){
    currCount += adjCount;
    adjCount--;
  }
  return currCount;
}

long long Solution::zeroFilledSubarray(std::vector<int>& nums){
  int adjCount=0;
  long long total = 0;
  for(int i :nums){
    if(i){
      total += currSubArrayCount(adjCount);
      adjCount = 0;
    }else{
      adjCount ++;
    }
  }
  if(adjCount>0){
    total += currSubArrayCount(adjCount);
  }
  return total;
}

int main(){
  // for (int i = 1 ; i < 10 ; i++) std::cout<<currSubArrayCount(i)<<std::endl;
  Solution s;
  std::vector<int> test = {0,0,0,1,0,0};
  std::cout<<s.zeroFilledSubarray(test)<<std::endl;
  return 0;
}