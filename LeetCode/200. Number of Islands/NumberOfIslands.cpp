#include <vector>
#include <stack>

using namespace std;

class Solution {
public:

    void search(vector<vector<char>>& grid,int i ,int j){
      if(i < 0 || i > grid.size()-1 || j < 0 || j > grid[0].size()-1 || grid[i][j] != '1') return;
      grid[i][j] = '0';
      search(grid,i+1,j);
      search(grid,i-1,j);
      search(grid,i,j-1);
      search(grid,i,j+1);
      
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;

        for(int i = 0 ; i < m ; i++){
          for(int j = 0 ; j< n; j++){
            if(grid[i][j] == '1'){
              res++;
              search(grid,i,j);
            }else{
              continue;
            }
          }
        }
        return res;
    }
};