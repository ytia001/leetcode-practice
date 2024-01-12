#include "MaximumUnitsTruck.hpp"
bool comparator ( const std::vector<int>& a, const std::vector<int>& b){
    return a[1] > b[1];
}
int Solution::maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize){
  std::sort(boxTypes.begin(),boxTypes.end(),comparator);
  
  int remainderSize = truckSize;
  int totalUnit = 0;

  for ( int i = 0 ; i < boxTypes.size() ; i++){
    if(remainderSize < boxTypes[i][0]){
      totalUnit += remainderSize * boxTypes[i][1] ;
      break;
    }else{
      totalUnit += boxTypes[i][0] * boxTypes[i][1];
      remainderSize -= boxTypes[i][0];
    }
  }

  return totalUnit;
}

int main(){
  std::vector<std::vector<int>> test= { {1,3},{2,2},{3,1}};
  Solution s1;
  std::cout<<s1.maximumUnits(test,4)<<std::endl;
  return 0;
}