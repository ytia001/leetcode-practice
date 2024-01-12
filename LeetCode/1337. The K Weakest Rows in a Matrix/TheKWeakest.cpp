#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    struct Compare{
      bool operator()(const pair<int,int>& a, const pair<int,int>& b){
        if(a.first!=b.first){
          return a.first > b.first;
        }
          return a.second > b.second;
      }
    };

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
        for(int i = 0; i < mat.size() ; i++){
          int oneCount = 0;
          for(int j = 0 ; j < mat[0].size() ; j++){
            if(mat[i][j]) oneCount++;
          }
          pq.push({oneCount,i});
          if(pq.size() > k) pq.pop();
        }

        while(pq.size()){
          res.push_back(pq.top().second);
          pq.pop();
        }


       return vector<int>(res.rbegin(),res.rend());
    }


    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<>> pq;
        for(int i = 0; i < mat.size() ; i++){
          int oneCount = 0;
          for(int j = 0 ; j < mat[0].size() ; j++){
            if(mat[i][j]) oneCount++;
          }
          pq.push({oneCount,i});
          if(pq.size() > k){
            pair<int,int> toRemove = pq.top();
            pq.pop();
            if(toRemove.first == pq.top().first && toRemove.second < pq.top().second){
              pq.pop();
              pq.push(toRemove);
            }
          }
        }

        while(pq.size()){
          res.push_back(pq.top().second);
          pq.pop();
        }


      return vector<int>(res.rbegin(),res.rend());
    }

};