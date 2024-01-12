#include <unordered_set>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:

    
    int uniquePaths(int m, int n) {

      if(m==1 || n==1){
        return 1;
      }

      vector<vector<int>> grid(m,vector<int>(n,0));
      for(int i = 1 ; i < n ; i++ ){
        grid[0][i] = 1;
      }
      for(int i = 1 ; i < m ; i++ ){
        grid[i][0] = 1;
      }

      for(int i = 1 ; i < m ; i++){
        for(int j = 1; j < n ; j++){
          grid[i][j] = grid[i-1][j] + grid[i][j-1];
        }
      }

      return grid[m-1][n-1];
    }

    void dfs( vector<vector<int>>& grid,int i, int j , int y , int x, int& res){
      if(i < 0 || j < 0 || i > y || j > x  ){
        return;
      }

      if(i==y && j ==x ){
        res++;
        return;
      }

      dfs(grid,i,j+1,y,x,res);
      dfs(grid,i-1,j,y,x,res);
      
      return;
    }

    int uniquePaths(int m, int n) {
      //set<pair<int,int>> st;
      vector<vector<int>> grid(m,vector<int>(n,0));
      grid[0][0] = 1;
      grid[m-1][n-1] = 1;
      //st.insert({0,0});
      //st.insert({m-1,n-1});
      int res = 0;
      dfs(grid,0,0,m-1,n-1,res);

      return res;
    }
};