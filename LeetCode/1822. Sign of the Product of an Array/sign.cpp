#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // int arraySign(vector<int>& nums) {
    //     int negVal = 0;
    //     int zeroPresent = false;
    //     for (int i : nums){
    //       if(i == 0){
    //         zeroPresent = true;
    //         break;
    //       }
    //       else if(i<0){
    //         negVal++;
    //       }
    //     }
    //     if(zeroPresent) return 0;
    //     if( negVal%2 == 0){
    //       return  1;
    //     }else if(negVal%2 != 0){
    //       return -1;
    //     }
    //   return -100;
    // }
     int arraySign(vector<int>& nums) {
        // if(nums.size()==1){
        //   if(nums[0]==0){
        //     return 0;
        //   }else if (nums[0]>0){
        //     return 1;
        //   }else {
        //     return -1;
        //   }
        // }
        std::sort(nums.begin(),nums.end());
        int left = 0;
        int right = nums.size()-1;
        while(left<right){
          int mid = left + (right-left)/2;
          if(nums[mid]>=0){
            right = mid;
          }
          else if(nums[mid]<0){
            left = mid + 1;
          }
        }
        if(nums[left] == 0) return 0;
        if(left%2 != 0 || (nums.size()==1 && nums[left]<0)){
          return -1;
        }else if(left%2 == 0 || (nums.size()==1 && nums[left]>0)){
          return 1;
        }
        return -100;
    }
};

int main(){
  std::vector<int> input = {9,72,34,29,-49,-22,-77,-17,-66,-75,-44,-30,-24};
  Solution s;
  long result = s.arraySign(input);
  std::cout<<result<<std::endl;
  return 0;
}