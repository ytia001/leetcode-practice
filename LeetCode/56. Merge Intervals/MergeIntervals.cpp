#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    static bool comparator(vector<int>& a, vector<int>& b){
      return a[0]<b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(),intervals.end(),comparator);   
      vector<vector<int>> res;
      int curMin = intervals[0][0];
      int curMax = intervals[0][1];
      for(int i = 1; i < intervals.size() ; i++){
        if(intervals[i][0] <= curMax || intervals[i][1] <= curMax){
          curMin = min(curMin,intervals[i][0]);
          curMax = max(curMax,intervals[i][1]);
        }else{
          res.push_back({curMin,curMax});
          curMin = intervals[i][0];
          curMax = intervals[i][1];
        }
      }
      res.push_back({curMin,curMax});
      return res;
    }
};