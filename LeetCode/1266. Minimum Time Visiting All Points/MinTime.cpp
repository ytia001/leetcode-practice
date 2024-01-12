#include <vector>

using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
      int hp = points[0][0] , vp = points[0][1];
      int steps = 0;

      for(int i = 1 ; i < points.size() ; i++){
        int hDist = abs(points[i][0] - hp);
        int vDist = abs(points[i][1] - vp);
        int diagonal = min (hDist,vDist);

        steps += (diagonal + (hDist-diagonal) + (vDist-diagonal));
        
        hp = points[i][0];
        vp = points[i][1];
  
      }

      return steps;
    }
};