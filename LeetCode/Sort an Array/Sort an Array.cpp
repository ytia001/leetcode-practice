#include "SortAnArray.hpp"
// use heap sort or merge sort
// std::vector<int> Solution::sortArray(std::vector<int>& nums){
//   int mid = (nums.size()-1)/2;
//   if (nums.size()==1) return std::vector<int>{nums[mid]};
//   if (nums.size()==2) return std::vector<int>{std::min(nums[0],nums[1]),std::max(nums[0],nums[1])};
 
// }

int main(){
  std::vector<int> test = {5,2,3,1};
  Solution s1;
  std::vector<int> result =  s1.sortArray(test);
  for (int i : result){
    std::cout<<i<<std::endl;
  }
  return 0 ;
}

// std::vector<int> Solution::sortArray(std::vector<int>& nums){
//   std::vector<int> sortedArray;
//   for ( int i = 0 ; i<nums.size() ; i++){
//     int currInt = nums[i];
//     if (sortedArray.size() == 0){
//       sortedArray.push_back(currInt);
//     }else{
      
//       int left = 0;
//       int right = sortedArray.size()-1;
//       // std::cout<<left<<"::"<<right<<std::endl;

//       while ( left < right){
//         int mid = left + (right - left)/2;
//         //std::cout<<mid<<std::endl;
//         if (sortedArray[mid] < currInt){
//           left = mid + 1;
//         }else{
//           right = mid;
//         }
//       }
//       // std::cout<<"left: "<<left<<std::endl;
//       // std::cout<<"sortedArray[left]:"<<sortedArray[left]<<std::endl;
//       if ( currInt > sortedArray[left]){
//         sortedArray.insert(sortedArray.begin()+left+1,currInt);
//       }else{
//         // std::cout<<"efewf"<<std::endl;
//         sortedArray.insert(sortedArray.begin()+left,currInt);
//       }
//     }
//     // for (int i :sortedArray) std::cout<<i<<std::endl;
//     // std::cout<<"-----"<<std::endl;
//   }
//   return sortedArray;
// }