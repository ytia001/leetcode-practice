#include "kthMissingPosNo.hpp"

int Solution::findKthPositive(std::vector<int>& arr, int k){
  // std::vector<int> intVect(2000);
  // std::iota(intVect.begin(),intVect.end(),1);
  int currK = 0;
  int maxValue = 2000;
  for( int i = 1 ; i <= maxValue ;i++){
    if(std::find(arr.begin(),arr.end(),i) != arr.end()){
      continue;
    }
    currK++;
    if(currK == k){
      return i;
    }
  }
  return -1;
}

int main(){
  Solution s1;
  std::vector<int> test = {1,2,3,4};
  std::cout<<s1.findKthPositive(test,2) << std::endl;
  return 0;
}