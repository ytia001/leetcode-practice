#include "CapacityPackageWithinDDays.hpp"

//SOLUTION USING Binary Search
int Solution::totalnumberDaysSoln(std::vector<int>& weights, int minWeight) {
    int numOfDays = 1;
    int currentWeight = 0;
    for (int i = 0; i < weights.size(); i++) {
        if (currentWeight + weights[i] > minWeight) {
            numOfDays++;
            currentWeight = 0;
        }
        currentWeight += weights[i];
    }
    return numOfDays;
}

// binary search an array of value from 0 to 25000000 instead of using for loop
int Solution::shipWithinDaysSoln(std::vector<int>& weights, int days) {
    int left = 0;
    int right = 25000000;
    while (left < right) {
        int mid = left + (right - left) / 2;
        int requiredDays = totalnumberDaysSoln(weights, mid);
        if (requiredDays <= days) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

// 1 ship == 1 day
int Solution::totalnumberDays (std::vector<int>& weights, int minWeight ){
  int numOfDays = 0;
  int currentWeight = 0;
  int index = 0;
  while ( index < weights.size()){
  while ( index < weights.size() && currentWeight + weights[index] <= minWeight ){
        currentWeight += weights[index++];
        
      }
  
  if(index < weights.size() && weights[index] > minWeight ) return 0;
  numOfDays ++ ;
  currentWeight = 0;
  }
  return numOfDays;
}

// Code took too long => use binary search
int Solution::shipWithinDays(std::vector<int>& weights, int days){
  int left = 0;
  int right = 300000;

  while ( left < right){
    int mid = left + (right-left)/2;
    std::cout<<"output: "<< mid << std::endl;
    int accumulatedDays = totalnumberDays(weights,mid);
     std::cout<<"accumulatedDays: "<< accumulatedDays << std::endl;
    if (accumulatedDays > days || accumulatedDays == 0){
      left = mid + 1;
    }else if(accumulatedDays <= days){
      right = mid;
    }
  }
  return left;
}

int main(){
  std::vector<int> testSet = {1,2,3,4,5,6,7,8,9,10};
  Solution s1;
  //std::cout<< s1.totalnumberDaysSoln(testSet, 2) << std::endl;
  std::cout<< s1.shipWithinDays(testSet, 5) << std::endl;
  return 0;
}

// int Solution::shipWithinDays(std::vector<int>& weights, int days){
//   int accumulatedDays = 0;
//   int currentWeight = 1;

//   while ( accumulatedDays == 0 || accumulatedDays > days ){
//     accumulatedDays = totalnumberDays(weights,currentWeight++);
//     std::cout<< accumulatedDays << std::endl;
//   }

//   int minWeight = currentWeight - 1;

//   return minWeight;
// }

// int Solution::shipWithinDays(std::vector<int>& weights, int days){
//     int minWeight, currentWeight, accumulatedDays, index;
//     currentWeight = 0;
//     minWeight = 1;
//     index = 0;
//     accumulatedDays = 0;

//     while ( accumulatedDays <= days ){
      
//       if ( index > weights.size()-1){
//         accumulatedDays = 0;
//         index = 0;
//         minWeight ++ ;
//         currentWeight = 0;
//         continue;
//       }

//       while ( currentWeight + weights[index] <= minWeight ){
//         currentWeight += weights[index++];
//       }

//       std::cout<<currentWeight<< std::endl;
//       accumulatedDays ++; 
      
//       if ( accumulatedDays > days){
//         accumulatedDays = 0;
//         index = 0;
//         minWeight ++ ;
//         currentWeight = 0;
//         continue;
//       }

//       currentWeight = 0;
//     }

//     return minWeight;

// }