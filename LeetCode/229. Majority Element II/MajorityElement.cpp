#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      vector<int> res;
      unordered_map<int,int> mp;

      int target = nums.size()/3;

      for(int i = 0 ; i < nums.size() ; i++){
        if(mp.count(nums[i])){
          if(mp[nums[i]] == -1) continue;
          mp[nums[i]]++;
          if(mp[nums[i]] > target){
            res.push_back(nums[i]);
            mp[nums[i]] = -1;
          }
        }else{
          mp[nums[i]] = 1;
        }
      }

      return res;
    }
};