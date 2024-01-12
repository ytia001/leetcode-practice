#include <vector>
#include<iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int count = 1;
      int val = nums[0];
      for(int i = 1; i < nums.size() ; i++){
        if(val!=nums[i]){
          if(count != 3){
            return val;
          }else{
            val = nums[i];
            count = 1;
          }
        }else{
          count++;
        }
      }
      return val;
    }
};