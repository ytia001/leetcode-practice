#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> res;
      res.push_back({});
      for(int i = 0 ; i < nums.size() ; i++){
        vector<vector<int>> copy = res;
        transform(copy.begin(),copy.end(),back_inserter(res),[i,nums](vector<int> a){
           a.push_back(nums[i]);
           return a;});
      }
      return res;
    }


    vector<vector<int>> subsets1(vector<int>& nums) {
      vector<vector<int>> res;
      res.push_back({});
      //queue<vector<int>> q;
      //q.push({nums[0]});
      //q.push({});
      for(int i = 0 ; i < nums.size() ; i++){
        vector<vector<int>> copy = res;
        while(!copy.empty()){
          vector<int> vect = copy.back();
          vect.push_back(nums[i]);
          copy.pop_back();
          res.push_back(vect);
        }
      }
      return res;
    }
};