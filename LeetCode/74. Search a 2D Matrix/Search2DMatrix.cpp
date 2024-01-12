#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int l = 0;
      int n = matrix[0].size();
      int m = matrix.size();
      int r = n*m - 1;

      while(l<r){
        int mid = l + (r-l)/2;
        int i = mid/(n), j = mid%(n);
        if(matrix[i][j] >=target){
          r = mid;
        }else{
          l = mid + 1;  
        }
      }

      if(matrix[l/n][l%n] != target) return false;

      return true;
    }
};