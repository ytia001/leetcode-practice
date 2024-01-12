#include <vector>
#include <unordered_set>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      if(graph.empty()) return { };
      unordered_set<int> termNode;
      unordered_set<int> visited;
      vector<int> res;
      queue<int> q;
      q.push(0);
      visited.insert(0);

      for(int i = 0 ; i < graph.size() ; i++){
        int node = q.front(); q.pop();
        bool isTerm = true;

        for(int neighbour : graph[node]){
          if(visited.count(neighbour)) continue;
          visited.insert(neighbour);
          // cout<<node<<" "<<graph[neighbour].size()<<endl;
          if(graph[neighbour].empty()){
            termNode.insert(neighbour);
          }else{
            isTerm = false;
          }
          cout<<"neighbour  "<<neighbour<<endl;
          q.push(neighbour);
        }

        //cout<<node<<"   "<<isTerm<<endl;
        if(isTerm) res.push_back(node);

      } 

      // for(auto i : termNode){
      //  res.push_back(i);
      // }
      return res;
    }
};