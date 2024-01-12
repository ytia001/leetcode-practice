#include <queue>
#include <set>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <functional>

using namespace std;


class Solution {
private:
    set<int> setA, setB;
    bool error;
public:

    bool Answer(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n); // 0: uncolored; 1: color A; -1: color B
        
    queue<int> q; // queue, resusable for BFS    
	
    for (int i = 0; i < n; i++) {
      if (color[i]) continue; // skip already colored nodes
      
      // BFS with seed node i to color neighbors with opposite color
      color[i] = 1; // color seed i to be A (doesn't matter A or B) 
      for (q.push(i); !q.empty(); q.pop()) {
        int cur = q.front();
        for (int neighbor : graph[cur]) 
		{
          if (!color[neighbor]) // if uncolored, color with opposite color
          { color[neighbor] = -color[cur]; q.push(neighbor); } 
		  
          else if (color[neighbor] == color[cur]) 
            return false; // if already colored with same color, can't be bipartite!
        }        
      }
    }
    
    return true;
  }

    void dfs(vector<vector<int>>& graph,vector<bool>& visited, int node , bool isA = true ){
      visited[node] = true;
      if(isA){
        setA.insert(node);
      }else{
        setB.insert(node);
      }
      isA = !isA;
      for(auto i: graph[node]){
        if(!visited[i]){
          dfs(graph,visited,i,isA);
        }else{
          if(isA && setB.count(i)){
            error = true;
          }else if (!isA && setA.count(i)){
            error = true;
          }
        }
      }
      return;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        error = false;
        int n = graph.size();
        vector<bool> visited(n,false);
        for(int i = 0 ; i < n ; i++){
          if(!visited[i]){
            dfs(graph,visited,i,true);
            if(error) return false;
          }
        }

        return true;
    }

    bool isBipartiteTest2(vector<vector<int>>& graph) {
        bool error = false;
        set<int> setA, setB;
        int n = graph.size();
        vector<bool> visited(n,false);

        function<void(int, bool)> dfs;

        dfs = [&](int node , bool isA = true ){
          visited[node] = true;
          if(isA){
            setA.insert(node);
          }else{
            setB.insert(node);
          }
          isA = !isA;
          for(auto i: graph[node]){
            if(!visited[i]){
              dfs(i,isA);
            }else{
              if(isA && setB.count(i)){
                error = true;
              }else if (!isA && setA.count(i)){
                error = true;
              }
            }
          }
          return;
        };

        for(int i = 0 ; i < n ; i++){
          if(!visited[i]){
            dfs(i,true);
            if(error) return false;
          }
        }

        return true;
    }

    bool isBipartiteTest(vector<vector<int>>& graph) {
        int n = graph.size();
        int isA = true; 
        unordered_map<int,set<bool>> container;

        for(int i = 0 ; i < n ; i++){
          container[i].insert(isA);
          isA = !isA;
          for(int k : graph[i]){
            container[k].insert(isA);
          }
        }

        for(auto k : container){
          if(k.second.size()==2){
            return false;
          }
        }

        return true;
    }
};

int main(){
  //vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
  vector<vector<int>> graph = {{1},{0,3},{3},{1,2}};
  Solution s;
  s.isBipartite(graph) ? cout<<"true"<<endl : cout<<"False"<<endl;
  return 0;
}