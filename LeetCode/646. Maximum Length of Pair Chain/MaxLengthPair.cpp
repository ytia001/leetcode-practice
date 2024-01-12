#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
      priority_queue<vector<int>,vector<vector<int>>,greater<>> pq1;
      priority_queue<vector<int>,vector<vector<int>>,greater<>> pq2(pairs.begin(),pairs.end());
      while(!pq2.empty()){
        vector<int> next = pq2.top();
        pq2.pop();
        if(pq1.empty()){
          pq1.push({next[1],next[0]});
          continue;
        }
        vector<int> prev = pq1.top();
        if(next[0] > prev[0]){
          pq1.push({next[1],next[0]});
          continue;
        }else if(next[1]==prev[0]){
          if()
        }
      }
    }
};