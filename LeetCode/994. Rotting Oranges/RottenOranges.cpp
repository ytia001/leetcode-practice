#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int time = -1;
      int m = grid.size() , n = grid[0].size();
      queue<pair<int,int>> q;
      int freshOrange = 0;
      for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
          if(grid[i][j]==2){
            q.push({i,j});
          }
          if(grid[i][j]==1){
            freshOrange++;
          }
        }
      }

      // if no fresh orange
      if(freshOrange == 0) return 0;
      // no rotten orange but have fresh orange
      if(q.empty()) return -1; 

      vector<vector<int>> neighbourLoc = {{0,1},{1,0},{0,-1},{-1,0}};

      // fresh orange and rotten orange
      while(!q.empty()){
        int size = q.size();
        while(size-->0){
          auto loc = q.front();
          q.pop();
          for(auto& neigh : neighbourLoc ){
            int row = loc.first + neigh[0];
            int col = loc.second + neigh[1];
            if(row < 0 || col < 0 || row >= m || col >= n || grid[row][col] != 1) continue;
            freshOrange--;
            grid[row][col] = 2;
            q.push({row,col});
          }
        }
        time++;
      }

      // if still have fresh orange left
      if(freshOrange != 0) return -1;
      // All cells are either rotten oranges or empty cell
      return time;
    }
};