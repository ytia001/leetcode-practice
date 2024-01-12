#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int total = 0;
        int maxIdx = mat.size()-1;
        for(int i = 0 ; i<mat.size() ; i++){
          int priDiagonal = i;
          int secDiagonal = maxIdx-i;
          if(priDiagonal == secDiagonal){
            total += mat[i][priDiagonal];
            continue;
          }
          total+= mat[i][priDiagonal] + mat[i][secDiagonal];
          // total += (i!=(maxIdx-i))? (mat[i][i] + mat[i][maxIdx-i]):mat[i][i];
        }
        return total;
    }

    int answer(vector<vector<int>>& mat) {
    int res = 0;
    int n = mat.size();
    for (int i = 0; i < n; i++) {
        res += mat[i][i]; // Primary diagonals are row = column!
        res += mat[n - 1 - i][i]; // Secondary diagonals are row + column = n-1!
    }
    return n % 2 == 0 ? res : res - mat[n / 2][n / 2]; // if n is an odd number, that means we have added the center element twice!
}
};

int main(){
  vector<vector<int>> test ={{1,2,3},{4,5,6},{7,8,9}};
  //vector<vector<int>> test ={{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
  //vector<vector<int>> test = {{5}};
  Solution s;
  cout<<s.diagonalSum(test)<<endl;
  return 0;
}