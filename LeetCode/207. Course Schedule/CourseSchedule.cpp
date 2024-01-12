#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:

    bool dfs(unordered_map<int,vector<int>>& graph,int startNode, unordered_set<int>& check,unordered_set<int> curPoints){
      bool res = true;
      if(check.count(startNode)){
        return res;
      }
      check.insert(startNode);     
      curPoints.insert(startNode);
      for(auto i : graph[startNode]){
        if(curPoints.count(i)) return false;
        res = dfs(graph,i,check,curPoints);
        if(!res) break;
      }
      return res;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<int> courses(numCourses,1);
      unordered_map<int,vector<int>> graph;
      unordered_set<int> curPoints;
      unordered_set<int> check;

      for(auto i : prerequisites){
        graph[i[1]].push_back(i[0]);
      }

      for(int i = 0 ; i < numCourses ; i++){
        if(check.count(i)) continue;
        // check.insert(i);
        if(!dfs(graph,i,check,curPoints)){
          return false;
        }
      }
      return true;
    }


    // bool canFinishTest(int numCourses, vector<vector<int>>& prerequisites) {
    //   int total = 0;
    //   vector<int> courses(numCourses,1);
    //   unordered_map<int,vector<int>> graph; 
    //   unordered_set<int> checked;
    //   queue<int> q;
    //   for(auto i : prerequisites){
    //     graph[i[1]].push_back(i[0]);
    //   }
    //   for(int i = 0 ; i < numCourses ; i++){
    //     unordered_set<int> currentCheck;
    //     q.push(i);
    //     while(!q.empty()){
    //       int currentNode = q.front();
    //       currentCheck.insert(currentNode);
    //       q.pop();
    //       for(int i : graph[currentNode]){
    //         if(currentCheck.count(i)) return false;
    //         if(!checked.count(i)){
    //           q.push(i);
    //         }
    //       }
    //     }
    //     checked.insert(i);
    //   }
    //   return true;
    // }
};