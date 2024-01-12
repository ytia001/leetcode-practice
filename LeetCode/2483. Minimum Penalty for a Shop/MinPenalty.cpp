#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int bestClosingTime(string customers) {
      int res;
      int minCount = INT_MAX;
      int size = customers.size();
      vector<vector<int>> count(size + 1,vector<int>{0,0}); 

      for(int i = 1 ; i <= size ; i++){
        count[i][0] = (customers[i-1] == 'N') ? count[i-1][0] + 1 : count[i-1][0];
      }

      for(int i = size - 1 ; i >= 0 ; i--){
        count[i][1] = (customers[i] == 'Y') ? count[i+1][1] + 1 : count[i+1][1];
      }

      for(int i = 0 ; i <= size ; i++){
        // cout<<"count[i][0]: "<<count[i][0]<<" count[i][1]: "<<count[i][1]<<endl;
        int currentCount = count[i][0]+count[i][1];
        if(currentCount < minCount){
          res = i;
          minCount = currentCount;
        }
      }

      return res;  

    }
};