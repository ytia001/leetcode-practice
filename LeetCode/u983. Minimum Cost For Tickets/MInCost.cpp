#include "MinCost.hpp"

int Solution::mincostTickets(std::vector<int>& days, std::vector<int>& costs){

  int total = 0;
  float weightOne = costs[0];
  float  weightSeven = 0;
  float weightThirty = 0;

  std::vector<int> sumPlaces(days.size(),0);
  for(int i = 0 ; i < sumPlaces.size() ; i++){
    sumPlaces[i] = i+1;
  }

  for ( int i = 0; i < days.size() ; i ++){
    int currVal = days[i];
    int index1 = binarySearch(currVal+6,days);
    int index2 = binarySearch(currVal+29,days);
    weightSeven =  costs[1]/(float)(sumPlaces[index1]-sumPlaces[i]+1);
    weightThirty =  costs[2]/(float)(sumPlaces[index2]-sumPlaces[i]+1);
    
    std::cout<<"index1: "<<index1<<"  "<<"index2: "<<index2<<std::endl;
    std::cout<<"weightSeven: "<<weightSeven<<"  "<<"weightThirty: "<<weightThirty<<std::endl;

    if(weightSeven < weightThirty){
      if( weightSeven < weightOne){
        i = index1;
        total += costs[1];
      }else{
        total += costs[0];
      }
    }else{
      if( weightThirty < weightOne){
        i = index2;
        total += costs[2];
      }else{
        total += costs[0];
      }
    }
  }
  return total;
}

int Solution::binarySearch(int target,const std::vector<int>& days){
  int left = 0;
  int right = days.size()-1;

  while(left<right){
    int mid = left + (right-left+1)/2;
    //std::cout<<"mid"<<mid<<std::endl;
    if(target == days[mid]){
      return mid;
    }
    else if(target > days[mid]){
      left = mid;
    }else{
      right = mid-1;
    }
  }

  return left;
}

int main(){
   Solution s;
   std::vector<int> test = {1,4,6,9,10,11,12,13,14,15,16,17,18,20,21,22,23,27,28};
   std::vector<int> cost = {3,13,45};
   std::cout<<s.mincostTickets(test,cost)<<std::endl;
   //std::cout<<s.binarySearch(17,test)<<std::endl;
   return 0;
} 

