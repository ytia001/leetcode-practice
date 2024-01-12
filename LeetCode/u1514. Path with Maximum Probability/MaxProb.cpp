#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:


    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
      unordered_set<int> track;
      //track.insert(start);
      unordered_map<int,unordered_map<int,double>> graph;
      queue<pair<int,int>> q;
      q.push({start,1});
      double res = 0;
      for(int i = 0 ; i < edges.size() ; i++){
          graph[edges[i][0]][edges[i][1]] = succProb[i];
          graph[edges[i][1]][edges[i][0]] = succProb[i];
      }
      
      while(!q.empty()){
        auto k = q.front();
        q.pop();
        if(!track.count(k.first)){
          track.insert(k.first);
          for(auto i : graph[k.first]){
            if(i.first==end){
              res = max(res,k.second*i.second);
            }else if(!track.count(i.first)){
              q.push({i.first,k.second*i.second});
            }
          }
        }
      }

      return res;
    }




    // void dfs(pair<const int,double> node,unordered_map<int,unordered_map<int,double>>& graph, unordered_set<int> previous,double& res, double current,int start, int end ){
    //   if(previous.count(node.first)) return;
    //   if(node.first==end){
    //     res = max(res,current*node.second);
    //     return;
    //   }
    //   previous.insert(node.first);
    //   current *= node.second;
    //   for(auto k : graph[node.first] ){
    //     dfs(k,graph,previous,res,current,start,end);
    //   }
    // }


    // double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    //     unordered_map<int,unordered_map<int,double>> graph;
    //     for(int i = 0 ; i < edges.size() ; i++){
    //       graph[edges[i][0]][edges[i][1]] = succProb[i];
    //       graph[edges[i][1]][edges[i][0]] = succProb[i];
    //     }
    //     double res = 0;
    //     unordered_set<int> previous;
    //     previous.insert(start);
    //     for(auto k : graph[start]){
    //       dfs(k,graph,previous,res,1,start,end);
    //     }

    //     return res;
    // }
};