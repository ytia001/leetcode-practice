# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>

using namespace std;

class Solution {
public:

    vector<vector<int>> findMatrix(vector<int>& nums) {
      unordered_map<int, int> mp;
      vector<vector<int>> res;
      for(int i = 0 ; i < nums.size() ; i++){
        if(mp.count(nums[i])){
          if(++mp[nums[i]] == res.size()){
            res.push_back({nums[i]});
          }else{
            res[mp[nums[i]]].push_back(nums[i]);
          }
        }else{
          if(!res.empty()){
            res[0].push_back(nums[i]);
          }else{
            res.push_back({nums[i]});
          }
          mp[nums[i]] = 0;
        }

      }
      return res;
    }
};