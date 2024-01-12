#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
      int res = 0;
      int idx = -1;
      int current = 0;
      for(int i = 0 ; i < nums.size() ; i++){
        if(nums[i]==1){
          current++;
        }else{
          //cout<<"current: "<<current<<endl;
          res = max(res,current);
          if(idx==-1){
            nums[i] = current;
            idx = i;
          }else{
            //cout<<"idx: "<<idx<<" nums[idx]: "<<nums[idx]<<endl;
            nums[i] = current - nums[idx];
            idx = i;
            current = nums[i];
          }
        }
        //cout<<"current: "<<current<<endl;
      }
      res = max(res,current);
      if(idx == -1) return nums.size()-1;
      return res;  
    }
};