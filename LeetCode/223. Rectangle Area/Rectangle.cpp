# include <algorithm>

using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
      // int area1 = (ax2-ax1) * (ay2-ay1);
      // int area2 = (bx2-bx1) * (by2-by1);

      int overlapX = 0;
      int overlapY = 0;

      if(bx1 < ax2 && bx2 > ax1){
        overlapX = min(ax2,bx2) - max(bx1,ax1);
      }

      if(by1 < ay2 && by2 > ay1){
        overlapY = min(ay2,by2) - max(by1,ay1);
      }

      return ((ax2-ax1) * (ay2-ay1)+ (bx2-bx1) * (by2-by1)) - (overlapX*overlapY);
    }
};