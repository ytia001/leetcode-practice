#include <vector>

using namespace std;

class Solution {
public:

    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> res(numRows);
      res[0] = {1};
      if(numRows > 1) res[1] = {1,1};
      for(int i = 2 ; i < numRows ; i++){
        res[i].push_back(1);
        for(int j = 0 ; j < res[i-1].size()-1 ; j++){
          res[i].push_back(res[i-1][j] + res[i-1][j+1]);
        }
        res[i].push_back(1);
      }

      return res;
    }


    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> res(numRows);
      res[0] = {1};
      if(numRows > 1) res[1] = {1,1};
      for(int i = 2 ; i < numRows ; i++){
        vector<int> current = {1};
        vector<int> prev = res[i-1];
        for(int j = 0 ; j < prev.size()-1 ; j++){
          current.push_back(prev[j] + prev[j+1]);
        }
        current.push_back(1);
        res[i] = current;
      }

      return res;
    }
};