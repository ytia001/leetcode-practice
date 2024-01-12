# include <vector>

using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
      int count = 0; 
      int res = -1;
      for(int i = 0 ; i < arr.size() ; i++){
        if(count == 0) {
          res = arr[i];
          count = 1;
          continue;
        }

        if(res == arr[i]){
          count++;
        }else{
          count--;
        }
      }

      return res;
    }
};