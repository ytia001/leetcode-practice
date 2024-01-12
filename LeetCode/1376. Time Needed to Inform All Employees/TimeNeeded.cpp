#include <unordered_map>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:

     void dfs(int total,int& res,int startNode,unordered_map<int,vector<int>>& graph,vector<int>& checked, vector<int>& informTime){
        total += informTime[startNode];
        checked[startNode] = 0 ;
        if(!graph.count(startNode)){
          res = max(res,total);
          return;
        }
        for(auto i: graph[startNode]){
          if(checked[i]==1){
            dfs(total,res,i,graph,checked,informTime);
          }
        }
     }

     int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res = 0;
        vector<int> checked(n,1);
        unordered_map<int,vector<int>> graph;
        for(int i = 0 ; i<manager.size();i++){
          if(manager[i]==-1) continue;
          graph[manager[i]].push_back(i);
        }
        dfs(0,res,headID,graph,checked,informTime);
        return res;
    }


    // int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    //     int res = 0;
    //     if(n==1) return informTime[0];
    //     deque<int> calling;
    //     unordered_map<int,deque<int>> graph;
    //     for(int i = 0 ;  i<manager.size();i++){
    //       if(manager[i]==-1) continue;
    //       graph[manager[i]].push_front(i);
    //     }

    //     calling.push_front(headID);

    //     while(!calling.empty()){
    //       deque<int> copy = calling;
    //       calling.clear();
    //       res++;
    //       while(!copy.empty()){
    //         int current = copy.front();
    //         copy.pop_front();

    //         if(--informTime[current]>0){
    //           calling.push_front(current);
    //           continue;
    //         }
    //         //res += informTime[current];
    //         while(!graph[current].empty()){
    //            if(graph.count(graph[current].front())!=0){
    //             calling.push_front(graph[current].front());
    //           }
    //           graph[current].pop_front();
    //         }
    //       }
    //     }
    //     return res;
    // }
};