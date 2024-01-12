#include "MissingNumber.hpp"

//  int missingNumber(vector<int>& nums) {
//        sort(nums.begin(),nums.end());
//        int s=0;
//        int e=nums.size()-1;
//        int mid = s+(e-s)/2;
//        while(s<=e)
//        {
//            if(nums[mid]<=mid)
//                 s=mid+1;
//             else
//                 e=mid-1;
//         mid = s+(e-s)/2;
//        }
//        return s;
//     }

//  int missingNumber(vector<int>& nums) {
//         int result = nums.size();
//         int i=0;
        
//         for(int num:nums){
//             result ^= num;
//             result ^= i;
//             i++;
//         }
        
//         return result;
//     }

 int Solution::missingNumber(std::vector<int>& nums){
  std::sort(nums.begin(),nums.end());
  for (int i = 0 ; i<nums.size() ; i++){
    if(i != nums[i]){
      return i;
    }
  }
  return nums.size();
 }

 int main(){
  Solution s1;
  std::vector<int> test= {9,6,4,2,3,5,7,0,1};
  std::cout<<s1.missingNumber(test)<<std::endl;
  return 0;
 }