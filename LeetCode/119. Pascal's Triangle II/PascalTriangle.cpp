#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
      if(rowIndex == 0) return {1};
      vector<int> res(2,1);
      
      for(int i = 2 ; i <= rowIndex ; i++){
        for(int j = res.size() - 1 ; j > 0 ; j--){
          res[j] += res[j-1];
        }
        res.push_back({1});
      }

      return res;
    }
};