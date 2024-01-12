#include "SortArrayIncreaseFreq.hpp"
// bool comparator1 (std::pair<int,int>& a , std::pair<int,int>& b){
//   return a.second<b.second;
// }

// bool comparator2 (std::pair<int,int>& a , std::pair<int,int>& b){
//   if (a.second==b.second){
//     return a.first>b.first;
//   }
//   return false;
// }

bool comparator (std::pair<int,int>& a , std::pair<int,int>& b){
  if (a.second!=b.second){
    return a.second<b.second;
  }
  else{
    return a.first>b.first;
  }
}
std::vector<int> Solution::frequencySort(std::vector<int>& nums){
  
  std::map<int,int> intToCount; 
  std::vector<int> copy;
  //std::sort(nums.begin(),nums.end());                            *map sort the keys values automatically in ascending order
  for (int i:nums){
    intToCount[i]++;
  }
  std::vector<std::pair<int,int>> intToCountVect(intToCount.begin(),intToCount.end());
  std::sort(intToCountVect.begin(),intToCountVect.end(),comparator); 
  // std::sort(intToCountVect.begin(),intToCountVect.end(),comparator2); 

  for (std::pair<int,int> p : intToCountVect){
      for ( int i = 0 ; i < p.second ; i++){
          copy.push_back(p.first);
      }
  }
  // for (const auto& element : intToCount) {
  //      std::cout << "Key: " << element.first << ", Value: " << element.second << std::endl;
  // }
  return copy;
}


int main(){
  std::vector<int> test = {-1,1,-6,4,5,-6,1,4,1};
  Solution s1;
  std::vector<int> result = s1.frequencySort(test);
  for(int i : result) std::cout<<i<<std::endl;
  return 0;
}