#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if(intervals.empty()) return {newInterval};
        int start = newInterval[0], end = newInterval[1];
        bool ended = false;
        for(int i = 0 ;  i < intervals.size() ; i++){
          if(intervals[i][1] < newInterval[0] || intervals[i][0] > newInterval[1]){
            if(ended) {
              res.push_back({start,end});
              ended = false;
              }
            res.push_back(intervals[i]);
          }else{
            ended = true;
            if(newInterval[0]>intervals[i][0]){
              start = intervals[i][0];
            }
            if(newInterval[1]<intervals[i][1]){
              end = intervals[i][1];
            }
          }
        }
        if(ended) res.push_back({start,end});
        return res;
    }

    int binarySearch(vector<vector<int>>& intervals, int target){
      int l = 0;
      int r = intervals.size()-1;
      while(l<r){
        int mid = l + (r-l+1)/2;
        if(intervals[mid][0] <= target && intervals[mid][1] >= target){
          return mid;
        }else if(intervals[mid][0]>target){
          r = mid-1;
        }else if(intervals[mid][1]>target){
          l = mid;
        }
      }
      return l;
    }


    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      vector<vector<int>> res;
      int l = binarySearch(intervals,newInterval[0]);
      int r = binarySearch(intervals,newInterval[1]);
      int start,end;
      cout<<"l: "<<l<<" r: "<<r<<endl;
      for(int i = 0 ; i < intervals.size() ; i++){
        if(i==l){
          if(newInterval[0]<intervals[l][0]){
            start = newInterval[0];
          }else{
            start = intervals[l][0];
          }

          if(newInterval[1]>intervals[r][1]){
            end = newInterval[1];
          }else{
            end = intervals[r][1];
          }
          //cout<<"start: "<<start<<endl;
          res.push_back({start,end});
        }
        else if(i>l && i<=r){
          continue;
        }else{
          //cout<<"dsf"<<endl;
          res.push_back(intervals[i]);
        }
      }
      return res;
      }

    



    // vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    //   vector<vector<int>> res;
    //   int start = -1, end = -1;
    //   for(auto& i : intervals){
    //     if(i[0] < newInterval[0] && i[1] < newInterval[0]){
    //       res.push_back(i);
    //       continue;
    //     }
        
    //     if(i[0] < newInterval[0] && i[1] < newInterval[0]){
    //       if(i[0]>=newInterval[0]){
    //         start = newInterval[0];
    //       }else{
    //         start = i[0];
    //       }
    //     }

    //     if(i[0] < newInterval[0] && i[1] < newInterval[0]){
    //       if(i[0]>=newInterval[0]){
    //         start = newInterval[0];
    //       }else{
    //         start = i[0];
    //       }
    //     }
    //   }  
    // }
};

int main(){

  Solution s;
  vector<vector<int>> test = {{1,5}};
  vector<int> interval = {2,3};
  vector<vector<int>> result = s.insert(test,interval);
  for(auto i : result){
    cout<<i[0]<<"-----"<<i[1]<<endl;
  }
  return 0;
}