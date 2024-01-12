#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>& image,int target,int i ,int j){
      if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != target) return;
      image[i][j] = -1;
      dfs(image,target,i+1,j);
      dfs(image,target,i-1,j);
      dfs(image,target,i,j+1);
      dfs(image,target,i,j-1);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      int startPixel = image[sr][sc];
      dfs(image,startPixel,sr,sc);
      for(int i = 0 ; i < image.size() ; i++){
        for(int j = 0 ; j < image[0].size() ;j++){
          if(image[i][j]==-1) image[i][j] = color;
        }
      }
      return image;
    }
};