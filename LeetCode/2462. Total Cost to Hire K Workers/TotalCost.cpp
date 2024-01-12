#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
      long long res = 0;
      int l = 0;
      int r = costs.size()-1;
      priority_queue<pair<int,char>,vector<pair<int,char>>,greater<>> pq;
      for(int i = 0 ; i<k ; i++){
        if(l>=r) break;
        pq.push({costs[l++],'l'});
        pq.push({costs[r--],'r'});
      }
      for(int i = 0 ; i < k ; i++){
        auto k = pq.top();
        pq.pop();
        res += k.first;
        if(k.second=='l' && r-l>1){
          pq.push({costs[++l],'l'});
        }else if(k.second=='r' && r-l>1){
          pq.push({costs[--r],'r'});
        }else{
          continue;
        }
      }
      return res;
    }
};