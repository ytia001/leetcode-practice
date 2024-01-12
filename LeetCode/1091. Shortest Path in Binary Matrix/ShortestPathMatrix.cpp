#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isZero(vector<vector<int>>& grid,int i , int j ){
      if(i<0 || i>=grid.size() || j<0 || j>=grid.size() || grid[i][j] == 1){
        return false;
      }
        return true;
    }

    void check(vector<vector<int>>& grid,int i , int j , int& res, int count ){
      if(i<0 || i>=grid.size() || j<0 || j>=grid.size()){
        return;
      }
      if(grid[i][j]==0){
        count++;
      }
      if(i==grid.size()-1 && j==grid.size()-1){
        res = max(res,count);
      }
      // check(grid,i+1,j+1,res,count);
      // check(grid,i,j+1,res,count);
      // check(grid,i+1,j,res,count);
      // check(grid,i+1,j-1,res,count);
      // check(grid,i-1,j+1,res,count);
      // check(grid,i+1,j,res,count);
      // check(grid,i,j-1,res,count);
      // check(grid,i-1,j-1,res,count);
      if(isZero(grid,i+1,j+1)){
        check(grid,i+1,j+1,res,count);
      }else if(isZero(grid,i,j+1) || isZero(grid,i+1,j)){
        check(grid,i,j+1,res,count);
        check(grid,i+1,j,res,count);
      }else if(isZero(grid,i+1,j-1) || isZero(grid,i-1,j+1)){
        check(grid,i+1,j-1,res,count);
        check(grid,i-1,j+1,res,count);
      }else if(isZero(grid,i+1,j) || isZero(grid,i,j-1)){
        check(grid,i+1,j,res,count);
        check(grid,i,j-1,res,count);
      }else{
        check(grid,i-1,j-1,res,count);
      }
      return;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      int m = grid.size();
      if(grid[0][0] != 0 && grid[m-1][m-1] != 0) return -1;
      int res = -1;
      check(grid,0,0,res,0);
      return res;
    }
};