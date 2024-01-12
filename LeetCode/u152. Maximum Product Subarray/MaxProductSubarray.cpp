#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    // int maxProduct(vector<int>& nums) {
    //   int res = 0;
    //   vector<int> container(nums.size(),0);
    //   queue<int> q;
    //   container[0] = nums[0];
    //   res = max(res,nums[0]);
    //   int currentVal = 0;
    //   for(int i = 0 ; i< nums.size() ; i++){
    //     int val = container[]
    //     int val = container[i-1]*nums[i];
    //     if( nums[i] <= 0){
    //       res = max(res,container[i-1]);
    //       q.push(val);
    //       container[i] = 1;
    //     }else if(i == nums.size()-1){
    //       res = max(res,val);
    //     }else{
    //       container[i] = val;
    //     }
        
    //   }

    //   return container[nums.size()-1];
    // }
};

int main(){
  Solution s;
  vector<int> nums = {2,3,-2,4};
  //cout<<s.maxProduct(nums)<<endl;
  return 0;
}