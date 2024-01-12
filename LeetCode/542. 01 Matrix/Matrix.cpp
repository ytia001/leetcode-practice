#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& mat, int i , int j , int dist,unordered_map<int,unordered_set<int>> matMap){
      if(i>=mat.size() || i<0|| j>=mat[0].size() || j<0){
        //cout<<"i: "<<i<<" j: "<<j<<endl;
        return INT_MAX;
      }
      
      if(matMap[i].count(j)==0){
        matMap[i].insert(j);
      }else{
        if(mat[i][j]==0){
        return dist;
        }
        return INT_MAX;
      }
      
          

      //cout<<"i: "<<i<<" j: "<<j<<endl;  
      if(mat[i][j]==0){
        return dist;
      }

      int up = dfs(mat,i-1,j,dist+1,matMap);
      int down = dfs(mat,i+1,j,dist+1,matMap);
      int left = dfs(mat,i,j-1,dist+1,matMap);
      int right = dfs(mat,i,j+1,dist+1,matMap);

      cout<<"left: "<<left<<" right: "<<right<<" up: "<<up<<" down: "<<down<<endl;

      return min({up,down,left,right});
      
    }


     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size() , n = mat[0].size();
        vector<vector<int>> res(m,vector<int>(n));
        for(int i = 0 ; i < m ; i++){
          for(int j = 0 ; j < n ; j++){
            if(mat[i][j] == 0){
              res[i][j] == 0;
              continue;
            }
            unordered_map<int,unordered_set<int>> matMap;
            cout<<"i: "<<i<<" j: "<<j<<endl;
            res[i][j] = dfs(mat,i,j,0,matMap);
          }
        }

        return res;
    }


    vector<vector<int>> updateMatrixTest(vector<vector<int>>& mat) {
        int m = mat.size() , n = mat[0].size();
        // int res[m][n];
        vector<vector<int>> res(m,vector<int>(n));
        for(int i = 0 ; i < m ; i++){
          for(int j = 0 ; j < n ; j++){
            if(mat[i][j] == 0){
              // cout<<"1"<<endl;
              res[i][j] == 0;
            }
            else if(i==0){
              //res[i][j] = mat[i][j] + min(mat[i][max(0,j-1)],mat[i][min(mat[0].size()-1,j+1)]);
              // cout<<"2"<<endl;
              res[i][j] = mat[i][j] + min(mat[i][max(0,j-1)],mat[i][min(n-1,j+1)]);
            }else if(j==0){
              // cout<<"3"<<endl;
              res[i][j] = mat[i][j] + min(mat[max(0,i-1)][j],mat[min(m-1,i+1)][j]);
            }else{
              // cout<<"4"<<endl;
              // cout<<"i: "<<i<<" j: "<<j<<endl;
              res[i][j] = mat[i][j] + min(mat[i-1][j],mat[i][j-1]);
              // cout<<"done"<<endl;
            }
          }
        }

        return res;
    }
};

int main(){
  Solution s;
  vector<vector<int>> mat = {{0,1,0,1,1},{1,1,0,0,1},{0,0,0,1,0},{1,0,1,1,1},{1,0,0,0,1}};
  vector<vector<int>> res = s.updateMatrix(mat);
  for(auto i : res){
    for(auto j : i){
      cout<<j<<" ";
    }
    cout<<endl;
  }
  return 0;
}