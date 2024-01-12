#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:

    int dfs(vector<vector<int>>& mat,int i,int j,int count){
      if( i < 0 || j < 0 || i > mat.size()-1 || j > mat[0].size()-1) {
        return INT_MIN;
      } 
      if(mat[i][j] < 0) return count;
      mat[i][j] = -mat[i][j];
      mat[i][j] -= max({dfs(mat,i-1,j,count+1),dfs(mat,i+i,j,count+1),dfs(mat,i,j+1,count+1),dfs(mat,i,j-1,count+1)});
      return mat[i][j];
    }

    void check(vector<vector<int>>& mat,int i,int j){
      if(i-1<0 || j-1<0 || i+1 >= mat.size() || j+1 >= mat[0].size() || mat[i][j]!=0) return;
      if(mat[i-1][j] == 1) mat[i-1][j] = -1;
      if(mat[i+1][j] == 1) mat[i+1][j] = -1;
      if(mat[i][j-1] == 1) mat[i][j-1] = -1;
      if(mat[i][j+1] == 1) mat[i][j+1] = -1;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      int m = mat.size();
      int n = mat[0].size();
      for( int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
          check(mat,i,j);
        }
      }

      for( int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
          if(mat[i][j]>0){
            dfs(mat,i,j,0);
          }
        }
      }
      return mat;
    }
};