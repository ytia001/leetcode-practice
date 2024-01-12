#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:

    void checking(vector<int>& nums, unordered_set<int>& history, vector<int>& curVect, vector<vector<int>>& res){
      if (curVect.size()==nums.size()) {
        res.push_back(curVect);
        return;
      }

      for(int i = 0 ; i < nums.size() ; i++){
        if(history.count(nums[i])) continue;
        history.insert(nums[i]);
        curVect.push_back(nums[i]);
        checking(nums,history,curVect,res);
        curVect.pop_back();
        history.erase(nums[i]);
      }
    }

    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> res;  
      vector<int> curVect;
      unordered_set<int> history;
      checking(nums,history,curVect,res);
      return res;
    }
};