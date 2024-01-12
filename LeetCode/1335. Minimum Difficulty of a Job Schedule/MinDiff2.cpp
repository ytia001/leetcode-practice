# include <vector>
# include <algorithm>
# include <numeric>

using namespace std;

class Solution {
public:
    vector<int> sortedVect;
    vector<vector<int>> history;
    int n;

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();
        if(n < d) return -1;
        else if (n == d) return accumulate(jobDifficulty.begin(),jobDifficulty.end(),0);

        sortedVect = jobDifficulty;
        history = vector<vector<int>>(n+1,vector<int>(d+1,-1));

        return minDiff(0,d);
    }

    int minDiff(int i , int d){
      if(d == 1) return *max_element(sortedVect.begin()+i,sortedVect.end());
      if(sortedVect.size()-i == d) return accumulate(sortedVect.begin()+i,sortedVect.end(),0);
      if(history[i][d] != -1) return history[i][d];

      int res = INT_MAX;

      for(int j = i ; j < n - d + 1 ; j++){
        res = min(res,*max_element(sortedVect.begin()+i,sortedVect.begin()+j+1) + minDiff(j+1,d-1));
      }

      return history[i][d] = res;
    }
};