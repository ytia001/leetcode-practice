# include <vector>
# include <algorithm>

using namespace std;

bool comparator(const vector<int>& a , const vector<int>& b){
  return a[0] < b[0] ;
}

class Solution {
public:

    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
      int res = 0;
      sort(points.begin(),points.end(),comparator);
      for(int i = 1 ; i < points.size() ; i++ ){
        res = max(res, points[i][0]-points[i-1][0]);
      }
      return res;
    }
};