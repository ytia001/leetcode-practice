#include <vector>

using namespace std;

class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();
      vector<vector<int>> obstacles(m,vector<int>(n,0));

      for(int i = 0 ; i < m ; i++){
          for(int j = 0 ; j < n; j++){
            if(obstacleGrid[i][j] == 1){
              obstacles[i][j] = 1;
              continue;
            }

            if(i == 0 || j ==0 ){
              obstacleGrid[i][j] = 1;
            }

          }
      }

      for(int i = 1 ; i < m; i++){
          for(int j = 1 ; j < n; j++){
            if(obstacles[i][j]== 1){
              obstacleGrid[i][j]=0;
              continue;
            }
            obstacleGrid[i][j] = (obstacles[i-1][j] ? 0 : obstacleGrid[i-1][j]) + (obstacles[i][j-1] ? 0 : obstacleGrid[i][j-1]);
          }
        }

        return obstacleGrid[m-1][n-1];
    }


   int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();
        for(int i = 0 ; i < m ; i++){
          for(int j = 0 ; j < n; j++){
            if(obstacleGrid[i][j] == 1){
              obstacleGrid[i][j] = -1;
              continue;
            }

            if(i == 0 || j ==0 ){
              obstacleGrid[i][j] = 1;
            }

          }
        }

        // for(int i = 0 ; i < m ; i++){
        //   for(int j = 0 ; j < n ; j++){
        //     cout<<obstacleGrid[i][j]<<" ";
        //   }
        //   cout<<endl;
        // }

        for(int i = 1 ; i < m; i++){
          for(int j = 1 ; j < n; j++){
            if(obstacleGrid[i][j]==-1){
              obstacleGrid[i][j]=0;
              continue;
            }
            obstacleGrid[i][j] = (obstacleGrid[i-1][j] != -1? obstacleGrid[i-1][j] : 0 ) + (obstacleGrid[i][j-1] != -1? obstacleGrid[i][j-1] : 0 );
            //cout<<"obsatcleGrid[i][j]: "<<obstacleGrid[i][j]<<endl;
          }
        }

        return obstacleGrid[m-1][n-1];
    }
};