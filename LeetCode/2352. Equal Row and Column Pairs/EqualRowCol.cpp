#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:

    int equalPairs(vector<vector<int>>& grid) {
      //map<vector<int>,int> colMap;
      //unordered_map<vector<int>,int> colMap;
      // for(int i = 0 ; i < grid.size() ; i++){
      //   for(int j = 0 ; j < grid[0].size() ; j++){
      //     colMap[j].push_back(grid[i][j]);
      //   }
      // }
      int res = 0;
      for(int i = 0 , j = 0; i < grid.size() ; i++){
        vector<int> currentCol;
        while(j<grid.size()){
          currentCol.push_back(grid[j][i]);
          j++;
        }
        j = 0;
        res += count(grid.begin(),grid.end(),currentCol);
      }
      // for(int i = 0 ; i < grid.size() ; i++){
      //   vector<int> currentCol;
      //   for(int j = 0 ; j <grid.size() ; j++){
      //     currentCol.push_back(grid[j][i]);
      //     j++;
      //   }
      //   res += count(grid.begin(),grid.end(),currentCol);
      // }
      return res;
    }
};