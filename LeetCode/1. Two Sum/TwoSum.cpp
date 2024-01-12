#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int size = nums.size();
      vector<int> copy = nums;
      vector<int> res;
      sort(copy.begin(),copy.end());
      int l = 0 , r = nums.size()-1;
      while(l<r){
        if(nums[l]+nums[r]==target){
          break;
        }else if(nums[l]+nums[r]>target){
          r--;
        }else {
          l++;
          r=nums.size()-1;
          continue;
        }
      }

      for(int i = 0 ; i <nums.size() ; i++){
        if(l!=-1 && nums[i]==copy[l]){
          res.push_back(i);
          l = -1;
        }else if(r!=-1 && nums[i]==copy[r]){
          res.push_back(i);
          r = -1;
        }
      }

      return res;
    }
};