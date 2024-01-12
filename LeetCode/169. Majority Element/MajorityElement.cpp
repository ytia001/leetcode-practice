#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:


    int majorityElement(vector<int>& nums) {
     int res = 0;
     int max = 0;
     unordered_map<int,int> mp;
     for(int i : nums){
        mp[i] ++;
        if(mp[i]>max){
          max = mp[i];
          res = i;
        }
     }
     return res;
    }  

    // int majorityElement(vector<int>& nums) {
    //   if(nums.size()==1) return nums[0];
    //   sort(nums.begin(),nums.end());
    //   int window = (nums.size()/2)+1;
    //   int check = 0;
    //   for(int i = 0 ; i < nums.size() ; i++){
    //     if(i+1< window){
    //       check ^= nums[i];
    //       continue;
    //     }
    //     check ^= nums[i];
    //     if(i - window >= 0) check ^= nums[i-window];
    //     if(!check) return nums[i];
    //   }
    //   return 0;
    // }  


    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res = 0;
        int current = nums[0];
        int max = 0;
        int count = 1;
        for(int i = 1 ; i < nums.size() ; i++){
          if(nums[i]!=current){
            if(count>max) {
              res = nums[i-1];
              max = count; 
            }
            count=1;
            current = nums[i];
            continue;
          }
          count++;
        }
        if(count>max) res = nums[nums.size()-1];
        return res;
    }
};