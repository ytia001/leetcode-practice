#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int oddCount = 0 , evenCount = 0;
        for(int i : position){
          if(i%2){
            oddCount++;
          }else{
            evenCount++;
          }
        }

        if(oddCount==0 || evenCount==0){
          return 0;
        }else{
          return min(oddCount,evenCount);
        }

        //return min(oddCount,evenCount);
    }
};