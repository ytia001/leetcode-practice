# include <vector>

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
      int res = 0;

      for(int i = 0; i < mat.size() ; i++){
        for(int j = 0 ; j < mat[0].size(); j++){
          if(mat[i][j]){
            int count = check(mat,i,j);
            res += count;
          }
        }
      }

      return res;
    }

    int check(vector<vector<int>>& mat,int i , int j){
      for(int k = 0; k < mat[0].size() ; k++){
        if(k == j) continue;
        if(mat[i][k]){
          return false;
        }
      }

      for(int k = 0; k < mat.size() ; k++){
        if(k == i) continue;
        if(mat[k][j]){
          return false;
        }
      }

      return 1;
    }
};