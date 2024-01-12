#include "SingleElement.hpp"

// bool checkSingle(std::vector<int>& nums,int target){
//   if ( target >0 && nums[target-1] == nums[target]){
//       return false;
//     }else if ( target < nums.size() && nums[target+1] == nums[target]){
//       return false;
//     }else{
//       return true;
//     }
// }

// use O(log n) time complexity
int Solution::singleNonDuplicate(std::vector<int>& nums){
  int left = 0;
  int right = nums.size()-1;

  while(left<=right){
    int totalLeft = 0 , totalRight = 0;
    int mid = (left + right)/2;

    if (mid == 0) return nums[mid];
    if ( mid >0 && nums[mid-1] == nums[mid]){
      totalLeft = mid + 1 - 2;
      totalRight = nums.size() - ( mid + 1 );
    }else if ( mid < nums.size() && nums[mid+1] == nums[mid]){
      totalLeft = mid + 1 -1;
      totalRight = nums.size() - ( mid + 1 + 1);
    }else{
      return nums[mid];
    }

    if ( totalRight%2 != 0){
      left = mid + 1;
    }else if (totalLeft%2 != 0){
      right = mid - 1;
    }

  }
  return -1;
}

// uses O(2logn) time complexity
int Solution::singleNonDuplicateV1(std::vector<int>& nums){
  int oriMid, oriLeft , oriRight;
  int left = oriLeft = 0;
  int right = oriRight = nums.size()-1;
  int index = 0;
  oriMid = (left + right)/2;

    if ( oriMid >0 && nums[oriMid-1] == nums[oriMid]){
      oriLeft = oriMid +1;
      oriRight = oriMid -2;
    }else if ( oriMid < nums.size() && nums[oriMid+1] == nums[oriMid]){
      oriRight = oriMid - 1;
      oriLeft = oriMid + 2;
    }else{
      return nums[oriMid];
    }
      

  // 1st part 
  left = oriLeft;
  right = nums.size()-1;
  while ( left <= right){
     int mid = (left + right)/2;
    if ( mid >0 && nums[mid-1] == nums[mid]){
      left = mid + 1;
    }else if (mid < nums.size() && nums[mid+1] == nums[mid]){
      right = mid - 1;
    }else{
      index = mid;
      return nums[index];
    }
  }

  // 2nd part if no single Element in 1st part
  if (!index){
    left = 0;
    right = oriRight;
    while ( left <= right){
    int mid = (left + right)/2;
    if ( mid >0 && nums[mid-1] == nums[mid]){
      left = mid + 1;
    }else if (mid < nums.size() && nums[mid+1] == nums[mid]){
      right = mid - 1;
    }else{
      index = mid;
      return nums[index];
    }
  }
  }
  
  return -1;
}

// 1st: check the middle index whether odd or even 
// 2nd : if even, check if right element same as middle elem
// 3rd: if yes: single elem is one the left side, else it is on the left side
// 4th: if odd , check if right element not the same as middle elem
// 5th: if not the same: left elem must be the same & single elem is at right side
//      if same: single elem at the left side


// int singleNonDuplicate(vector<int>& nums) {
//         int l=0;
//         int r=nums.size()-1;
//         while(l<r){
//             int mid=(l+r)/2;
//             if(mid%2==0){
//                 if(nums[mid]==nums[mid+1]){
//                     l=mid+1;
//                 }
//                 else{
//                     r=mid;
//                 }
//             }
//             else{
//                 if(nums[mid]!=nums[mid+1]){
//                     l=mid+1;
//                 }
//                 else{
//                     r=mid;
//                 }
//             }
//         }
//         return nums[l];
//     }

int main(){
  Solution s1;
  std::vector test ={3};
  //checkSingle(test,8) ? std::cout<< "Single" : std::cout<<"Not Single";
  std::cout << s1.singleNonDuplicate(test) << std::endl;
  return 0;
}