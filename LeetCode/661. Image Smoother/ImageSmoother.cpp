# include <vector>

using namespace std;

class Solution {
public:

    int calculate(vector<vector<int>>& img, int i , int j){
      vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1}};
      int total = 0 , count = 0;
      for(const auto& [di,dj] : dir){
        int i_n = i + di , j_n  = j + dj;
        if(i_n < 0 || i_n > img.size() || j_n < 0 || j_n > img[0].size()) continue;
        total += img[i_n][j_n];
        count ++;
      }

      return total/count;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
      int m = img.size() , n = img[0].size();
      vector<vector<int>> res(m,vector<int>(n,0));

      for(int i = 0 ; i < img.size() ; i++){
        for(int j = 0 ; j < img[0].size() ; j++){
          res[i][j] = calculate(img,i,j); 
        }
      }  
      return res;
    }
};