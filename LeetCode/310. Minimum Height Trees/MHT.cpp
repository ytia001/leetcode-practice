#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:

    int bfs(vector<vector<int>>& graph,int root){
      int depth = -1;
      queue<int> q;
      unordered_set<int> history;
      q.push(root);
      history.insert(root);
      
      while(!q.empty()){
        depth++;
        int size = q.size();
        while(size-->0){
          int curNode = q.front();
          q.pop();
          for(auto neigh : graph[curNode]){
            if(!history.count(neigh)){
              history.insert(neigh);
              q.push(neigh);
            }
          }
        }
        //if(!q.empty()) depth++;
      }
      return depth;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
      int minHeight = INT_MAX;
      vector<int> res;

      vector<vector<int>> graph(n);
      for(auto& edge: edges){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
      }

      for(int i = 0 ; i < n ; i++){
        int rootDepth = bfs(graph,i);
        if(rootDepth < minHeight){
          res.clear();
          res.push_back(i);
          minHeight = rootDepth;
        }
        else if(rootDepth == minHeight){
          res.push_back(i);
        }
      }

      return res;
    }
};