#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
      vector<int> res, holder(2);
      sort(nums.begin(),nums.end());
      holder[0] = nums[0];
      holder[1] = 1;
      for(int i = 1 ; i < nums.size() ; i++){
        if(holder[0]!=nums[i]){
          if(holder[1] !=2) res.push_back(holder[0]);
          holder[0] = nums[i];
          holder[1] = 1;
        }
        else{
          holder[1]++;
        }
      }
      if(holder[1]==1){
        res.push_back(holder[0]);
      }
      return res;
    }

    vector<int> singleNumberTest(vector<int>& nums) {
      vector<int> res;
      sort(nums.begin(),nums.end());
      int num = nums[0];
      int count = 1;
      for(int i = 1 ; i < nums.size() ; i++){
        if(num!=nums[i] && count !=2){
          res.push_back(num);
          num = nums[i];
          count = 1;
        }else if(num!=nums[i] && count ==2){
          num = nums[i];
          count = 1;
        }
        else{
          count++;
        }
      }
      if(count==1){
        res.push_back(num);
      }
      return res;
    }


    // vector<int> singleNumber(vector<int>& nums) {
    //   vector<int> res;
    //   sort(nums.begin(),nums.end());
    //   int left = nums[0];
    //   for(int i = 1 ; i < nums.size() ; i++){
    //     if(nums[i]==nums[i+1]){
    //       i++;
    //     }else{
    //       if(i + 1 == nums.size()-1 ||nums[i+1]==nums[i+2]){
    //         res.push_back(nums[i]);
    //       }
    //       if(i == nums.size()-1 ||nums[i]==nums[i-1]){
    //         res.push_back(nums[i+1]);
    //       }
    //     }
    //   }
    // }
};

int main(){
  Solution s;
  vector<int> nums = {0,1};
  vector<int> res = s.singleNumber(nums);
  for(int i : res){
    cout<<i<<endl;  
  }
  return 0;
}