# include <stack>
# include <vector>
# include <string>
# include <queue>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
      int total = neededTime[0];
      int maxTime = neededTime[0];
      int res = 0;
      int prevColor = 0;

      for(int i = 1 ; i < colors.size() ; i++){
        if(colors[i]!=colors[prevColor]){
          if(i-prevColor > 1){
            res += (total-maxTime);
          }
          prevColor = i;
          total = neededTime[i];
          maxTime = neededTime[i];
        }else{
          total += neededTime[i];
          maxTime = max(maxTime,neededTime[i]);
        }
      }

      if(colors.size() - prevColor > 1){
        res += (total-maxTime);
      }

      return res; 
    }
};