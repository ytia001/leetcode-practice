#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:

    double dist(vector<int>& a , vector<int>& b){
      double y_dist = pow(b[1]-a[1],2);
      double x_dist = pow(b[0]-a[0],2);
      // cout<<"y_dist"<<y_dist<<endl;
      // cout<<"x_dist"<<x_dist<<endl;
      // cout<<sqrt(y_dist+x_dist)<<endl;
      return sqrt(y_dist+x_dist);
    }

    // void dfs(unordered_map<int,vector<int>>& bombMap,vector<int>& checked, int startBomb, int& res, int current){
    //   checked[startBomb] = 1;
    //   for(auto i : bombMap[startBomb]){
    //     if(checked[i]!= 1){
    //       dfs(bombMap,checked,i,res,++current);
    //     }
    //   }
    //   res = max(res,current);
    // }

    int maximumDetonation(vector<vector<int>>& bombs) {
      unordered_map<int,vector<int>> bombMap;
      queue<int> q;
      for(int i = 0 ; i < bombs.size() ; i++){
        for(int j = 0 ; j < bombs.size(); j++){
          if(i==j) continue;
          if(dist(bombs[i],bombs[j])<=bombs[i][2]){
            // cout<<"dsfds"<<endl;
            // cout<<"i: "<<i<<" j:"<<j<<endl;
            bombMap[i].push_back(j);
          }
        }
      }
      // for(auto i : bombMap){
      //   cout<<i.first<<endl;
      //   for(auto j : i.second){
      //     cout<<j<<" ";
      //   }
      //   cout<<endl;
      // }
      int res = 0 ; 
      for(int i = 0 ; i < bombs.size() ; i++){
        int count = 0;
        // if(checked[i]==1){
        //   continue;
        // }
        q.push(i);
        vector<int> checked(bombs.size(),0);
        checked[i] = 1;
        while(!q.empty()){
          int currentBomb = q.front();
          q.pop(); 
          count++;
          //cout<<"i: "<<i<<" currentBomb: "<<currentBomb<<" count: "<<count<<endl;
          for(auto i : bombMap[currentBomb]){
            if(checked[i]!=1){
              checked[i] = 1;
              q.push(i);
            }
          }
        }
        res = max(res,count);
      }

      return res;
    }
};

int main(){

  Solution s;
  // vector<vector<int>> bombs = {{2,1,3},{6,1,4}};
  vector<vector<int>> bombs = {{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}};
  cout<<s.maximumDetonation(bombs)<<endl;  
  return 0;
}