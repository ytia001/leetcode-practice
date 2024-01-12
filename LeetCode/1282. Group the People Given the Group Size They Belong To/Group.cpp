#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
      vector<vector<int>> res;
      unordered_map<int,vector<int>> mp;
      
      for(int i = 0 ; i < groupSizes.size() ; i++){
        mp[groupSizes[i]].push_back(i);
        if(mp[groupSizes[i]].size() == groupSizes[i]){
          res.push_back(mp[groupSizes[i]]);
          //mp.erase(groupSizes[i]);
          mp[groupSizes[i]].clear();
        }
      }

      return res;
    }


    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
      vector<vector<int>> res;
      unordered_map<int,vector<int>> mp;

      for(int i = 0 ; i < groupSizes.size() ; i++){
        if(mp.count(groupSizes[i])){
          mp[groupSizes[i]].push_back(i);
          if(mp[groupSizes[i]].size() == groupSizes[i]){
            res.push_back(mp[groupSizes[i]]);
            mp[groupSizes[i]].clear();
          }
        }else{
          if(groupSizes[i]==1){
            res.push_back({i});
            continue;
          }
          mp[groupSizes[i]] = {i};
        }
      }

      // for(auto i : mp){
      //   if (!i.second.empty()) res.push_back(i.second);
      // }
      return res;
    }
};