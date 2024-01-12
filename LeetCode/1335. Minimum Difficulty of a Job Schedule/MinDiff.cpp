# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedVect;
    //int curDiff;
    int n;

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();
        if(n < d) return -1;

        vector<int> temp = jobDifficulty;
        sort(temp.begin(),temp.end());
        sortedVect = temp;
        //int tempVal = temp.back();
        //curDiff = tempVal;

        return minDiff(0,d);
    }

    int minDiff(int i , int d){
      if(d == 1) return sortedVect[i];
      int res = INT_MAX;

      for(int j = i ; j < n - d ; j++){
        res = min(res,sortedVect[j] + minDiff(j+1,d-1));
      }

      return res;
    }
};