#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    static bool comparator ( const vector<int>& a , const vector<int>& b){
      return (a[0]==b[0]) ? (a[1]<b[1]) : (a[0] < b[0]);
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      if(intervals.size()==1) return 0;
      int res = 0;
      sort(intervals.begin(),intervals.end(),comparator);
      int minVal = intervals[0][0], maxVal = intervals[0][1];

      for(int i = 1 ; i < intervals.size() ; i++){
        //if(intervals[i][0] < max || intervals[i][1] < max)
        if(intervals[i][0] < maxVal){
          res++;
        }else{
          minVal = min(minVal,intervals[i][0]);
          maxVal = max(maxVal,intervals[i][1]);
        }
      }

      return res;
    }
};