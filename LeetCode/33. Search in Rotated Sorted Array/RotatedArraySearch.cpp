#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
     int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l<r){
          int leftInt = nums[l];
          //int rightInt = nums[r];
          int mid = l + (r-l)/2;
          if(nums[mid]==target){
            return mid;
          }else if(nums[mid]>=leftInt){
            if(nums[mid]>target){
              if(leftInt>target){
                l = mid+1;
              }else{
                r = mid;
              }
            }else{
              l = mid+1;
            }
          }else{
           if(nums[mid]>target){
              r = mid;
            }else{
              if(leftInt>target){
                l = mid+1;
              }else{
                r = mid;
              }
            }
          }
        }
        if(nums[l] != target) return -1;
        return l;
    }


    int searchTest(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l<r){
          int leftInt = nums[l];
          int rightInt = nums[r];
          // if(leftInt == target) return l;
          // if(rightInt == target) return r;
          int mid = l + (r-l)/2;
          if(nums[mid]==target){
            return mid;
          }else if(nums[mid]>target){
            if(nums[mid]>=leftInt){
              if(leftInt<=target){
                r = mid; 
              }else{
                l = mid+1;   
              }
            }else{
              if(leftInt>target){
                r = mid;
              }else{
                l = mid+1;
              }
            }
      
            // if(leftInt<=target){
            //   r = mid;
            // }else{
            //   l = mid+1;
            // }
          }else{
            if(nums[mid]>=leftInt){
              l = mid+1;
            }else{
              if(leftInt>target){
                l = mid+1;
              }else{
                r = mid;
              }
            }

            // if(leftInt<=target){
            //   l = mid+1;
            // }else{
            //   r = mid;
            // }
            // if(rightInt>=target){
            //   l = mid+1;
            // }else{
            //   r = mid;
            // }
          }
        }
        if(nums[l] != target) return -1;
        return l;
    }
};

int main(){
  Solution s;
  vector<int> test = {4,5,6,7,0,1,2};
  //[4,5,6,7,0,1,2],[4,5,6,7,0,1,2],[1],[5,1,3],[4,5,6,7,8,1,2,3],[1,3],[5,1,2,3,4],[4,5,6,7,0,1,2]
  //0,3,0,3,8,3,1,5
  int target = 5;
  cout<<s.search(test,target)<<endl;
  return 0;
}