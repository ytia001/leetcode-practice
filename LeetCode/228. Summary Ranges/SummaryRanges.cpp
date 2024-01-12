#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
      vector<string> res;
      if(nums.empty()) return res;
      long long nextTarget = nums[0];
      string start = to_string(nums[0]), end = to_string(nums[0]);
      for(long long i : nums){
        if(i==nextTarget){
          end = to_string(i);
          nextTarget++;
          continue;
        }else{
          start==end? res.push_back(start) : res.push_back(start+"->"+end);
          start = to_string(i), end = to_string(i);
          nextTarget = i + 1;
        }
      }
      start==end? res.push_back(start) : res.push_back(start+"->"+end);
      return res;
    }
};

int main(){

  Solution s;
  vector<int> nums = {1};
  vector<string> test = s.summaryRanges(nums);
  for(auto& i : test){
    cout<<i<<endl;
  }
  return 0;
}