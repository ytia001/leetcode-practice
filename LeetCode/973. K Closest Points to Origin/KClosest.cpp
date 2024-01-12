#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


class Solution {
public:

    // static bool comparator(vector<int>& a, vector<int>&b){
    //   return (a[0]*a[0])+(a[1]*a[1]) < (b[0]*b[0])+(b[1]*b[1]);
    // }


    //  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    //     priority_queue<vector<int>,vector<vector<int>>,less<>> pq;
    //     sort(points.begin(),points.end(),comparator);
    //     return vector<vector<int>>(points.begin(),points.begin()+k);
    // }

    struct comparator{
      bool operator()(const vector<int>& a , const vector<int>& b){
        return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
      }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,comparator> pq;
        vector<vector<int>> res;
        for(int i = 0 ; i < points.size() ; i++){
          int sq = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
          // if(pq.size()<k){
          //   pq.push({sq,points[i][0],points[i][1]});
          // }else{
          //   if(sq<pq.top()[0]){
          //     pq.pop();
          //     pq.push({sq,points[i][0],points[i][1]});
          //   }
          // }

          // if(pq.size()==k){
          //   pq.push({sq,points[i][0],points[i][1]});
          //   pq.pop();
          // }else{
          //   pq.push({sq,points[i][0],points[i][1]});
          // }

          pq.push({sq,points[i][0],points[i][1]});
          if(pq.size()>k) pq.pop();

        }

        while(!pq.empty()){
          res.push_back({pq.top()[1],pq.top()[2]});
          pq.pop();
        }

        return res;
    }
};