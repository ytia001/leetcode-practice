#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int res = 0;
      int min = INT_MAX;
      for(int i : prices){
        if(i<=min){
          min = i;
          continue;
        } 
        res = max(res,i-min);
        //if((i-min)>res) res = i-min;
      }
      return res;
    }
};