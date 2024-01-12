#include <queue>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& graph,vector<int>& checked,int startNode){
      checked[startNode]=0;
      for(auto i : graph[startNode]){
        if(checked[i]){
          dfs(graph,checked,i);
        }
      }
      return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
       unordered_map<int,vector<int>> graph;
       int size = isConnected.size();
       int res = 0;
       vector<int> checked(size,1);
        for(int i = 0 ; i < isConnected.size() ; i++){
          for(int j= 0 ; j<isConnected[i].size() ; j++){
            if(i==j || isConnected[i][j] == 0) continue;
            graph[i].push_back(j);
          }
        }

        for(int i = 0 ; i < size ; i++){
          if(checked[i]!=0){
            dfs(graph,checked,i);
            res ++;
          }
        }
      return res;
    }

    //  int findCircleNum(vector<vector<int>>& isConnected) {
    //    int res = 0;
    //    vector<int> checked(isConnected.size(),1);
    //    queue<int> toCheck;
    //     for(int i = 0 ; i < isConnected.size() ; i++){
    //       if(checked[i]==0) continue;
    //       // checked[i]=0;
    //       toCheck.push(i);
    //       // for(int j= 0 ; j<isConnected.size(); j++){
    //       //   if(i==j || checked[j]==0) continue;
    //       //   if(isConnected[i][j]==1){
    //       //     checked[j]=0;
    //       //   }
    //       // }
    //       while(toCheck.empty()){
    //         int startNode = toCheck.front();
    //         toCheck.pop();

    //       }
    //       res++;
    //     }
    //   return res;
    // }
};

int main(){
  Solution s;
  vector<vector<int>> test = {{1,1,0},{1,1,0},{0,0,1}};
  cout<<s.findCircleNum(test)<<endl;
  return 0;
}