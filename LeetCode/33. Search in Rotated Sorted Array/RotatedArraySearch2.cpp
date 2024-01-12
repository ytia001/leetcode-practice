#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    int search(vector<int>& nums, int target) {
      int size = nums.size();
      int l = 0;
      int r = nums.size()-1;
      int val = nums[0];
      while(l<r){
        int mid = l + (r-l)/2;
        if(nums[mid]>=val){
          l = mid + 1;
        }else if (nums[mid]<val){
          r = mid;
        }
      }
 
      if(nums[l] > val){
        l = 0;
      }
    
      r = l + (size-1);
       cout<<"pivot: "<<l<<"r: "<<r<<endl;
      while(l<r){
        cout<<"l: "<<l<<" r: "<<r<<endl;
        int mid = (l+(r-l)/2);
        cout<<"mid: "<<mid<<endl;
        //cout<<"nums[mid%size]: "<<nums[mid%(size)]<<endl;
        if(nums[mid%(size)]>=target){
          r = mid;
        }else{
          l = (mid + 1);
        }
      }
      cout<<"final l: "<<l<<endl;
      cout<<"nums[l]: "<<nums[l]<<endl;
      return nums[l%size]==target? l%size : -1;
    }

    // int search(vector<int>& nums, int target) {
    //   int size = nums.size();
    //   int l = 0;
    //   int r = nums.size()-1;
    //   int val = nums[0];
    //   while(l<r){
    //     int mid = l + (r-l)/2;
    //     if(nums[mid]>=val){
    //       l = mid + 1;
    //     }else if (nums[mid]<val){
    //       r = mid;
    //     }
    //   }

    //   if(nums[l] > val){
    //     l = 0;
    //   }

    //   r = l + (size-1);

    //   while(l<r){
    //     int mid = (l+(r-l)/2)%size;
    //     if(nums[mid]>=target){
    //       r = mid;
    //     }else{
    //       l = mid + 1;
    //     }
    //   }

    //   return nums[l]==target? l : -1;
    // }
};

int main(){
  Solution s;
  vector<int> nums = {4,5,6,7,8,1,2,3};
  cout<<s.search(nums,8)<<endl;
  return 0;
}