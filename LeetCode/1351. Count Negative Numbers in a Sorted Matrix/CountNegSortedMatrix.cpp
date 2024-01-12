#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
      int res = 0;
      int n = grid[0].size();
      int m = grid.size();
      int row = m-1;
      int col = 0;
      while(row>=0 && col<=n-1){
        if(grid[row][col]>=0){
          col++;
        }else{
          res += n-col;
          row--;
        }
      }
      return res;
    }
};