# include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
      int m = matrix.size();
      int n = matrix[0].size();
      vector<vector<int>> res(n,vector<int>(0,m));

      for(int j = 0 ; j < n ; j++){
        for(int i = 0 ; i < m ; i ++){
          res[j][i] = matrix[i][j];
        }
      }

      return res;
    }
};