#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      int m = mat.size();
      int n = mat[0].size();
      queue<pair<int,int>> q;

      for(int i = 0; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
          if(mat[i][j]==0){
            q.push({i,j});
          }
          if(mat[i][j]!=0){
            mat[i][j]=-1;
          }
        }
      }

      vector<vector<int>> neigh = {{0,1},{-1,0},{0,-1},{1,0}};

      while(!q.empty()){
        auto coord = q.front();
        q.pop();
        for(auto i: neigh){
          int di = coord.first + i[0];
          int dj = coord.second + i[1];
          if(di<0 || dj<0 || di>=m || dj>=n ||mat[di][dj]!=-1) continue;
          mat[di][dj] = mat[coord.first][coord.second] + 1;
          q.push({di,dj});
        }
      }

      return mat;
    }
};