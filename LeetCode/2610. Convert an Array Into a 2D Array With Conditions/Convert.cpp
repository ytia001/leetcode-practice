# include <vector>
# include <iostream>
# include <unordered_map>
# include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,unordered_set<int>> mp;
        vector<vector<int>> res;

        for(int i = 0 ; i < nums.size() ; i++){
          if(mp.count(nums[i])){
            unordered_set<int> idxAvoid = mp[nums[i]];
            if(idxAvoid.size() == res.size()){
                res.push_back({nums[i]});
                mp[nums[i]].insert(res.size()-1);
                continue;
            }
            for(int j = 0 ; j < res.size() ; j++){
              if(!idxAvoid.count(j)){
                res[j].push_back(nums[i]);
                mp[nums[i]].insert(j);
                break;
              }
            }
          }else{
            if(!res.empty()){
              res[0].push_back(nums[i]);
            }else{
              res.push_back({nums[i]});
            }
            mp[nums[i]] = {0};
          }
        }

        return res;
    }
};