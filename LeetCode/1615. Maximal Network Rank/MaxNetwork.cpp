#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
      vector<int> neigh(n,0);
      vector<vector<int>> connect(n,vector<int>(n,0));
      //set<vector<int>> st(roads.begin(),roads.end());
      for(int i = 0 ; i < roads.size() ; i++){
        neigh[roads[i][0]]++;
        neigh[roads[i][1]]++;
        connect[roads[i][0]][roads[i][1]]=1;
        connect[roads[i][1]][roads[i][0]]=1;
      }

      int res = INT_MIN;

      for(int i = 0 ; i < neigh.size()-1 ; i++){
        for(int j = i + 1; j < neigh.size() ; j++){
          int current = neigh[i]+neigh[j];
          if(connect[i][j] || connect[j][i]){
            current--;
          }
          if(current > res) res = current;
        }
      }

      return res; 
    }

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
      vector<int> neigh(n,0);
      set<vector<int>> st(roads.begin(),roads.end());
      for(int i = 0 ; i < roads.size() ; i++){
        neigh[roads[i][0]]++;
        neigh[roads[i][1]]++;
      }

      int res = INT_MIN;
      int l = 0 , r = neigh.size()-1;

      // int fr = 0 , sc = 1;
      // int res = neigh[fr]+neigh[sc];
      // if(st.count({fr,sc})|| st.count({sc,fr})){
      //   res--;
      // }

      // for(int i = 2 ; i < neigh.size() ; i++){
      //   int cur1 = neigh[i]+neigh[sc];
      //   if(st.count({i,sc})|| st.count({sc,i})){
      //     cur1--;
      //   }
      //   int cur2 = neigh[fr]+neigh[i];
      //   if(st.count({fr,i})|| st.count({i,fr})){
      //     cur2--;
      //   }

      //   if(cur1>res || cur2>res){
      //     if(cur1>=cur2){
      //       res = cur1;
      //       fr = i;
      //     }else{
      //       res = cur2;
      //       sc = i;
      //     }
      //   }
      // }

      while(l<r){
        int current = neigh[l] + neigh[r];
        if(st.count({l,r})|| st.count({r,l})){
         current--;
        }

        res = max(res,current);
        if(neigh[l] >= neigh[r]){
          r--;
        }else{
          l++;
        }
      }

      return res; 
    }

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
      vector<int> neigh(n,0);
      set<vector<int>> st(roads.begin(),roads.end());
      for(int i = 0 ; i < roads.size() ; i++){
        neigh[roads[i][0]]++;
        neigh[roads[i][1]]++;
      }

      int res = INT_MIN;

      for(int i = 0 ; i < neigh.size()-1 ; i++){
        for(int j = i + 1; j < neigh.size() ; j++){
          int current = neigh[i]+neigh[j];
          if(st.count({i,j})|| st.count({j,i})){
            current--;
          }
          if(current > res) res = current;
        }
      }

      return res; 
    }
};