#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:

    int largestAltitude(vector<int>& gain) {
      int res = gain[0] > 0 ? gain[0] : 0 ; 
      for(int i = 1 ; i<gain.size() ; i++){
        res = max(res,gain[i] += gain[i-1]);
      }
      return res; 
    }

    int largestAltitude(vector<int>& gain) {
      int res = 0; 
      int cur = 0;
      for(int i = 0 ; i<gain.size() ; i++){
        cur += gain[i];
        res = max(res,cur);
      }
      return res;
    }
};