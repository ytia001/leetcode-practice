#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> res(n,vector<int>(n,0));
      int total = n*n , current = 1;
      int firstRow = 0 , lastRow = n-1;
      int firstCol = 0 , lastCol = n-1;

      while(current<=total){
        for(int j = firstCol ; j <= lastRow && current<=total ; j++){
          res[firstRow][j] = current++;
        } 

        for(int i = firstRow + 1 ; i <= lastRow - 1 && current<=total ; i++){
          res[i][lastCol] = current++;
        } 

        for(int j = lastCol ; j >= firstCol && current<=total ; j--){
          res[lastRow][j] = current++;
        } 

        for(int i = lastRow - 1 ; i >= firstRow + 1 && current<=total ; i--){
          res[i][firstCol] = current++;
        }

        firstRow ++ , lastRow -- ;
        firstCol ++ , lastCol -- ;
      }

      return res;
    }
};